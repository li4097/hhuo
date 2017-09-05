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
#ifndef HH_EVENTLOOP_H
#define HH_EVENTLOOP_H

#include <queue>
#include "HH_Poller.h"
#include "HH_ListenEvent.h"
#include "utils/HH_DataDeal.h"

namespace hhou
{
    /**
     * loop对象
     */
    class HHEventLoop
    {
    public:
        HHEventLoop();
        virtual ~HHEventLoop();
		
		/**
         * 初始化
         */
        bool Init(const string &strHost, const int port);
		
		/**
         * 开启服务
         */
        void Start();
		
		/**
         * 关闭服务
         */
        void Stop();
		
	private:
		/**
         * 循环事件处理
         */
        bool Loop(const int &timeout);

    private:
        bool m_bQuit; /// loop的中止标志
        shared_ptr<HHPoller> m_Poller; /// poller对象
		shared_ptr<HHListenEvent> m_Listener; /// listener的对象
        queue<HHEventBase *>  m_qEvents; ///触发的socket
		shared_ptr<thread> m_Thread; /// 线程执行
    };
}

#endif //HH_EVENTLOOP_H