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
#include "HH_Task.h"
#include "HH_ThreadPool.h"

hhou::HHThreadPool::HHThreadPool()
{
    Init(); /// 初始化
    cout << "Init threadpool" << endl;
}

bool hhou::HHThreadPool::Dispatch(const vector<HHTask> &vTasks)
{
    /// 统计下空闲的线程
    set<int> idleThreadID;
    for (int i = 0; i < m_nThreadNums; i++)
    {
        if (m_threadPool[i]->m_bStatus == 1)
            idleThreadID.insert(m_threadPool[i]->m_nThreadID);
    }

    /// 将任务平均分配至线程执行
    size_t cout = 0;
    int threadSize = vTasks.size() / idleThreadID.size();
    for (set<int>::iterator j = idleThreadID.begin(); j != idleThreadID.end(); j++)
    {
        HHThread *pThread = m_threadPool[*j];
        if (cout == idleThreadID.size())
        {
            pThread->m_vTasks.assign(vTasks.begin() + cout * threadSize, vTasks.begin() + (cout + 1) * threadSize);
            pThread->StartThread();  /// 开启线程处理
        }
        else
        {
            pThread->m_vTasks.assign(vTasks.begin() + cout * threadSize, vTasks.end());
            pThread->StartThread();  /// 开启线程处理
            break;
        }
        cout++; /// 下一个线程任务集的起始位置
    }
    return true;
}

bool hhou::HHThreadPool::Init(int nThreadNum)
{
    m_nThreadNums = nThreadNum;
    for (int i = 0; i < m_nThreadNums; ++i)
    {
        HHThread *pThread = new HHThread(i); /// 初始化线程
        m_threadPool.insert(make_pair(i, pThread)); /// 添加到map中
    }
    return true;
}