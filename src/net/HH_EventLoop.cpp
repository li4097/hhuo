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
#include "HH_ListenEvent.h"
#include "HH_EventLoop.h"
#include "HH_Task.h"
#include "utils/HH_DataDeal.h"

hhou::HHEventLoop::HHEventLoop()
        : m_bQuit(false),
          m_pPoller(new HHPoller)
{

}

hhou::HHEventLoop::~HHEventLoop()
{
    m_bQuit = true;
}

bool hhou::HHEventLoop::Loop(const int &timeout)
{
    while (!m_bQuit)
    {
        m_pPoller->ProcessEvents(timeout, m_qEvents);
        while (!m_qEvents.empty())
        {
            /// 准备任务，将作分发处理
            auto iter = m_qEvents.front();
            HHTask tsk(iter->handler, static_cast<void *>(iter));
            m_qEvents.pop();
        }
    }
    return true;
}
