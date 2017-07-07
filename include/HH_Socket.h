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

#ifndef HHUO_HH_SOCKET_H
#define HHUO_HH_SOCKET_H

#include <string>
#include <vector>
#include <list>

#include "HH_Common.h"
#include <time.h>

namespace hhou
{
    /*net的loop对象*/
    class HHPoller;

    /*
    * HH_Socket是一个socket的封装类，封装了socket的处理
    * */
    class HHSocket
    {
        friend class HHPoller;
    public:
        /*
         * 禁掉默认构造函数
         * */
        HHSocket() = delete;

        /*
         * 默认只能引用构造
         * */
        HHSocket(HHPoller&);
        virtual ~HHSocket();

        /*
         * 创建socket对象的接口
         * 具体的实现在各自的继承类中
         * */
        virtual HHSocket *Create();

        /*
         * 初始化socket的各种配置参数
         * */
        virtual void Init();

        /*
         * 关闭socket对象的接口
         * */
        virtual int Close();

        /*
         * socket的fd操作接口
         * */
        inline void Attach(SOCKET fd) { m_socket = fd; }
        SOCKET GetSocket() { return m_socket; }

    protected:
        /*
         * 允许子类和友元访问的构造函数
         * */
        HHSocket(const HHSocket&);
        HHSocket& operator=(const HHSocket&);

    private:
        SocketInitializer m_socketInit; // socket初始化
        SOCKET m_socket; // socket句柄
        HHPoller m_poller; // poller对象
        time_t m_tLast; // 上次的活动时间
        time_t m_tCreate; // 创建时间
        int m_tTimeout; // 超时时间（心跳机制，应用层进行管理）
        size_t m_count; // 接收的字节数
        ipaddr_t m_remoteAddr; // 对端的ip地址
        port_t m_remoteAddr; // 对端的port端口

        /*
         * string m_strUserID; // 用户ID（自定义的保留）
         */
    };
}
#endif //HHUO_HH_SOCKET_H