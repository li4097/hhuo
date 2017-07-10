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

#ifndef HH_EVENTBASE_H
#define HH_EVENTBASE_H

#include "HH_Common.h"

namespace hhou
{
    /**
     * epoll反应堆的事件虚基类
     */
    class HHEventBase
    {
    public:
        /**读操作*/
        virtual void OnRead() {}

        /**写操作*/
        virtual void OnWrite() {}

        /**超时操作*/
        virtual void OnTimeout() {}

        /**execption*/
        virtual void OnException() {}

        /**conneting*/
        virtual void OnConneting() {}

        /**conneted*/
        virtual void OnConneted() {}

        /**close*/
        virtual void OnClosed() {}

        /**nonBlock?*/
        bool NonBlock(bool yes)
        {
            int flags = 0;
            if (fcntl(handler, F_GETFL, 0) == -1)
                return false;
            int newFlag = yes? (flags | O_NONBLOCK) : (flags & ~O_NONBLOCK);
            fcntl(handler, F_SETFL, newFlag);
            return true;
        }

        /**reuse?*/
        bool Reuse(bool yes)
        {
            int on = (yes? 1:0);
            if (setsockopt(handler, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == -1)
                return false;
            else
                return true;
        }

        /**keepalive?*/
        bool KeepAlive(bool yes)
        {
            int on = (yes? 1:0);
            if (setsockopt(handler, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == -1)
                return false;
            else
                return true;
        }

        /**句柄对象*/
        SOCKET handler;

        /**last active time*/
        time_t m_tLast;

        /**event's info*/
        HHEventInfo eventInfo;
    };
}

#endif // HH_EVENTBASE_H