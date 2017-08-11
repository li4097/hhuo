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

#include <queue>
#include "HH_Task.h"
#include "HH_ThreadPool.h"

hhou::HHThreadPool *hhou::HHThreadPool::g_threadPoolObj = nullptr;
hhou::HHThreadPool::HHThreadPool()
{
    
}

bool hhou::HHThreadPool::Init(int nThreadNum)
{
    m_nThreadNums = nThreadNum;
    for (int i = 0; i < m_nThreadNums; ++i)
    {
        auto pThread = new HHThread(i); /// 初始化线程
        m_threadPool.insert(make_pair(i, pThread)); /// 添加到map中
    }
    LOG(INFO) << "Init threadpool";
    return true;
}