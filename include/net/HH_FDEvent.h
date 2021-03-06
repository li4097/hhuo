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

#ifndef HHUO_HHFDEVENT_H
#define HHUO_HHFDEVENT_H

#include "HH_EventBase.h"
#include "../HH_Common.h"
#include "../utils/HH_CircularBuffer.h"

namespace hhou
{
    /**net的loop对象*/
    class HHPoller;

    /**
    * HH_FDEvent是一个fd的封装类，封装了fd的处理
    * */
    class HHFDEvent : public HHEventBase
    {
        friend class HHPoller;

        /**
         * bool: 为false则关闭socket
         * bool : 是否需要keepalive
         * void * : 接受到的数据的指针
         * int : 上述数据的大小
         * */
        typedef function<bool(void *, int)> RecvProc;

        /**
		 * bool: 为false则关闭socket
         * string &: 处理完的数据
		 * int : 最大的数据长度
         * */
        typedef function<bool(string &, int)> SendProc;
		
		/**
         * 断开回调函数
         * */
        typedef function<void()> CloseProc;
		
    public:
        /**
         * 禁用的构造函数
         */
        HHFDEvent() = delete;

        /**
         * 默认只能引用构造
         */
        HHFDEvent(shared_ptr<HHPoller> poller, size_t bufSize = TCP_BUFSIZE);
        virtual ~HHFDEvent();

        /**
         * 重载读事件
         * */
        void OnRead();

        /**
         * 重载写事件
         * */
        void OnWrite();

        /**
         * 正在关闭的
         */
        void OnClosing();

        /**
         * 重载关闭事件
         * */
        void OnClosed();

        /**
         * 重载超时事件
         * */
        void OnTimeout();

        /**
         * 外部主动发送的接口
         * */
        bool SendData(const string &strData);

        /**
         * 设置客户端的ip和port
         */
        void SetIpAndPort(ipaddr_t ip, port_t port)
        {
            m_remoteAddr = ip;
            m_remotePort = port;
        }

        /**
         * 获取ip和端口
         */
        void GetIpAndPort(ipaddr_t &ip, port_t &port)
        {
            ip = m_remoteAddr;
            port = m_remotePort;
        }

        /**
         * 设置解析回调函数
         */
        void SetCallBack(RecvProc pRecvProc, SendProc pSendProc, CloseProc pCloseProc)
        {
            m_recvProc = pRecvProc;
			m_sendProc = pSendProc;
			m_closeProc = pCloseProc;
        }

    public:
        unsigned long m_nTotalRecv; /// 次socket接受的总字节数
        unsigned long m_nTotalSend; /// 次socket发送的总字节数

    private:
        shared_ptr<HHPoller> m_Poller; /// poller对象
        time_t m_tCreate; /// 创建时间
        int m_tTimeout; /// 超时时间（心跳机制，应用层进行管理）
        size_t m_count; /// 接收的字节数
        ipaddr_t m_remoteAddr; /// 对端的ip地址
        port_t m_remotePort; /// 对端的port端口
        HHCircularBuffer m_bufIn; /// 接受的data
        HHCircularBuffer m_bufOut; /// 发送的data
        RecvProc m_recvProc; ///解析层的回调函数
        SendProc m_sendProc; ///发送完数据的回调函数
		CloseProc m_closeProc; ///关闭socket的回调

    public:
#ifdef HAVE_OPENSSL
        SSL *m_sSSL; /// ssl对象
        bool m_bSSLConnected; /// ssl是否已经握手成功
#endif
    };
}
#endif //HHUO_HHFDEVENT_H
