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

#ifndef HH_CONDITION_H
#define HH_CONDITION_H

#include "HH_Common.h"
#include "HH_Mutex.h"

namespace hhou
{
    /**
     * 条件变量对象
     */
    class HHCond
    {
    public:
        /**
         * 禁用条件变量的复制
         */
        HHCond(const HHCond &rhs) = delete;
        HHCond &operator=(const HHCond &rhs) = delete;

        /**
         * 默认构造函数
         */
        HHCond()
        {
            pthread_cond_init(&m_cond, NULL);
        }

        /**
         * 析构
         */
        virtual ~HHCond() {}

        /**
         * 等待触发
         */
        void Wait(HHMutex &mutex)
        {
            pthread_cond_wait(&m_cond, mutex.GetMutexObj());
        }

        /**
         * 通知
         */
        void Notify()
        {
            pthread_cond_signal(&m_cond);
        }

        /**
         * 通知ALL
         */
        void NotifyAll()
        {
            pthread_cond_broadcast(&m_cond);
        }

    private:
        pthread_cond_t m_cond; /// 条件变量
        HHMutex m_mutex;  /// 锁的对象
    };
}

#endif // HH_MUTEX_H