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

#include <map>
#include "HH_Thread.h"
#include "HH_Task.h"
#include "HH_Log.h"

hhou::HHThread::HHThread(int nThreadID)
        : m_bStatus(0),
          m_nThreadID(nThreadID)
{
    m_thread = thread(Run, this);
    m_bStatus = 1;
}

hhou::HHThread::~HHThread()
{
    m_thread.join();
    m_bStatus = 0;
}

void hhou::HHThread::PushTask(HHTask &tsk)
{
    m_qTasks.PutBack(tsk);
}

void hhou::HHThread::Run(void *pParm)
{
    auto pclThread = (HHThread *)pParm;
    while (pclThread->m_bStatus > 0)
    {
        lock_guard<mutex> lock(pclThread->m_mutex);  /// 先锁
        if (pclThread->m_qTasks.Empty())
        {
            pclThread->m_bStatus = 1; /// 空闲中
            pclThread->m_cond.wait(pclThread->m_mutex); /// 等待条件触发
        }
        else
        {
            pclThread->m_bStatus = 2; /// 忙碌中
            while (!pclThread->m_qTasks.Empty())
            {
                HHTask tsk;
                pclThread->m_qTasks.TakeFront(tsk);
                tsk.Excute();
            }
        }
    }
}

void hhou::HHThread::StartThread()
{
    lock_guard<mutex> lock(m_mutex);
    m_cond.notify_one();
}

