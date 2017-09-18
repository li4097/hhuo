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
#ifndef HH_WORKERPOOL_H
#define HH_WORKERPOOL_H

#include <vector>
#include <queue>
#include "../HH_Common.h"

namespace hhou
{
	template<typename T>
	class HHWorkerPool
	{
	public:
		typedef HHWorkerPool<T> THIS_TYPE;
		typedef function<void(T *)> WorkerProc;
		typedef vector<thread *> ThreadVec;

		HHWorkerPool() : m_bActive(false) {}
		virtual ~HHWorkerPool()
		{
			m_vThreads.clear();
		}

		void Start(WorkerProc f, int workerNum = 1)
		{
			m_bActive = true;
			m_vThreads.resize(workerNum);
			for (int i = 0; i < workerNum; i++)
			{
				m_vThreads[i] = new thread(bind(&THIS_TYPE::Consumer, this));
			}
			m_pProc = f;
		}

		void Push(T *t)
		{
			unique_lock<mutex> lck(m_mutex);
			m_task.push(t);
			m_cv.notify_one();
		}

		void Stop()
		{
			m_mutex.lock();
			while (!m_task.empty())
			{
				m_mutex.unlock();
				this_thread::sleep_for(chrono::milliseconds(1000));
				m_cv.notify_one();
				m_mutex.lock();
			}
			m_mutex.unlock();
			m_bActive = false;
			m_cv.notify_all();
			for (ThreadVec::iterator it = m_vThreads.begin(); it != m_vThreads.end(); ++it)
			{
				(*it)->join();
				delete (*it);
			}
		}
	private:
		void Consumer()
		{
			unique_lock<mutex> lck(m_mutex);
			while (m_bActive)
			{
				while (m_bActive && m_task.empty())
				{
					m_cv.wait(lck);
				}
				if (!m_bActive)
					break;
				T *quest = m_task.front();
				m_task.pop();
				lck.unlock();
				m_pProc(quest);
				lck.lock();
			}
		}

		mutex m_mutex;
		queue<T *> m_task;
		condition_variable m_cv;
		bool m_bActive;
		vector<thread *> m_vThreads;
		WorkerProc m_pProc;
	};
}

#endif // HH_WORKERPOOL_H