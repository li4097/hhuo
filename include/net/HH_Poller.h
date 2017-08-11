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

#ifndef HH_POLLER_H
#define HH_POLLER_H

#include <map>
#include <queue>
#include "utils/HH_OrderQueue.h"
#include "HH_EventBase.h"
#include "HH_Config.h"

namespace hhou
{
    /**poller最大事件数量*/
    #define Poller_MAX_EVENT 1024

    /**
     * epoll的操作类
     */
    class HHPoller
    {
        typedef multimap<time_t, HHEventBase *>::iterator multiMapItor;
    public:
        HHPoller();
        virtual ~HHPoller() {}

        /**
         * 添加监听对象
         */
        void AddEvent(HHEventBase *event);

        /**
         * 修改监听对象
         */
        void ChangeEvent(HHEventBase *event);

        /**
         * 删除监听对象
         */
        void DelEvent(HHEventBase *event);

        /**
         * 把epoll_wait事件添加到map
         */
        void ProcessEvents(int timeout, queue<HHEventBase *> &qEvents);

        /**
         * 更新连接数
         */
        void UpdateConnNums(int nNum);

    private:
        SOCKET m_epollFd; ///poller的fd
        struct epoll_event m_events[Poller_MAX_EVENT]; ///关注事件的最大数量
        int m_connectionNum; /// 连接的总数
        time_t m_nStart; /// 启动的开始时间
        HHOrderQueue<HHEventBase *> m_AllSockets; /// 所有的socket对象
        
    };
}

#endif //HH_POLLER_H