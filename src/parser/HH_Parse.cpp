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

#include "HH_Parse.h"

bool hhou::HHParse::ParseData(void *buf, int nLen)
{
#ifdef HTTP
    int nRet = (int)m_req.Parse((char *)buf, nLen);
	if (!nRet && m_pDataDeal(Http, (void *) &m_req, (void *) &m_res))
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
            return false;
    }
    else 
    {
        if (m_req.WSDecodeFrame((char *)buf, nLen))
        {
            while (!m_req.m_ReadMsg.empty())
            {
                auto iter = m_req.m_ReadMsg.front();
                HHMsg msg(0, 0);
                m_pDataDeal(Websocket, (void *) iter.get(), (void *) &msg);
                m_res.WSEncodeFrame(msg);
                m_req.m_ReadMsg.pop_front();
            }
        }
        else
        {
            return false;
        }
    }
#endif
	return true;
}

bool hhou::HHParse::SendData(string &strRet, int nSize)
{
    m_res.GetResult(strRet, nSize);
	return true;
}

hhou::HHParse *hhou::HHParserMgr::GetParser(const int fd)
{
    /// 先去空闲的里面找，没有则new
    HHParse *pParse;
    auto it = m_mParsers.find(fd);
    if (it != m_mParsers.end())
    {
        pParse = it->second;
    }
    else
    {
        lock_guard<mutex> lock(m_mutex);
        pParse = new hhou::HHParse(m_pDataDeal);
        m_mParsers.insert(make_pair(fd, pParse));
    }
    return pParse;
}

bool hhou::HHParserMgr::RmParser(const int fd)
{
    lock_guard<mutex> lock(m_mutex);
    auto it = m_mParsers.find(fd);
    if (it != m_mParsers.end())
    {
        delete it->second;
        it->second = NULL;
        m_mParsers.erase(it);
    }
    return true;
}
