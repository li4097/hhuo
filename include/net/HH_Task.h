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
#ifndef HH_TASK_H
#define HH_TASK_H

#include "HH_EventBase.h"
#include "../HH_Log.h"

namespace hhou
{
    /**
     * 线程的执行任务类
     */
    struct HHTask
    {
        HHTask(int nID, void *pVoid) : m_nID(nID), m_pData(pVoid) {}
        int Excute() const
        {
            HHEventBase *pEvent = static_cast<HHEventBase *>(m_pData);
            if (pEvent->eventInfo.status == In)
            {
                pEvent->OnRead();
            }
            else if (pEvent->eventInfo.status == Out)
            {
                pEvent->OnWrite();
            }
            else
            {
                /// 将要关闭的socket
                return -1;
            }
            return 0;
        }
        int m_nID; /// 任务编号
        void *m_pData; /// 任务的数据
    };
}

#endif //HH_TASK_H