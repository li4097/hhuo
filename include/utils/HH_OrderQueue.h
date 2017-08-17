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

#ifndef HH_ORDERQUEUE_H
#define HH_ORDERQUEUE_H

#include <deque>   
#include "HH_Common.h"

namespace hhou
{
	/**
	 * 有序队列
	 */
	template<typename T>
	class HHOrderQueue
	{
		typedef typename deque<T>::value_type        value_type;
		typedef typename deque<T>::size_type         size_type;
		typedef typename deque<T>::reference         reference;
		typedef typename deque<T>::const_reference   const_reference;
		typedef typename deque<T>::iterator          iterator;
		typedef typename deque<T>::const_iterator    const_iterator;

	public:
		/**
		 * 迭代器返回
		 */
		iterator Begin() { return m_queue.begin(); }
		const_iterator Begin() const { return m_queue.begin(); }
		iterator End() { return m_queue.end(); }
		const_iterator End() const { return m_queue.end(); }

		/*
		 ** 直接存取
		 */
		reference operator[](size_type n) { return m_queue[n]; }
		const_reference operator[](size_type n) const { return m_queue[n]; }

		/*
		 ** 大小
		 */
		bool Empty() 
		{ 
			bool bRet = false;
			lock_guard<mutex> lock(m_mutex);
			{
				if (m_queue.empty())
				{
					bRet = true;
				}
			}			
			return bRet;
		}
		size_type Size() const { return m_queue.size(); }

		/*
		 ** 获取头尾操作
		 */
		reference Front() { return m_queue.front(); }
		const_reference Front() const { return m_queue.front(); }
		void PopFront() 
		{ 
			lock_guard<mutex> lock(m_mutex);
			m_queue.pop_front(); 
		}
		reference Back() { return m_queue.back(); }
		const_reference Back() const { return m_queue.back(); }
		void PopBack() 
		{ 
			lock_guard<mutex> lock(m_mutex);
			m_queue.pop_back(); 
		}

		/*
		 ** 更新操作
		 */
		void Push(const value_type &x)
		{
			lock_guard<mutex> lock(m_mutex);
			auto it = find(Begin(), End(), x);
			if (it != End())
			{
				m_queue.erase(it);
			}
			m_queue.insert(lower_bound(Begin(), End(), x), x);
		}

		/**
		 * Update
		 */
		void Update(const value_type &x)
		{
			lock_guard<mutex> lock(m_mutex);
			auto it = find(Begin(), End(), x);
			if (it == End())
			{
				m_queue.insert(lower_bound(Begin(), End(), x), x);
			}
		}

		/*
		 ** 删除所有值为 x 的元素
		 */
		void Remove(const value_type &x) 
		{
			/// 用equal_range效率较高
			lock_guard<mutex> lock(m_mutex);
			auto interval = equal_range(Begin(), End(), x);
			m_queue.erase(interval.first, interval.second);
		}
		void Clear() { m_queue.clear(); }

	protected:
		mutex m_mutex; /// 需要锁的保护
		deque<T> m_queue;  /// 有序队列对象
	};
}
#endif // HH_ORDERQUEUE_H