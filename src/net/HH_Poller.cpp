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
#include "HH_Log.h"

hhou::HHPoller::HHPoller()
        : m_connectionNum(0)
{
    m_epollFd = epoll_create(8096); // 新建epoll对象
    if (m_epollFd <= 0)
    {
        LOG(ERROR) << "Poller epoll_create failure!";
        exit(-1);
    }
}

void hhou::HHPoller::AddEvent(HHEventBase *event)
{
    struct epoll_event ev;
    ev.events = EPOLLIN | EPOLLET;
    ev.data.ptr = event;
    epoll_ctl(m_epollFd, EPOLL_CTL_ADD, event->handler, &ev);
    event->m_tLast = time(0);
    if (event->eventInfo.nType != 0)  /// listen不加入监控
    {
        m_mHandlers.insert(make_pair(event->m_tLast, event));
    }
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
    event->m_tLast = time(0);
}

void hhou::HHPoller::DelEvent(HHEventBase *event)
{
    event->eventInfo.status = Close;
    struct epoll_event ev;
    ev.data.ptr = event;
    epoll_ctl(m_epollFd, EPOLL_CTL_DEL, event->handler, &ev);
    m_mHandlers.erase(event->m_tLast);
    event->m_tLast = 0;
}

void hhou::HHPoller::ProcessEvents(int timeout, vector<HHEventBase *> &vEvents)
{
    /// checkout timeout
    time_t expireTime = time(0) - HH_Config::Instance().ReadInt("connection", "timeout", 60);
    pair<multiMapItor, multiMapItor> pos = m_mHandlers.equal_range(expireTime);
    for (multimap<time_t, HHEventBase *>::iterator it = pos.first; it != pos.second;)
    {
        HHEventBase *pEvent = it->second;
        m_mHandlers.erase(it++);
        pEvent->OnTimeout(); /// 作超时处理
    }

    /// wait for events to happen
    int fds = epoll_wait(m_epollFd, m_events, Poller_MAX_EVENT, timeout);
    if (fds == -1)
    {
        LOG(ERROR) << "epoll_wait error, errno:" << errno;
        return;
    }
    for(int i = 0; i < fds; i++)
    {
        HHEventBase *pEvent = static_cast<HHEventBase *>(m_events[i].data.ptr);
        if (pEvent->eventInfo.nType == 0)
        {
            /// accept立即响应
            pEvent->OnConneting();
        }
        else
        {
            vEvents.push_back(pEvent);
        }
    }
}

void hhou::HHPoller::UpdateConnNums(int nNum)
{
    m_connectionNum += nNum;
    LOG(INFO) << "Current connection num: " << m_connectionNum;
}