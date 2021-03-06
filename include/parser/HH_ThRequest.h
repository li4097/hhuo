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
#ifndef HHUO_HH_THREQUEST_H
#define HHUO_HH_THREQUEST_H

#include <map>
#include <queue>
#include <vector>
#include <sstream>
#include "../HH_Common.h"
#include "../HH_Log.h"

namespace hhou
{
    enum HttpMethodType
    {
        HTTP_METHOD_NONE,   /// 错误的请求
        HTTP_METHOD_GET,    /// get请求
        HTTP_METHOD_POST,   /// post请求
        HTTP_METHOD_RESP    /// response请求
    };

    enum HttpError
    {
        HTTP_OK = 0,            /// 无错误
        HTTP_HEAD_ERROR,        /// 头部错误（GET /getxxx HTTP1.x）
        HTTP_BODY_INCOMPLTED    /// 数据不完整
    };

    enum HttpParse
    {
        HTTP_NONE_DONE,    /// 还未进行解析
        HTTP_HEAD_DONE,    /// 头解析完成
        HTTP_BODY_DONE     /// body解析完成
    };

    /**
     * http的request解析
     */
    class HHThRequest
    {
        typedef map<string, string>::iterator ReqIter;
        typedef map<string, string>::const_iterator ReqCIter;
    public:
        /**
         * 构造函数
         */
        HHThRequest();
        virtual ~HHThRequest() {}

        /**
         * 解析的函数
         */
        hhou::HttpError Parse(const char *szHttpReq, int nDataLen);

        /**
         * 外部调用的获取接口
         */
        HttpMethodType &GetMethodType() { return m_nMethod;}
        string &GetMethod() { return m_strMethod;}
		string &GetContent() { return m_strContent;}
		void ClearContent() { m_strContent.clear();}
        void GetParam(const string &strKey, string &strVal);
        void GetFieldInt(const string &strKey, int &nVal);
        void GetFieldStr(const string &strKey, string &strVal);

    private:
        HttpMethodType m_nMethod; /// 请求类型
        string m_strMethod;  /// 方法名（以此作路由）
        string m_strContent; /// 消息的body
        map<string, string> m_mField; /// 存放域值
        map<string, string> m_mParam; /// 存放参数
        HttpParse m_nParseWhere;  /// 解析到哪里了

    };
}

#endif //HHUO_HH_THREQUEST_H
