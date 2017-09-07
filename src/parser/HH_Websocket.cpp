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
		  m_strResult("")
{

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
    m_strResult = os.str();
    return 1;
}

int hhou::HHWebsocket::WSParse(const char *szHttpReq, int nDataLen)
{
    if (m_nStatus == Connected) return Connected;
	
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
    char shaHash[128];
    memset(shaHash, 0, sizeof(shaHash));
    hhou::Sha1(strMagicKey.c_str(), shaHash);
    string strMKey = hhou::Base64Encode((const unsigned char *)shaHash, strlen(shaHash));
    m_nStatus = Connected;
	AddHeader("Sec-WebSocket-Accept", strMKey);
    LOG(INFO) << "Sec Key:: " << strMKey;
	return Connected;
}