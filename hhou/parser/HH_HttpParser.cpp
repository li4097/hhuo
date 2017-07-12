#include "HH_HttpParser.h"
#include "../utils/HH_Split.h"

hhou::HHHttpParamParser::HHHttpParamParser(const char *buf, size_t nLen)
{
    if (buf && nLen > 0)
        Parse(buf, nLen);
}

void hhou::HHHttpParamParser::Parse(const char *buf, size_t nLen)
{
    size_t nPos = 0;
    while(true)  /// 过滤掉没用的字符
    {
        if (buf[nPos] == '\0')
            break;
        if (!((buf[nPos] >= 'a' && buf[nPos] <= 'z') ||
              (buf[nPos] >= 'A' && buf[nPos] <= 'Z') ||
              buf[nPos] == '%' || buf[nPos] == '+'))
        {
            nPos++;
            continue;
        }
        else
            break;
    }

    /// 开始处理正确的数据
    string strData = string(buf + nPos);
    vector<string> vStr;
    SplitString(strData, vStr, "&");
    for (vector<string>::iterator it = vStr.begin(); it != vStr.end(); it++)
    {
        SplitKV(*it, m_mKV, "=");
    }
}

string hhou::HHHttpParamParser::GetParam(const string &strKey)
{
    string strRet;
    map<string, string>::iterator it = m_mKV.find(strKey);
    if (it != m_mKV.end())
        strRet = it->second;
    return strRet;
}

hhou::HHHttpParser::HHHttpParser(const char *szHttpReq, size_t nDataLen, string &strOut)
        : m_pReqData(szHttpReq),
          m_nReqLen(nDataLen)
{
    if (szHttpReq && m_nReqLen > 0)
        Parse(m_pReqData, m_nReqLen, strOut);
}

int hhou::HHHttpParser::Parse(const char *buf, size_t nLen, string &strOut)
{
    size_t nContentPos;

    /// 检测是否安全
    if (!CheckSecurity(buf))
        return -1;

    /// 检测是否接受完全
    int nTotalLen = GetLengthEx(buf, nLen, nContentPos, m_nContentSize);
    if (nTotalLen <= 0)
        return nTotalLen;

    /// 分离头域字段
    if (!ParseField(buf, nTotalLen))
        return -1;

    /// 分析第一行信息
    if (!ParseFirstLine())
        return -1;

    ///
    return 1;
}