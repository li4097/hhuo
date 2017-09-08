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

#include "HH_Parse.h"
#include "HH_FDEvent.h"
#include "HH_Poller.h"
#include "HH_Task.h"
#include "HH_Log.h"

hhou::HHPoller::HHPoller()
		: m_connectionNum(0),
          m_nStart(time(nullptr))
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
    struct epoll_event ev = {};
    ev.events = EPOLLIN | EPOLLET;
    ev.data.ptr = event;
    epoll_ctl(m_epollFd, EPOLL_CTL_ADD, event->handler, &ev);
    if (event->eventInfo.nType != 0)
    {
        event->m_tLast = time(nullptr);
        m_AllSockets.Push(event);
        UpdateConnNums(1);
    }
}

void hhou::HHPoller::ChangeEvent(HHEventBase *event)
{
    struct epoll_event ev = {};
    if (event->eventInfo.status == In)
        ev.events = EPOLLIN | EPOLLET;
    else
        ev.events = EPOLLOUT | EPOLLET;
    ev.data.ptr = event;
    epoll_ctl(m_epollFd, EPOLL_CTL_MOD, event->handler, &ev);
    event->m_tLast = time(nullptr);
    m_AllSockets.Push(event);
}

void hhou::HHPoller::DelEvent(HHEventBase *event)
{
    struct epoll_event ev = {};
    ev.data.ptr = event;
    epoll_ctl(m_epollFd, EPOLL_CTL_DEL, event->handler, &ev);
    event->m_tLast = 0;
    m_AllSockets.Push(event); 
    UpdateConnNums(-1);
}

void hhou::HHPoller::ProcessEvents(int timeout, queue<HHEventBase *> &qEvents)
{   
    /// check timeout
    time_t expireTime = time(nullptr) - HHConfig::Instance().ReadInt("connection", "timeout", 60);
    while (!m_AllSockets.Empty())
    {
        auto it = m_AllSockets.Front();
        if (it->m_tLast < expireTime)
        {
            if (it->m_tLast == 0)
            {
                LOG(INFO) << "socket: " << it->handler << " closed.";
            }
            else
            {
                LOG(INFO) << "socket: " << it->handler << " timeout.";
            }
            it->OnTimeout();
            m_AllSockets.PopFront();
        }
        else
        {
            break;
        }  
    }
    LOG_IF_EVERY_N(INFO, m_AllSockets.Size(), 100) << UpdateBytes();
	
    /// wait for events to happen
    int fds = epoll_wait(m_epollFd, m_events, Poller_MAX_EVENT, timeout);
    for(int i = 0; i < fds; i++)
    {
        auto pEvent = static_cast<HHEventBase *>(m_events[i].data.ptr);
        if (pEvent->eventInfo.nType == 0)
        {
            /// accept立即响应
            pEvent->OnConneting();
        }
        else
        {
            qEvents.push(pEvent);
        }
    }
}

void hhou::HHPoller::UpdateConnNums(int nNum)
{
    m_connectionNum += nNum;
    if (m_connectionNum < 0)
    {
        m_connectionNum = 0;
    }
    LOG(INFO) << "Current socket num: " << m_connectionNum << ".";
}

string hhou::HHPoller::UpdateBytes()
{
    ostringstream os;
    os << "\n\nThere are ";
    os << m_AllSockets.Size();
    os << " connections.\n";
    for (size_t i = 0; i < m_AllSockets.Size(); ++i)
    {
        auto pEvent = (HHFDEvent *)m_AllSockets[i];
        ipaddr_t ip;
        port_t port;
        pEvent->GetIpAndPort(ip, port);
        struct in_addr addr;
        addr.s_addr = ip;
        os << "Connection " << inet_ntoa(addr) << " " << ntohs(port);
        os << " received: " << pEvent->m_nTotalRecv;
        os << ", sent: " << pEvent->m_nTotalSend << ".\n";
    }
    return os.str();
}
