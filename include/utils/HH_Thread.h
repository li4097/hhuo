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

#include <queue>
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

        /**push任务*/
        void PushTask(HHTask *tsk);
		
	private:
		/**线程执行的函数*/
		void Run();
		
    public:
        queue<HHTask *> m_qTasks; /// 要处理的任务
		
    private:
        int m_nThreadID; /// 线程的ID
		bool m_bRun;  /// 线程是否运行的标志
        thread m_thread; /// 线程
        condition_variable_any m_cond; /// 条件
        mutex m_mutex; /// 锁
    };
}

#endif //HH_THREAD_H