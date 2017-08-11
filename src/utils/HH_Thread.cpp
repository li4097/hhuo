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

#include <map>
#include "HH_Thread.h"
#include "HH_Task.h"
#include "HH_Log.h"

hhou::HHThread::HHThread(int nThreadID)
        : m_nThreadID(nThreadID),
		  m_bRun(true)
{
    m_thread = thread(&HHThread::Run, this);
}

hhou::HHThread::~HHThread()
{
    m_thread.join();
}

void hhou::HHThread::PushTask(HHTask *tsk)
{
	unique_lock<mutex> lock(m_mutex);
    m_qTasks.push(tsk);
	m_cond.notify_one();
}

void hhou::HHThread::Run()
{
	unique_lock<mutex> lock(m_mutex);  /// 先锁
	while (m_bRun)
	{
		while (m_bRun && m_qTasks.empty())
		{
		    m_cond.wait(lock);
		}
		if (!m_bRun)
			break;
		HHTask *tsk = m_qTasks.front();
		m_qTasks.pop();
		lock.unlock();
		tsk->Excute();
		delete tsk;
		tsk = nullptr;
		lock.lock();
	}
}

