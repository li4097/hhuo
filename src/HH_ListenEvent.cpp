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

#include "HH_Common.h"
#include "HH_ListenEvent.h"
#include "HH_Poller.h"

hhou::HHListenEvent::HHListenEvent(HHPoller *poller)
        : m_pPoller(poller),
          m_connectionNum(0)
{
    eventInfo.flags = HHFast;
    cout << "Init ListenEvent" << endl;
}

bool hhou::HHListenEvent::Listen(const string &addr, const port_t &port, size_t listenFds)
{
    struct sockaddr_in listenAddr;
    memset(&listenAddr, 0, sizeof(listenAddr));
    handler = socket(AF_INET, SOCK_STREAM, 0);
    if (!NonBlock(true))
    {
        cout << "NonBlock error, errno:" << errno << endl;
        return false;
    }
    if (!Reuse(true))
    {
        cout << "Reuse error, errno:" << errno << endl;
        return false;
    }
    listenAddr.sin_family = AF_INET;
    listenAddr.sin_addr.s_addr = inet_addr(addr.c_str());
    listenAddr.sin_port = htons(port);
    if (bind(handler, (struct sockaddr *)&listenAddr, sizeof(listenAddr)) == -1)
    {
        cout << "bind error, errno:" << errno << endl;
        return false;
    }
    if(listen(handler, listenFds) == -1)
    {
        cout << "listen error, errno:" << errno << endl;
        return false;
    }

    /// 添加到epoll的监控中
    {
        eventInfo.status = In;
        eventInfo.flags = HHFast;
        eventInfo.nType = 0;
        m_pPoller->AddEvent(this);
    }
    return true;
}

void hhou::HHListenEvent::OnConneting()
{
    cout << "new connection" << endl;
}