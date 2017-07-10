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


#include <vector>
#include "HH_Common.h"
#include "HH_Poller.h"

hhou::HHPoller::HHPoller()
{
    m_epollFd = epoll_create(Poller_MAX_FD); // 新建epoll对象
    if (m_epollFd <= 0)
    {
        cout << "Poller epoll_create failure!" << endl;
        exit(-1);
    }
}

void hhou::HHPoller::AddEvent(HHEventBase *event)
{
    struct epoll_event ev;
    ev.events = EPOLLIN | EPOLLET;
    ev.data.ptr = event;
    epoll_ctl(m_epollFd, EPOLL_CTL_ADD, event->handler, &ev);
}

void hhou::HHPoller::ChangeEvent(HHEventBase *event)
{
    struct epoll_event ev;
    if (event->eventInfo.status == In)
        ev.events = EPOLLIN | EPOLLET;
    else
        ev.events = EPOLLOUT | EPOLLET;
    ev.data.ptr = event;
    epoll_ctl(m_epollFd, EPOLL_CTL_MOD, event->handler, &ev);
}

void hhou::HHPoller::DelEvent(HHEventBase *event)
{
    event->eventInfo.status = Close;
    struct epoll_event ev;
    ev.data.ptr = event;
    epoll_ctl(m_epollFd, EPOLL_CTL_DEL, event->handler, &ev);
}

void hhou::HHPoller::ProcessEvents(int timeout, vector<HHEventBase *> &vEvents)
{
    /// wait for events to happen
    int fds = epoll_wait(m_epollFd, m_events, Poller_MAX_EVENT, timeout);
    if (fds == -1)
    {
        cout << "epoll_wait error, errno:" << errno << endl;
        return;
    }
    for(int i = 0; i < fds; i++)
    {
        HHEventBase *pEvent = static_cast<HHEventBase *>(m_events[i].data.ptr);
        if (pEvent->eventInfo.nType == 0)
        {
            pEvent->OnConneting();
        }
        else
        {
            vEvents.push_back(pEvent);
        }
    }
}