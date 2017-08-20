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
#ifndef HH_TASKPOOL_H
#define HH_TASKPOOL_H

#include <iostream>
#include <thread>
#include "HH_Task.h"
#include "HH_Config.h"
#include "HH_WorkerPool.h"
#include "HH_Common.h"

namespace hhou
{	
	class HHExcWorkerPool : public HHWorkerPool<HHTask>
	{
	public:
		HHExcWorkerPool(int nTaskThread = 1/**有序执行，必须设置为1*/)
		{
			Start(bind(&HHExcWorkerPool::DoWork, this, placeholders::_1), nTaskThread);
		}

		virtual ~HHExcWorkerPool()
		{
			Stop();
		}
		
		void DoWork(HHTask *quest)
		{
			quest->Excute();
		}
	};
	
	class HHTaskPool
	{
		typedef vector<hhou::HHExcWorkerPool *>::const_iterator CTIter;
	public:
		HHTaskPool(int nNum = HHConfig::Instance().ReadInt("thread", "num", 10)) : m_nNum(nNum)
		{
			m_taskPool.resize(nNum);
			for (int j = 0; j < m_nNum; j++)
			{
				m_taskPool[j] = new hhou::HHExcWorkerPool;
			}
		}

		virtual ~HHTaskPool()
		{
			for (CTIter it = m_taskPool.begin(); it != m_taskPool.end();)
			{
				delete (*it);
				it = m_taskPool.erase(it);
			}
		}

		hhou::HHExcWorkerPool *GetWorkPool(int nSeq)
		{
			return m_taskPool[nSeq % m_nNum];
		}

		static HHTaskPool *Instance()
		{
			static HHTaskPool m_gTaskPool;
			return &m_gTaskPool;
		}

	private:
		int m_nNum;
		vector<hhou::HHExcWorkerPool *> m_taskPool;
	};
}

#endif // HH_TASKPOOL_H