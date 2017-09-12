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
#ifndef HHUO_HH_WSRESPONSE_H
#define HHUO_HH_WSRESPONSE_H

#include <map>
#include <deque>
#include <vector>
#include <sstream>
#include "HH_Common.h"
#include "HH_Msg.h"
#include "HH_Log.h"

namespace hhou
{
    /**
     * websocket回应
     */
    class HHWsResponse
    {
        typedef map<string, string>::iterator ReqIter;
        typedef map<string, string>::const_iterator ReqCIter;
    public:
        /**
         * 构造函数
         */
        HHWsResponse();
        virtual ~HHWsResponse() {}
		
		/**
         * 添加头部信息
         */
        void AddHeader(const string &strKey, const string &strVal)
        {
            m_mHeaders.insert(make_pair(strKey, strVal));
        }
		
		/**
         * 生成websocket的函数(失败0，正确返回1)
         */
        int MakeRes();
		
		/**
         * websocket帧编码
         */
        bool WSEncodeFrame(const HHMsg &msg);
		
		/**
         * 获取处理完的数据
         */
        void GetResult(string &strRet, int nSize);

		/**
         * 重置
         */
        void Reset();

    private:
        map<string, string> m_mHeaders; /// 头部的键值对
		deque<shared_ptr<HHMsg>> m_SendMsg; /// 消息队列
		
    };
}

#endif //HHUO_HH_WEBSOCKET_H
