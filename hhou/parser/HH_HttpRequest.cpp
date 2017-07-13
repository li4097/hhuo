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
#include "HH_HttpRequest.h"
#include "../utils/HH_Split.h"

hhou::HH_HttpRequest::HH_HttpRequest(HttpParamType paramType)
        : m_nParamType(paramType),
          m_nMethod(HTTP_METHOD_NONE),
          m_strMethod(""),
          m_strContent("")
{

}

int hhou::HH_HttpRequest::Parse(const char *szHttpReq, int nDataLen, string &strOut)
{
    /// 检测是否合法
    if (!CheckSecurity(szHttpReq, nDataLen))
        return -1;

    /// 解析第一行
    int nLen;
    if (!ParseFirstLine(szHttpReq, nLen))
        return -1;

    /// 解析域
    if (!ParseFields(szHttpReq + nLen + 2, nLen))
        return -1;

    /// 解析content（如果有的话）
    if (!ParseContent(szHttpReq + nLen + 4, nLen))
        return -1;
    return 1;
}

bool hhou::HH_HttpRequest::ParseFirstLine(const char *buf, int &nLen)
{
    string strAll = string(buf);
    int pos = strAll.find("\r\n");
    string strLine = strAll.substr(0, pos);   /// 获取到第一行数据
    if(strLine.size() < 10)		/// 第一行不能小于10个字符
        return false;
    if ((int)strLine.find_last_of(" HTTP") == -1)  /// 不管get还是post都应该包含“HTPP字符串”
        return false;
    /// 获取method方法
    if ((int) strLine.find("GET") == 0)
    {
        m_nMethod = HTTP_METHOD_GET;
        if (!ParseParam(buf + 4))  /// 优先解析“Get”方法的
            return false;
    }
    else if ((int) strLine.find("POST") == 0)
        m_nMethod = HTTP_METHOD_POST;
    nLen += pos;
    return true;
}

bool hhou::HH_HttpRequest::ParseParam(const char *buf)
{
    string strParam = string(buf);
    vector<string> vMethod;
    SplitString(strParam, vMethod, "?");
    if (!vMethod.size())  /// 没带参数
    {
        int pos = strParam.find(" ");
        if (pos != -1)
            m_strMethod = strParam.substr(0, pos);
        return true;
    }
    m_strMethod = vMethod[0]; /// 保存请求方法字符串
    vector<string> vParam;
    if (vMethod.size() < 2)
        return true;
    SplitString(vMethod[1], vParam, "&");
    for (vector<string>::iterator it = vParam.begin(); it != vParam.end(); it++)
    {
        SplitKV(*it, m_mParam, "=");
    }
    return true;
}

bool hhou::HH_HttpRequest::ParseFields(const char *buf, int &nLen)
{
    string strAll = string(buf);
    int pos = strAll.find("\r\n\r\n");
    if (pos == -1)
        pos = strAll.size();
    string strField = strAll.substr(0, pos);  /// 所有的field的字符串
    vector<string> vField;
    SplitString(strField, vField, "\r\n");
    for (vector<string>::iterator it = vField.begin(); it != vField.end(); it++)
    {
        SplitKV(*it, m_mField, ":");
    }
    nLen += pos + 4;
    return true;
}

bool hhou::HH_HttpRequest::ParseContent(const char *buf, int &nLen)
{
    m_strContent = string(buf + nLen);
    return true;
}