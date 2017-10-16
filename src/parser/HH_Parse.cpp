/*
Copyright (C) 2004  loveyou12300liumao@163.com

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#include "../../include/parser/HH_Parse.h"

bool hhou::HHParse::ParseData(void *buf, int nLen)
{
#ifdef HTTP
    int nRet = (int)m_req.Parse((char *)buf, nLen);
	if (!nRet && m_pDataDeal(Http, m_nFd, (void *) &m_req, (void *) &m_res))
	{
		m_res.AddHeader("Connection", "Keep-Alive");
		m_res.MakeRes();
	}
    else
    {
        return false;
    }
#elif WEBSOCKET
	if (!m_req.WsStatus())
    {
        if (!m_req.Parse((char *)buf, nLen))
        {
            m_res.AddHeader("Connection", "Keep-Alive");
            m_res.AddHeader("Sec-WebSocket-Accept", m_req.GetServerKey());
            m_res.MakeRes();            
        }
        else
        {
            m_req.SetWsStatus(false);
            m_res.Reset();
            return false;
        }
    }
    else 
    {
        if (m_req.DecodeFrame((char *)buf, nLen))
        {
            while (!m_req.m_ReadMsg.empty())
            {
                auto iter = m_req.m_ReadMsg.front();
                HHMsg msg(0, 0);
                m_pDataDeal(Websocket, m_nFd, (void *) iter.get(), (void *) &msg);
                m_res.WSEncodeFrame(msg);
                m_req.m_ReadMsg.pop_front();
            }
        }
        else
        {
            m_req.SetWsStatus(false);
            m_res.Reset();
            return false;
        }
    }
#elif TCPCONN
    int nRet = (int)m_req.Parse((char *)buf, nLen);
    if (!nRet)
	{
		while (!m_req.m_ReadMsg.empty())
        {
            auto iter = m_req.m_ReadMsg.front();
            HHMsg msg(0, 0);
            if (m_pDataDeal(Tcp, m_nFd, (void *) iter.get(), (void *) &msg) && !m_req.Status())
			{
				m_req.SetStatus(true);
			}
			m_res.MakeRes(msg);
			m_req.m_ReadMsg.pop_front();
        }
	}
    else
    {
        return false;
    }
#endif
	return true;
}

bool hhou::HHParse::SendData(string &strRet, int nSize)
{
    m_res.GetResult(strRet, nSize);
	return true;
}

void hhou::HHParse::CloseConn()
{
    HHParserMgr::Instance().RmParser(m_nFd);
	m_pCloseConn(m_nFd);
}

shared_ptr<hhou::HHParse> hhou::HHParserMgr::GetParser(const int fd)
{
    /// 先去空闲的里面找，没有则new
    shared_ptr<hhou::HHParse> pParse;
    auto it = m_mParsers.find(fd);
    if (it != m_mParsers.end())
    {
        pParse = it->second;
    }
    else
    {
        lock_guard<mutex> lock(m_mutex);
        pParse = make_shared<HHParse>(fd, m_pDataDeal, m_pCloseConn);
        m_mParsers.insert(make_pair(fd, pParse));
    }
    return pParse;
}

shared_ptr<hhou::HHParse> hhou::HHParserMgr::GetExistParser(const int fd)
{
    /// 先去空闲的里面找，没有则new
    shared_ptr<hhou::HHParse> pParse;
    auto it = m_mParsers.find(fd);
    if (it != m_mParsers.end())
    {
        pParse = it->second;
    }
    return pParse;
}

bool hhou::HHParserMgr::RmParser(const int fd)
{
    lock_guard<mutex> lock(m_mutex);
    auto it = m_mParsers.find(fd);
    if (it != m_mParsers.end())
    {
        m_mParsers.erase(it);
    }
    return true;
}
