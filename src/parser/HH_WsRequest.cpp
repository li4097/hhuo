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

#include "HH_WsRequest.h"
#include "HH_Config.h"
#include "utils/HH_Split.h"
#include "utils/HH_Base64.h"
#include "utils/HH_Sha1.h"

hhou::HHWsRequest::HHWsRequest()
        : m_bConntected(false)
{
	
}

bool hhou::HHWsRequest::WSDecodeFrame(const char *buf, int nSize)
{
    int nPos = 0;
    if ((nSize - nPos) < 2) return false;
    while (nSize > nPos)
    {
		/// 判断是否合法
        if ((buf[nPos] & 0x70) != 0x00) return false;
		
		/// 判断是否完整
        int nCompleted = true;
        if ((buf[nPos] & 0x80) != 0x80) nCompleted = false;
        int nType = (buf[nPos++] & 0x0f);
		
		/// 必须要有mask
        if ((buf[nPos] & 0x80) != 0x80) return false;
		
		/// 解析body的长度
        int nContentLen = buf[nPos++] & 0x7f;
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
			memcpy(&length, buf + nPos, 8);
            nPos += 8;        
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
		if (!m_ReadMsg.empty() && !m_ReadMsg.front()->m_bCompleted)
			m_ReadMsg.front()->m_strMsg.append(body);
		else
			m_ReadMsg.push_back(make_shared<HHMsg>(0, 0, ""));	
		m_ReadMsg.front()->m_nOp = nType;		
		m_ReadMsg.front()->m_bCompleted = nCompleted;
		LOG(INFO) << "op: " << nType << " nCompleted: " << nCompleted << " length: " << nContentLen;
	}
	return true;
}

int hhou::HHWsRequest::Parse(const char *szHttpReq, int nDataLen)
{
	/// 读取request的对象
    string strBody;
    istringstream in(szHttpReq);
	
	/**********************判断是否合法****************/
    string strLine;
    getline(in, strLine);
    if (strLine.size() < 10) /// 第一行不能小于10个字符
        return WS_HEAD_ERROR;
    vector<string> vLine;
    SplitString(strLine, vLine, " ");
    if (vLine.size() < 3)  /// 第一行肯定是三块元素
        return WS_HEAD_ERROR;
		
	/**********************解析第一行****************/
    if (vLine[0] != "GET")
        return WS_HEAD_ERROR;
	
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
		return WS_HEAD_ERROR;
	}
	string strKey = iter->second;
    LOG(INFO) << "Client Key::" << strKey;
    string strMagicKey = hhou::HHConfig::Instance().ReadStr("websocket", "magickey", "258EAFA5-E914-47DA-95CA-C5AB0DC85B11");
    if (strMagicKey.empty())
    {
        LOG(ERROR) << "No magickey";
        return WS_HEAD_ERROR;
    }
    strMagicKey = strKey + strMagicKey;
	char shaHash[128] = {0};
    hhou::Sha1(strMagicKey, shaHash);
	hhou::Base64Encode(shaHash, strlen(shaHash), m_cServerKey);	
    m_bConntected = true;
    LOG(INFO) << "Sec Key:: " << m_cServerKey;
	return WS_OK;
}