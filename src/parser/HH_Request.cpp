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

#include "HH_Request.h"
#include "HH_Config.h"
#include "utils/HH_Split.h"
#include "utils/HH_Base64.h"
#include "utils/HH_Sha1.h"

hhou::HHRequest::HHRequest(HttpParamType paramType)
        : m_nParamType(paramType),
          m_nMethod(HTTP_METHOD_NONE),
          m_strMethod(""),
          m_strContent(""),
          m_nParseWhere(HTTP_NONE_DONE),
          m_nWSStatus(WS_STATUS_UNCONNECT),
          m_nMsgType(0)
{

}

void hhou::HHRequest::GetParam(const string &strKey, string &strVal)
{
    auto it = m_mParam.find(strKey);
    if (it != m_mParam.end())
        strVal = it->second;
}

void hhou::HHRequest::GetFieldInt(const string &strKey, int &nVal)
{
    auto it = m_mField.find(strKey);
    if (it != m_mField.end())
    {
        nVal = atoi(it->second.c_str());
    }
}

void hhou::HHRequest::GetFieldStr(const string &strKey, string &strVal)
{
    auto it = m_mField.find(strKey);
    if (it != m_mField.end())
    {
        strVal = it->second;
    }
}

int hhou::HHRequest::WSHandShake()
{
    if (m_nWSStatus == WS_STATUS_CONNECT)
    {
        return 2;
    }
    string strKey;
    GetFieldStr("sec-websocket-key", strKey);
    if (strKey.empty())
    {
        return -1;
    }
    LOG(INFO) << "Client Key::" << strKey;
    string strMagicKey = hhou::HHConfig::Instance().ReadStr("websocket", "magickey", "");
    if (strMagicKey.empty())
    {
        LOG(ERROR) << "No magickey";
        return -1;
    }
    strMagicKey = strKey + strMagicKey;
    char shaHash[32];
    memset(shaHash, 0, sizeof(shaHash));
    hhou::Sha1(strMagicKey.c_str(), shaHash);
    m_strMagicKey = hhou::Base64Encode((const unsigned char *)shaHash, strlen(shaHash));
    m_nWSStatus = WS_STATUS_CONNECT;
    LOG(INFO) << "Sec Key:: " << m_strMagicKey;
    return 1;
}

bool hhou::HHRequest::WSDecodeFrame(const char *buf, int nSize)
{
    /// pos 
    int nPos = 0;
    while (nSize > nPos)
    {
        if ((nSize - nPos) < 2)
        {
            return false;
        }

        /// 检查扩展位并忽略
        if ((buf[nPos] & 0x70) != 0x00)
        {
            return false;
        }

        /// 检查fin标志
        if ((buf[nPos] & 0x80) != 0x80)
        {
            m_nParseWhere = HTTP_HEAD_DONE;
        }

        /// 获取消息类型
        m_nMsgType = (buf[nPos] & 0x0f);
        nPos++;

        /// client发来的数据必须包含mask位
        if ((buf[nPos] & 0x80) != 0x80)
        {
            return false;
        }

        /// 获取消息体的长度
        int nContentLen = buf[nPos] & 0x7f;
        if (nContentLen == 126)
        {
            /// 将接下来的2个字节转化为long
            nPos += 2;
        }
        else if (nContentLen == 127)
        {
            /// 将接下来的8个字节转化为long
            nPos += 8;        
        }
    }
    m_nParseWhere = HTTP_BODY_DONE;
    return true;
}

hhou::HttpError hhou::HHRequest::Parse(const char *szHttpReq, int nDataLen)
{
    /// 判断是否已经建立了websocket
    if (m_nWSStatus == WS_STATUS_CONNECT)
    {
        WSDecodeFrame(szHttpReq, nDataLen);
        return HTTP_OK;
    }

    /// 判断body是否完整
    int nSize = 0;
    GetFieldInt("content-length", nSize);
    if (m_nParseWhere == HTTP_HEAD_DONE)
    {
        /// 判断是否接受完全
        if (nSize > (int)m_strContent.str().size())
            m_strContent << string(szHttpReq, 0, nDataLen);
        else
            m_nParseWhere = HTTP_BODY_DONE;
        return HTTP_OK;
    }

    /// 读取request的对象
    istringstream in(szHttpReq);
    string strLine;
    getline(in, strLine);

    /**********************判断是否合法****************/
    if (strLine.size() < 10) /// 第一行不能小于10个字符
        return HTTP_HEAD_ERROR;
    vector<string> vLine;
    SplitString(strLine, vLine, " ");
    if (vLine.size() < 3)  /// 第一行肯定是三块元素
        return HTTP_HEAD_ERROR;

    /**********************解析第一行****************/
    if (vLine[0] == "GET")
        m_nMethod = HTTP_METHOD_GET;
    else if (vLine[0] == "POST")
        m_nMethod = HTTP_METHOD_POST;

    /// 参数?xxx=111&yyy=222
    vector<string> vMethod;
    SplitString(vLine[1], vMethod, "?");
    if (vMethod.size() < 2)
    {
        m_strMethod = vLine[1];
    }
    else
    {
        m_strMethod = vMethod[0]; /// 保存请求方法字符串
        vector<string> vParam;
        SplitString(vMethod[1], vParam, "&");
        for (auto it = vParam.begin(); it != vParam.end(); it++)
        {
            SplitKV(*it, m_mParam, "=");
        }
    }

    /**********************解析域****************/
    while (getline(in, strLine) && strLine != "\r")
    {
        strLine.erase(strLine.end() - 1);
        SplitKV(strLine, m_mField, ":");
    }

    /**********************解析content（如果有的话）****************/
    string strBody;
    in >> strBody;
    m_strContent << strBody;

    /// 判断是否接受完全
    GetFieldInt("content-length", nSize);
    if (nSize <= (int)m_strContent.str().size())
    {
        m_nParseWhere = HTTP_BODY_DONE;
    }
    return HTTP_OK;
}
