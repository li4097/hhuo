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
#ifndef HHUO_HH_HTTPREQUEST_H
#define HHUO_HH_HTTPREQUEST_H

#include <map>
#include <vector>
#include "../net/HH_Common.h"

namespace hhou
{
    enum HttpMethodType
    {
        HTTP_METHOD_NONE,  /// 错误的请求
        HTTP_METHOD_GET,  /// get请求
        HTTP_METHOD_POST,  /// post请求
        HTTP_METHOD_RESP  /// response请求
    };

    enum HttpParamType
    {
        HTTP_PARAM_ALL,            /// 所有类型的参数
        HTTP_PARAM_HEADPARAM,        /// 只获取HEADPARAM
        HTTP_PARAM_CONTENT            /// 只获取CONTENT
    };

    /**
     * http的request解析
     */
    class HH_HttpRequest
    {
    public:
        /**
         * 构造函数
         */
        HH_HttpRequest(HttpParamType paramType = HTTP_PARAM_ALL);
        virtual ~HH_HttpRequest() {}

        /**
         * 解析的函数(错误数据返回-1，数据不完整返回0，接收完全返回>0)
         */
        int Parse(const char *szHttpReq, int nDataLen, string &strOut);

    private:
        /**解析第一行参数*/
        bool ParseFirstLine(const char *buf, int &nLen);

        /**解析请求参数*/
        bool ParseParam(const char *buf);

        /**解析域的键值对*/
        bool ParseFields(const char *buf, int &nLen);

        /**解析content内容*/
        bool ParseContent(const char *buf, int &nLen);

        /**检测是否合法*/
        bool CheckSecurity(const char *buf, int nLen) { return true; }

    private:
        HttpParamType m_nParamType; /// 需要解析的参数
        HttpMethodType m_nMethod; /// 请求类型
        string m_strMethod;  /// 方法名（以此作路由）
        string m_strContent;  /// content
        map<string, string> m_mField; /// 存放域值
        map<string, string> m_mParam; /// 存放参数

    };
}

#endif //HHUO_HH_HTTPREQUEST_H
