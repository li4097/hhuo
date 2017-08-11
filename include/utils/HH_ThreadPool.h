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

#ifndef HH_THREADPOOL_H
#define HH_THREADPOOL_H

#include <vector>
#include <map>
#include "HH_Thread.h"
#include "HH_Config.h"

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
         virtual ~HHThreadPool() 
         {
            if (g_threadPoolObj != nullptr)
            {
                delete g_threadPoolObj;
                g_threadPoolObj = nullptr;
            }
         }

         /**
          * 初始化
          */
         bool Init(int nThreadNum = HHConfig::Instance().ReadInt("thread", "num", 10));

         /**
          * 线程池的单例模式
          */
         static HHThreadPool *Instance()
         {
            if (g_threadPoolObj == nullptr)
            {
               g_threadPoolObj = new HHThreadPool();
            }
            return g_threadPoolObj;
         }

     public:
         int m_nThreadNums; /// 线程的个数
         map<int, HHThread *> m_threadPool; /// 线程存放map中

    private:
        static HHThreadPool *g_threadPoolObj;
     };
}
#endif //HH_THREADPOOL_H