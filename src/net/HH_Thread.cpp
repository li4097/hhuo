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

#include "HH_Thread.h"
#include "HH_Task.h"
#include "HH_Log.h"

hhou::HHThread::HHThread(int nThreadID)
        : m_bStatus(0),
          m_nThreadID(nThreadID)
{
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if (pthread_create(&m_thread, &attr, Run, this) == -1)
    {
        LOG(ERROR) << "pthread_create errno: " << errno;
    }
    pthread_attr_destroy(&attr);
    m_bStatus = 1;
}

hhou::HHThread::~HHThread()
{
    m_bStatus = 0;
    pthread_join(m_thread, NULL);
}

void* hhou::HHThread::Run(void *pParm)
{
    HHThread *pclThread = (HHThread *)pParm;
    while (pclThread->m_bStatus)
    {
        pclThread->m_mutex.Lock();  /// 先锁
        if (pclThread->m_vTasks.size() <= 0)
        {
            pclThread->m_bStatus = 1; /// 空闲中
            pclThread->m_cond.Wait(pclThread->m_mutex); /// 等待条件触发
        }
        else
        {
            pclThread->m_bStatus = 2; /// 忙碌中
            /// 开始处理task的任务
            for (vector<HHTask>::iterator iter = pclThread->m_vTasks.begin();
                 iter != pclThread->m_vTasks.end();)
            {
                (*iter).Excute();
                iter = pclThread->m_vTasks.erase(iter);
            }
        }
        pclThread->m_mutex.Unlock();
    }
    return pParm;
}

void hhou::HHThread::StartThread()
{
    m_mutex.Lock();
    m_cond.Notify();
    m_mutex.Unlock();
}

