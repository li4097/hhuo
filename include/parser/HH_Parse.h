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
#include "HH_ThRequest.h"
#include "HH_ThResponse.h"
#include "HH_WsRequest.h"
#include "HH_WsResponse.h"
#include "HH_TpRequest.h"
#include "HH_TpResponse.h"

namespace hhou
{
    /**
     * 连接的类型
     */
    enum LinkType
    {
        Http = 0, /// http
        Websocket, /// websocket
        Tcp /// 普通tcp
    };
    
    /**
     * 应用层的处理回调
	 * LinkType 协议类型
     * int 唯一标示
     * void *待处理包
     * void *相应包
     * */
    typedef function<int(LinkType, int, void *, void *)> DataDeal;

    /**
     * 解析数据的基础类
     */
    class HHParse
    {
    public:
        /**默认构造函数*/
        HHParse(int fd, DataDeal dataProc) : m_nFd(fd), m_pDataDeal(dataProc) {}
        virtual ~HHParse() {}

        /**先进行必要信息的解析*/
        bool ParseData(void *buf, int nLen);

        /**发送回调函数*/
        bool SendData(string &strRet, int nSize);

    private:
		int m_nFd;
        DataDeal m_pDataDeal;
    #ifdef HTTP
        hhou::HHThRequest m_req;  /// 请求包对象
        hhou::HHThResponse m_res; /// 回应包对象
	#elif WEBSOCKET
		hhou::HHWsRequest m_req; /// 请求包对象
        hhou::HHWsResponse m_res; /// 回应包对象
    #elif TCPCONN
        hhou::HHTpRequest m_req; /// 请求包对象
        hhou::HHTpResponse m_res; /// 回应包对象
    #endif

    };

    /**
     * 解析器的管理器
     */
    class HHParserMgr
    {
    public:
        /**默认构造函数*/
        HHParserMgr() {}
        virtual ~HHParserMgr() {}

        /**获取解析器，没有的话就给个新的*/
        shared_ptr<hhou::HHParse> GetParser(const int fd);
        bool RmParser(const int fd);

        /**设置回调*/
        void Callback(DataDeal dataProc) {m_pDataDeal = dataProc;}

        /**单例模式*/
        static HHParserMgr &Instance()
        {
            static HHParserMgr parserMgr;
            return parserMgr;
        }

    private:
        DataDeal m_pDataDeal;
        mutex m_mutex; /// 锁
        map<int, shared_ptr<hhou::HHParse>> m_mParsers;   /// fd对应的解析器
    };
}

#endif //HH_PARSE_H
