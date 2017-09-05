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

#ifndef HH_SERVERBASE_H
#define HH_SERVERBASE_H

#include "HH_Common.h"
#include "parser/HH_Parse.h"

namespace hhou
{
    /**
     * server的基类
     * 后续添加新的服务继承自即可
     */
    class HHServerBase
    {
    public:
        HHServerBase()
        {
            HHParserMgr::Instance().AppCallback(bind(&HHServerBase::AppData, this, _1, _2, _3, _4));
            HHParserMgr::Instance().HttpCallback(bind(&HHServerBase::HttpData, this, _1, _2, _3));
        }
        virtual ~HHServerBase() {}

        /**app的注册回调*/
        virtual int AppData(int nOp, void *first, int nFisrtLen, string &second) { return 0; }
        virtual int HttpData(void *first, int nFisrtLen, void *second) { return 0; }

        /**初始化本服务（读取配置文件等等）*/
        virtual bool Init() { return true;}

        /**开始服务*/
        virtual void Run() {}
		
    };
}
#endif //HH_SERVERBASE_H