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
#include "HH_Log.h"

hhou::HHThreadPool::HHThreadPool()
{
    Init(); /// 初始化
    LOG(INFO) << "Init threadpool";
}

bool hhou::HHThreadPool::Dispatch(const vector<HHTask> &vTasks)
{
    /**
     * fd除余就是线程的ID号
     * 相同的fd应当放到一个线程中执行
     * 因为不同线程之间存在对象被删除的时候，其他线程正在访问
     * */
    vector<HHThread *> vecToStart;  /// 需要工作的线程
    for (auto it = vTasks.begin(); it != vTasks.end(); it++)
    {
        int nSeq = (*it).m_nID % m_nThreadNums;
        auto thread = m_threadPool.find(nSeq);
        if (thread != m_threadPool.end())
        {
            vecToStart.push_back(thread->second);
            thread->second->m_vTasks.push_back((*it));
        }
    }

    /// 开启线程（已经在运行的则跳过）
    for (auto item = vecToStart.begin(); item != vecToStart.end(); item++)
    {
        if ((*item)->m_bStatus == 1)  /// 空闲中
        {
            (*item)->StartThread();
        }
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