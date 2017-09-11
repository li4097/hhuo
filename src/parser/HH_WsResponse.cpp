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

#include "HH_WsResponse.h"
#include "HH_Config.h"
#include "utils/HH_Split.h"
#include "utils/HH_Base64.h"
#include "utils/HH_Sha1.h"

hhou::HHWsResponse::HHWsResponse()
{
	/// 提前准备一个回应包
	m_SendMsg.push_back(make_shared<HHMsg>(GetMsgID(), 0, ""));
}

int hhou::HHWsResponse::MakeRes()
{
    ostringstream os;
    os << "HTTP/1.1 101 Switching Protocols" 
       << "\r\nConnection: Upgrade\r\nUpgrade: websocket\r\n";
    for (auto it = m_mHeaders.begin(); it != m_mHeaders.end(); it++)
    {
        os << it->first << ": " << it->second << "\r\n";
    }
    os << "\r\n";
	m_SendMsg.front()->m_strMsg = os.str();
    return 1;
}

void hhou::HHWsResponse::GetResult(string &strRet, int nSize)
{
	if (m_SendMsg.size() <= 0) return;
	strRet.assign(m_SendMsg.front()->m_strMsg, 0, nSize);
	m_SendMsg.pop_front();
}

bool hhou::HHWsResponse::WSEncodeFrame(const string &strRet)
{
	return true;
}