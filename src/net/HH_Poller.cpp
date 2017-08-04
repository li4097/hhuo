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
#include "net/HH_FDEvent.h"
#include "utils/HH_MutexLockGuard.h"
#include "utils/HH_ThreadPool.h"
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
    event->m_tLast = time(nullptr);
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
}

void hhou::HHPoller::DelEvent(HHEventBase *event)
{
    event->eventInfo.status = Close;
    struct epoll_event ev = {};
    ev.data.ptr = event;
    epoll_ctl(m_epollFd, EPOLL_CTL_DEL, event->handler, &ev);
    {
        HHMutexLockGuard lock(m_mutex);
        event->m_tLast = 0;
        m_mClosing.insert(make_pair(event->handler, event));
    }
}

void hhou::HHPoller::ProcessEvents(int timeout, queue<HHEventBase *> &qEvents)
{
    /// close closing socket
    {
        HHMutexLockGuard lock(m_mutex);
        for (auto iter = m_mClosing.begin(); iter != m_mClosing.end();)
        {
            HHEventBase *pSocket = iter->second;
            if (pSocket != nullptr)
            {
                pSocket->OnClosed();
                delete pSocket;
                pSocket = nullptr;
            }
            iter = m_mClosing.erase(iter);
        }
    }

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

    /// 打印客户端的流量信息
    for (int n = 0; n < fds; n++)
    {
        ipaddr_t ip;
        port_t port;
        auto pEvent = static_cast<HHFDEvent *>(m_events[n].data.ptr);
        pEvent->GetIpAndPort(ip, port);
        LOG(INFO) << "IP: " << ip << ", port: " << port << ", recved: " << pEvent->m_nTotalRecv << ", sent: " << pEvent->m_nTotalSend;
    }

    /// 打印线程里的剩余任务数
    if ((time(nullptr) - m_nStart) % 120 == 0)
    {
        for (auto it : HHThreadPool::Instance().m_threadPool)
        {
            auto th = it.second;
            LOG(INFO) << "Thread ID: " << it.first << " task's num: " << th->m_qTasks.size();
        }
    }
}

void hhou::HHPoller::UpdateConnNums(int nNum)
{
    m_connectionNum += nNum;
    LOG(INFO) << "Current connection num: " << m_connectionNum;
}