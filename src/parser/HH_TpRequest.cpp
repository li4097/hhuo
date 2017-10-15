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

#include "../../include/parser/HH_TpRequest.h"

hhou::HHTpRequest::HHTpRequest()
    : m_bConntected(false)
{

}

int hhou::HHTpRequest::Parse(const char *buf, int nSize)
{
    int nPos = 0;
    if (nSize < 5) return TCP_ERROR;
    while (nSize > nPos)
    {
		/// 判断是否合法
        if ((buf[nPos] & 0x70) != 0x00) return TCP_ERROR;
		
		/// 判断是否完整
        int nCompleted = true;
        if ((buf[nPos] & 0x80) != 0x80) nCompleted = false;

        /// opCode
        int nType = (buf[nPos++] & 0x0f);
        if (nType == 8) return TCP_ERROR;
        if (nType != 1 && !m_bConntected)
        {
            LOG(ERROR) << "TcpConn do not connected ok first!";
            return TCP_ERROR;
        }

        /// msgID
        int nID;
        memcpy(&nID, buf + nPos, 4);
        nPos += 4;
        if (nSize <= nPos)
        {
		    LOG(INFO) << "op: " << nType << " nCompleted: " << nCompleted;
            return TCP_OK;
        }
        
		/// 解析body的长度
        int nContentLen = buf[nPos++] & 0xff;
        if (nContentLen == 253)
        {
			short length = 0;
			memcpy(&length, buf + nPos, 2);
            nPos += 2;
			nContentLen = ntohs(length);
        }
        else if (nContentLen == 254)
        {
			int length = 0;
			memcpy(&length, buf + nPos, 8);
            nPos += 8;        
			nContentLen = ntohl(length);
        }

		/// 解析body
		string strBody = string(buf, nPos, nContentLen);
		
		/// 进行数据填充
		if (m_ReadMsg.empty() || m_ReadMsg.front()->m_bCompleted)			
			m_ReadMsg.push_back(make_shared<HHMsg>(0, nType, nCompleted, strBody));
		else
		{
            m_ReadMsg.front()->m_nOp = nType;		
            m_ReadMsg.front()->m_nID = ntohl(nID);	
			m_ReadMsg.front()->m_bCompleted = nCompleted;	
			m_ReadMsg.front()->m_strMsg.append(strBody);		
		}
		LOG(INFO) << "op: " << nType << " nCompleted: " << nCompleted << " length: " << nContentLen;
	}
    return TCP_OK;
}
