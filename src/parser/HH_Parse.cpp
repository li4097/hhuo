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

bool hhou::HHParse::ParseData(bool bOnce, void *buf, int nLen)
{
	LOG(INFO) << "client request: \n" << (char *)buf;
#ifdef HTTP
	int nRet = (int)request.Parse((char *)buf, nLen);
	if (!nRet && m_pDataDeal(Http, (void *) &request, nLen, (void *) &response))
	{
		bOnce ? response.AddHeader("Connection", "Close") : response.AddHeader("Connection", "Keep-Alive");
		response.MakeRes();
	}
#elif WEBSOCKET
	int nRet = (int)websocket.WSParse((char *)buf, nLen);
	if (nRet == 2)
	{
		websocket.MakeWBRes();
	}
	else if (!nRet)
	{
		return false;
	}
#endif
	return true;
}

bool hhou::HHParse::SendData(string &strRet, int nSize)
{
#ifdef HTTP
    response.GetResult(strRet, nSize);
#elif WEBSOCKET
	websocket.GetResult(strRet, nSize);
#endif
	LOG(INFO) << "send to client: \n" << strRet;
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
    auto it = m_mParsers.find(fd);
    if (it != m_mParsers.end())
    {
        delete it->second;
        it->second = NULL;
        m_mParsers.erase(it);
    }
    return true;
}
