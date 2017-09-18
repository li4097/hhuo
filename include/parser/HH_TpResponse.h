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

#ifndef HHUO_HH_TPRESPONSE_H
#define HHUO_HH_TPRESPONSE_H

#include <map>
#include <deque>
#include <vector>
#include <sstream>
#include "../HH_Common.h"
#include "HH_Msg.h"
#include "../HH_Log.h"

namespace hhou
{
    /**
     * tcp回应
     */
    class HHTpResponse
    {
        typedef map<string, string>::iterator ReqIter;
        typedef map<string, string>::const_iterator ReqCIter;
    public:
        /**
         * 构造函数
         */
        HHTpResponse();
        virtual ~HHTpResponse() {}
		
		/**
         * 生成tcp的函数(失败0，正确返回1)
         */
        int MakeRes(const HHMsg &msg);
		
		/**
         * 获取处理完的数据
         */
        void GetResult(string &strRet, int nSize);

		/**
         * 重置
         */
        void Reset();

    private:
		deque<shared_ptr<HHMsg>> m_SendMsg; /// 消息队列
		
    };
}

#endif //HHUO_HH_TPRESPONSE_H