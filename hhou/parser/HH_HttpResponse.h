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

#ifndef HHUO_HH_HTTPRESPONSE_H
#define HHUO_HH_HTTPRESPONSE_H

#include <map>
#include <vector>
#include "../net/HH_Common.h"

namespace hhou
{
    #define HTTP_CONTENT_TYPE_TXT	"text/html;charset=utf-8"
    #define HTTP_CONTENT_TYPE_JSON	"application/json;charset=utf-8"
    #define HTTP_CONTENT_TYPE_XML	"text/xml;charset=utf-8"

    /**
     * http的response生成
     */
    class HH_HttpResponse
    {
        typedef map<string, string>::iterator ResIter;
        typedef map<string, string>::const_iterator ResCIter;
    public:
        /**
         * 构造函数
         */
        HH_HttpResponse() {};
        virtual ~HH_HttpResponse() {}

        /**
         * 生成的函数(失败0，正确返回1)
         */
        int MakeRes(char *strResp, const string &strContent, const char *strContentType = HTTP_CONTENT_TYPE_TXT);

    private:

    };
}

#endif //HHUO_HH_HTTPRESPONSE_H
