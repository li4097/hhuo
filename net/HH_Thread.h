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

#ifndef HH_THREAD_H
#define HH_THREAD_H

#include <vector>
#include "HH_Common.h"

namespace hhou
{
    class HHTask;
    /**
     * 线程类
     */
    class HHThread
    {
        friend class HHThreadPool;
    public:
        HHThread(int nThreadID);
        virtual ~HHThread();

        /**线程执行的函数*/
        static void *Run(void *pParm);

        /**开启线程处理任务*/
        void StartThread();

    public:
        vector<HHTask> m_vTasks; /// 要处理的任务

    private:
        int m_bStatus; /// 线程状态(0---未启动，1---空闲，2---忙碌)
        int m_nThreadID; /// 线程的ID
        pthread_t m_thread; /// 线程
        pthread_cond_t m_cond; /// 条件
        pthread_mutex_t m_mutex; /// 锁
    };
}

#endif //HH_THREAD_H