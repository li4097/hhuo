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

#include <set>
#include "../../include/net/HH_ListenEvent.h"
#include "../../include/net/HH_EventLoop.h"
#include "../../include/HH_Config.h"
#include "../../include/utils/HH_TaskPool.h"

hhou::HHEventLoop::HHEventLoop()
        : m_bQuit(true),
		  m_Poller(make_shared<HHPoller>())
{
    
}

void hhou::HHEventLoop::Start(const int &nLoopTimeout, const int &nFdTimeOut)
{
	m_bQuit = false;
	m_Thread = make_shared<thread>(bind(&HHEventLoop::Loop, this, nLoopTimeout, nFdTimeOut));
}

void hhou::HHEventLoop::Stop()
{
	m_bQuit = true;
}

bool hhou::HHEventLoop::Init(const string &strHost, const int port, const string &strCert, const string &strKey)
{
	m_Listener = make_shared<HHListenEvent>(m_Poller);
	if (!m_Listener->Init(strCert, strKey))
	{
		LOG(ERROR) << "Listener Init error.";
		return false;
	}
	if (!m_Listener->Listen(strHost, port))
	{
		LOG(ERROR) << "Server Listen Addr: " << strHost << ", port: " << port << " error.";
		return false;
	}
	LOG(INFO) << "Server Listen Addr: " << strHost << ", port: " << port;
	return true;
}

hhou::HHEventLoop::~HHEventLoop()
{
    m_bQuit = true;
}

bool hhou::HHEventLoop::Loop(const int &nLoopTimeout, const int &nFdTimeOut)
{
    while (!m_bQuit)
    {
        m_Poller->ProcessEvents(nLoopTimeout, m_qEvents, nFdTimeOut);
        while (!m_qEvents.empty())
        {
            /// 准备任务，将作分发处理
            auto iter = m_qEvents.front();
            HHTask *tsk = new HHTask(iter->handler, static_cast<void *>(iter));
            HHTaskPool::Instance()->GetWorkPool(iter->handler)->Push(tsk);
            m_qEvents.pop();
        }
    }
    return true;
}
