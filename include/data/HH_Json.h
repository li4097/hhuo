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

#ifndef HH_JSON_H
#define HH_JSON_H

#include <vector>
#include <map>
#include <json/json.h>
#include "HH_Common.h"

namespace hhou
{
    /**
     * 封装json的数据处理
     */
    class HHJson
    {
    public:
        /**
         * 获取某个可以是否在json中
         */
        bool ExistK(const string &strContent, const string &strK);

        /**
         * Read函数
         */
        bool Read(vector<map<string, string> > &vKV, const string &strContent);

        /**
         * Write函数
         */
        bool Write(vector<map<string, string> > &vContent, string &strRet);
    };
}

#endif // HH_JSON_H