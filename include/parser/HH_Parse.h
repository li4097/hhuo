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
#ifndef HH_PARSE_H
#define HH_PARSE_H

#include "../HH_Common.h"

///////////////////////////////
/// 库和功能代码分开
typedef int (*CommitObject)(void *, int, void *);
bool SetCallBack(CommitObject obj);
///////////////////////////////

namespace hhou
{
    /**
     * 解析数据的基础类
     */
    class HHParse
    {
    public:
        /**默认构造函数*/
        HHParse() {}
        virtual ~HHParse() {}

        /**先进行必要信息的解析(错误数据返回-1，数据不完整返回0，接收完全返回>0)*/
        virtual int ParseData(const char *buf, int nLen, char *strRet);
    };
}

#endif //HH_PARSE_H