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

#ifndef HHUO_HH_TPREQUEST_H
#define HHUO_HH_TPREQUEST_H

#include <map>
#include <deque>
#include <vector>
#include <sstream>
#include "../HH_Common.h"
#include "../HH_Log.h"
#include "HH_Msg.h"

namespace hhou
{
    /**
	 * websocket请求
	 */
	enum TCP_STATUS
	{
        TCP_OK = 0,   /// 接收完整 
        TCP_ERROR    /// 数据出错
    };
    
    /**
     * tcpconnection的处理类
     * 0                   1                   2                   3
     *  0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
     * +-+-+-+-+-------+-------------------------------------------+
     * |F|R|R|R| opcode	   |   							               |
     * |I|S|S|S|  (4)      |                       	        	       |
     * |N|V|V|V|           |       		ID(32)      		           |
     * | |1|2|3|           |                                           |
     * +-+-+-+-+-------+---------------+ - - - - - - - - - - - - - - - +
     * | 			   | 			   |	Extended payload length    |
     * |ID(continue)   |Payload len(8) |		 (16/64)	   	       |
     * |			   |			   |	(if payload len==253/254)  |
     * +---------------+---------------+ - - - - - - - - - - - - - - - +
     * |     Extended payload length continued, if payload len == 254  |
     * + - - - - - - - - - - - - - - - +-------------------------------+
     * |           					   |		Payload Data 		   |
     * +-------------------------------+ - - - - - - - - - - - - - - - +
     * :                     Payload Data continued ...                :
     * + - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - +
     * |                     Payload Data continued ...                |
     * +---------------------------------------------------------------+
     * FIN：包是否结束
     * RSV：为保留位
     * opcode：操作码(0,15保留，1：connect，2：chat，3：ping，4：close,5....diy)
	 * ID: 消息的ID号（服务端需带回）
	 * Payload len：包体的内容长度
     */
    class HHTpRequest
    {
        friend class HHParse;
        typedef map<string, string>::iterator ReqIter;
        typedef map<string, string>::const_iterator ReqCIter;
    public:
        /**
         * 构造函数
         */
        HHTpRequest();
        virtual ~HHTpRequest() {}
		
		/**
         * 解析
         */
        int Parse(const char *szHttpReq, int nDataLen);

        /**
         * 建立状态
         */
        bool Status() {return m_bConntected;}
         
        /**
        * 设置状态
        */
        void SetStatus(bool bStatus) {m_bConntected = bStatus;}
		
    private:
		bool m_bConntected;	/// tcp的状态
        deque<shared_ptr<HHMsg>> m_ReadMsg; /// 消息队列
		
    };
}

#endif //HHUO_HH_TPREQUEST_H
