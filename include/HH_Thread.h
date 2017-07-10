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

#include <set>
#include "HH_Common.h"

namespace hhou
{
    /**当本线程的任务完成时（包括执行失败的）想管理者提交信息*/
    typedef void (*commit)(int nThreadID, set<int> sFailTask);

    /**任务*/
    struct HHTask
    {
        int nID; /// 任务编号
        void *pData; /// 任务的数据
    };

    /**
     * 线程类
     */
    class HHThread
    {
    public:
        HHThread();
        virtual int Run();
        virtual ~HHThread();

        /**线程执行的函数*/
        static void *StartThread(void *);

        /**获取线程状态*/
        bool GetStatus() { return m_bRunning; }

    public:
        commit Tell; /// 保存提交函数指针
        set<HHTask> m_sTasks; /// 要处理的任务

    private:
        int m_nThreadID; /// 线程的ID
        bool m_bRunning; /// 线程是否正常启动
        pthread_t m_thread; /// 线程
    };
}

#endif //HH_THREAD_H