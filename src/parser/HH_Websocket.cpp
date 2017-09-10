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

#include "HH_Websocket.h"
#include "HH_Config.h"
#include "utils/HH_Split.h"
#include "utils/HH_Base64.h"
#include "utils/HH_Sha1.h"

hhou::HHWebsocket::HHWebsocket()
        : m_nStatus(UnConnected),
		m_ReadMsg(make_shared<HHMsg>(0, 0, ""))
{
	/// 提前准备一个回应包
	m_SendMsg.push_back(make_shared<HHMsg>(GetMsgID(), 0, ""));
}

int hhou::HHWebsocket::MakeWBRes()
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

void hhou::HHWebsocket::GetResult(string &strRet, int nSize)
{
	if (m_SendMsg.size() <= 0) return;
	strRet.assign(m_SendMsg.front()->m_strMsg, 0, nSize);
	m_SendMsg.pop_front();
}

bool hhou::HHWebsocket::WSEncodeFrame(const string &strRet)
{
	return true;
}

bool hhou::HHWebsocket::WSDecodeFrame(const char *buf, int nSize)
{
    int nPos = 0;
    while (nSize > nPos)
    {
		/// 判断是否合法
        if ((nSize - nPos) < 2) return false;
        if ((buf[nPos] & 0x70) != 0x00) return false;
		
		/// 判断是否完整
        int nCompleted = true;
        if ((buf[nPos] & 0x80) != 0x80) nCompleted = false;
        int nType = (buf[nPos++] & 0x0f);
		
		/// 必须要有mask
        if ((buf[nPos] & 0x80) != 0x80) return false;
		
		/// 解析body的长度
        int nContentLen = buf[nPos] & 0x7f;
        if (nContentLen == 126)
        {
			short length = 0;
			memcpy(&length, buf + nPos, 2);
            nPos += 2;
			nContentLen = ntohs(length);
        }
        else if (nContentLen == 127)
        {
			int length = 0;
			memcpy(&length, buf + nPos, 4);
            nPos += 4;        
			nContentLen = ntohl(length);
        }
		
		/// 获取mask
		char mask[4] = {0};
		for(int i = 0; i < 4; i++) mask[i] = buf[nPos + i];
		nPos += 4;
		
		/// 解析body		
		char body[nContentLen + 1] = {0};
		for(int i = 0; i < nContentLen; i++)
		{
            int j = i % 4;
            body[i] = (buf[nPos + i] ^ mask[j]);
        }
		nPos += nContentLen;
		
		/// 进行数据填充
		m_ReadMsg->m_nOp = nType;
		m_ReadMsg->Append(body);
		LOG(INFO) << "op: " << nType << " nCompleted: " << nCompleted << " length: " << nContentLen;
		
		/// 判断完整，完整则需要提前准备一个空的msg
		if (nCompleted)
		{
			LOG(INFO) << "Msg: " << m_ReadMsg->m_strMsg << " size: " << m_ReadMsg->m_strMsg.length();
			m_ReadMsg->m_bCompleted = nCompleted;
		}
	}
	return true;
}

int hhou::HHWebsocket::WSParse(const char *szHttpReq, int nDataLen)
{
    if (m_nStatus == Connected)
	{
		WSDecodeFrame(szHttpReq, nDataLen);
		return Chat;
	}
	
	/// 读取request的对象
    string strBody;
    istringstream in(szHttpReq);
	
	/**********************判断是否合法****************/
    string strLine;
    getline(in, strLine);
    if (strLine.size() < 10) /// 第一行不能小于10个字符
        return Error;
    vector<string> vLine;
    SplitString(strLine, vLine, " ");
    if (vLine.size() < 3)  /// 第一行肯定是三块元素
        return Error;
		
	/**********************解析第一行****************/
    if (vLine[0] != "GET")
        return Error;
	
	/**********************解析域****************/
	map<string, string> mField;
    while (getline(in, strLine) && strLine != "\r")
    {
        strLine.erase(strLine.end() - 1);
        SplitKV(strLine, mField, ":");
    }
	
	/**********************搜索sec-key****************/
	auto iter = mField.find("sec-websocket-key");
	if (iter == mField.end())
	{
		LOG(ERROR) << "No seckey";
		return Error;
	}
	string strKey = iter->second;
    LOG(INFO) << "Client Key::" << strKey;
    string strMagicKey = hhou::HHConfig::Instance().ReadStr("websocket", "magickey", "258EAFA5-E914-47DA-95CA-C5AB0DC85B11");
    if (strMagicKey.empty())
    {
        LOG(ERROR) << "No magickey";
        return Error;
    }
    strMagicKey = strKey + strMagicKey;
	char shaHash[128] = {0};
    hhou::Sha1(strMagicKey, shaHash);
	
	char base64[128] = {0};
	string strBase = string(shaHash);
	hhou::Base64Encode(strBase, base64);	
    m_nStatus = Connected;
	AddHeader("Sec-WebSocket-Accept", base64);
    LOG(INFO) << "Sec Key:: " << base64;
	return Connected;
}