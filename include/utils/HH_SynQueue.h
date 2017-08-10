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

#ifndef HH_SYNQUEUE_H
#define HH_SYNQUEUE_H

#include "HH_common.h"

namespace hhou
{
	template<typename T>
	class HHSynQueue
	{
	public:
		/// 构造函数
		HHSynQueue() {}
		virtual ~HHSynQueue() {}

		/// 将T类型对象放入队列
		void Put(T &x)
		{
			lock_guard<mutex> locker(m_mutex);
			m_queue.push(x);
		}

		/// 将T类型对象从队列取出
		void Take(T &x)
		{
			lock_guard<mutex> locker(m_mutex);
			x = m_queue.front();
			m_queue.pop();
		}

		/// 判断队列是否为空
		bool Empty()
		{
			lock_guard<mutex> locker(m_mutex);
			return m_queue.empty();
		}

		/// 返回队列大小
		size_t Size()
		{
			lock_guard<mutex> locker(m_mutex);
			return m_queue.size();
		}

	private:
		queue<T> m_queue; /// 队列
		mutex m_mutex; /// 互斥锁
	};
}
#endif // HH_SYNQUEUE_H