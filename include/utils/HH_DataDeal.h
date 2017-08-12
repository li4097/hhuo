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

#ifndef HH_DATADEAL_H
#define HH_DATADEAL_H

#include "net/HH_Task.h"
#include "HH_WorkerPool.h"

namespace hhou
{
    class HHDataDeal : public HHWorkerPool<HHTask>
    {
    public:
        HHDataDeal() {}
        virtual ~HHDataDeal() {}

        void DoWork(HHTask *tsk)
        {
            tsk->Excute();
        }
    };
}

#endif // HH_DATADEAL_H