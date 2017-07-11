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

#include <vector>
#include <map>
#include "HH_Thread.h"

namespace hhou
{
    /**
     * 线程池的管理
     */
     class HHThreadPool
     {
     public:
         /**
          * 线程池的构造函数
          */
         HHThreadPool();
         virtual ~HHThreadPool() {}

         /**
          * 初始化
          */
         bool Init(int nThreadNum = THREAD_NUM);

         /**
          * dispatch任务到各个线程上
          */
         bool Dispatch(const vector<HHTask> &vTasks);

         /**
          * 线程池的单例模式
          */
         static HHThreadPool &Instance()
         {
             static HHThreadPool threadPool;
             return threadPool;
         }

     private:
         int m_nThreadNums; /// 线程的个数
         map<int, HHThread *> m_threadPool; /// 线程存放map中
     };
}