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

#ifndef HH_MUTEX_H
#define HH_MUTEX_H

#include "HH_Common.h"

namespace hhou
{
    /**
     * 互斥锁
     */
    class HHMutex
    {
    public:
        /**
         * 禁用锁的复制
         */
        HHMutex(const HHMutex &rhs) = delete;
        HHMutex &operator=(const HHMutex &rhs) = delete;

        /**
         * 默认构造函数
         */
        HHMutex()
        {
            pthread_mutex_init(&m_mutex, NULL);
        }

        /**
         * 析构
         */
        virtual ~HHMutex()
        {
            pthread_mutex_destroy(&m_mutex);
        }

        /**
         * 上锁
         */
        void Lock()
        {
            pthread_mutex_lock(&m_mutex);
        }

        /**
         * 解锁
         */
        void Unlock()
        {
            pthread_mutex_unlock(&m_mutex);
        }

    private:
        pthread_mutex_t m_mutex;  /// 锁的对象
    };
}

#endif // HH_MUTEX_H