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

#ifndef HHUO_HH_RESPONSE_H
#define HHUO_HH_RESPONSE_H

#include <map>
#include <vector>
#include "HH_Common.h"
#include "HH_Log.h"

namespace hhou
{
    #define HTTP_CONTENT_TYPE_TXT	"text/html;charset=utf-8"
    #define HTTP_CONTENT_TYPE_JSON	"application/json;charset=utf-8"
    #define HTTP_CONTENT_TYPE_XML	"text/xml;charset=utf-8"

    /**
     * http的response生成
     */
    class HHResponse
    {
        typedef map<string, string>::iterator ResIter;
        typedef map<string, string>::const_iterator ResCIter;
    public:
        /**
         * 构造函数
         */
        HHResponse() {}
        virtual ~HHResponse() {}

        /**
         * websocket帧编码
         */
        bool WSEncodeFrame();

        /**
         * 生成的函数(失败0，正确返回1)
         */
        int MakeRes(string &strRes, const string &strResContentType = HTTP_CONTENT_TYPE_TXT);

        /**
         * 生成websocket的函数(失败0，正确返回1)
         */
        int MakeWBRes(string &strRes, const string &strResContentType = HTTP_CONTENT_TYPE_TXT);

        /**
         * 设置response
         */
        void SetContent(const string &strContent) { m_strContent = strContent; }

        /**
         * 添加头部信息
         */
        void AddHeader(const string &strKey, const string &strVal)
        {
            m_mHeaders.insert(make_pair(strKey, strVal));
        }

    private:
        string m_strContent; /// 回应包
        map<string, string> m_mHeaders; /// 头部的键值对

    };
}

#endif //HHUO_HH_RESPONSE_H
