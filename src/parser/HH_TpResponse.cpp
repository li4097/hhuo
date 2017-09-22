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

#include "../../include/parser/HH_TpResponse.h"
#include "../../include/utils/HH_Split.h"
#include "../../include/utils/HH_Base64.h"
#include "../../include/utils/HH_Sha1.h"

hhou::HHTpResponse::HHTpResponse()
{

}

void hhou::HHTpResponse::Reset()
{
    m_SendMsg.clear();
}

int hhou::HHTpResponse::MakeRes(const HHMsg &msg)
{
    ostringstream os;
    m_SendMsg.push_back(make_shared<HHMsg>(0, 0));
    int dataSize = msg.m_strMsg.length();
    os << static_cast<uint8_t>(0x80 | msg.m_nOp);
    os << static_cast<uint8_t>(msg.m_nID);
    if (dataSize <= 0xfd) 
    {
        os << static_cast<uint8_t>(dataSize);
    }
    else
    {
        os << 0xfe;
        short len = htons(dataSize); 
        os << len;
    }
    os << msg.m_strMsg;
    m_SendMsg.front()->m_strMsg = os.str();
	return 1; 
}

void hhou::HHTpResponse::GetResult(string &strRet, int nSize)
{
	if (m_SendMsg.size() <= 0) return;
	strRet.assign(m_SendMsg.front()->m_strMsg, 0, nSize);
	m_SendMsg.pop_front();
}