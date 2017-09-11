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
#ifndef HHUO_HH_WSREQUEST_H
#define HHUO_HH_WSREQUEST_H

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
	 * websocket请求
	 */
	enum WS_STATUS
	{
		Error = 0,   /// 需要关闭socket
		UnConnected, /// 还未建立
		Connected, /// 已经建立
		Chat	/// 开始正常的收发信息
	};
	
    /**
     * websocket的处理类
     */
    class HHWsRequest
    {
        typedef map<string, string>::iterator ReqIter;
        typedef map<string, string>::const_iterator ReqCIter;
    public:
        /**
         * 构造函数
         */
        HHWsRequest();
        virtual ~HHWsRequest() {}
		
		/**
         * websocket握手
         */
        int Parse(const char *szHttpReq, int nDataLen);
		
		/**
         * websocket帧解码
         */
        bool WSDecodeFrame(const char *buf, int nSize);

        /** 
         * 获取serverkey
         */
        char *GetServerKey() {return m_cServerKey;}
		
    private:
		WS_STATUS m_nStatus;	/// ws的状态
        char m_cServerKey[128];  /// 服务器的key
        shared_ptr<HHMsg> m_ReadMsg; /// 处理的对象
		
    };
}

#endif //HHUO_HH_WSREQUEST_H
