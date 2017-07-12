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

#ifndef HH_HTTPPARSE_H
#define HH_HTTPPARSE_H

#include <map>
#include "../net/HH_Common.h"

namespace hhou
{
    /**
     * http的url参数解析
     */
    class HHHttpParamParser
    {
    public:
        HHHttpParamParser() {}
        HHHttpParamParser(const char *buf, size_t nLen);
        virtual ~HHHttpParamParser() {}

    public:
        void Parse(const char *buf, size_t nLen);
        string GetParam(const string &strKey);

    private:
        map<string, string> m_mKV; /// 存放的map

    };

    /***/

    /**
     * http的解析类
     */
    class HHHttpParser
    {
    public:
        /**
         * 默认构造函数
         */
        HHHttpParser(const char *szHttpReq, size_t nDataLen, string &strOut);
        virtual ~HHHttpParser() {}

        /**
         * 解析函数(错误数据返回-1，数据不完整返回0，接收完全返回>0)
         */
        int Parse(const char *szHttpReq, size_t nDataLen, string &strOut);

        /**
         * 获取各个头域参数值
         */
        string GetHeadField(const string &strKey);

        /**
         * 获取cookie
         */
        string GetCookie();

        /**
         * 获取参数的值
         */
        string GetParam(const string &strKey);

        /**
         * 获取参数字符串
         */
        string GetParamString();

    private:
        /**
         * 解析头域
         */
        bool ParseField(const char *szHttpReq, size_t nLen);

        /**
         * 解析第一行，提取method和headparam
         */
        bool ParseFirstLine();

        /**
         * 解析method
         */
        bool ParseMethod(const char* szFirstLine, const char* szMethod, int nMethodType);

        /**
         * 安全校验
         */
        bool CheckSecurity(const char* szHttpReq);

        /**
         * 检测是否接受完全
         */
        bool GetLengthEx(const char *buf, size_t nLen, size_t &nContentPos, size_t &nContentSize);

    private:
        const char *m_pReqData; /// 保存req的data
        size_t m_nReqLen; /// req的长度
        HHHttpParamParser m_HttpParamParser; /// 参数解析器
        map<string, string> m_mFields; /// 头部的KV
        string m_strUrl; /// 请求的url
        string m_strMethod; /// 请求的method
        string m_strContent; /// 请求的content
        size_t m_nContentSize; /// content的size
    };
}

#endif // HH_HTTPPARSE_H