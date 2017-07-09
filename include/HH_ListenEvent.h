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

namespace hhou
{
    /**
     * 监听对象
     */
    class HHListenEvent : public HHEventBase
    {
    public:
        HHListenEvent() = delete;
        HHListenEvent(HHPoller *poller, const string &addr, const port_t &port);

        /**
         * 初始化loop对象
         */
        SOCKET Init();

        /**
         * 连接的处理
         */
        void OnConneting();

    private:
        HHPoller *m_pPoller; /// poller对象
        size_t m_connectionNum; /// 连接的总数
        string m_strAddr; /// ip地址
        port_t m_port; /// 端口
    };
}
#endif // HHUO_HHFDEVENT_H