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

#include "HH_Thread.h"

hhou::HHThread::HHThread()
{
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    if (pthread_create(&m_thread, &attr, StartThread, this) == -1)
    {
        cout << "pthread_create errno: " << errno << endl;
        m_bRunning = false;
    }
    pthread_attr_destroy(&attr);
    m_bRunning = true;
}

hhou::HHThread::~HHThread()
{
    m_bRunning = false;
    pthread_join(m_thread, NULL);
}

void* hhou::HHThread::StartThread(void *pParm)
{
    HHThread *pclThread = (HHThread *)pParm;
    pclThread->Run();
    return pParm;
}

int hhou::HHThread::Run()
{
    while (m_bRunning)
    {
        cout << "I am running" << endl;
        sleep(5);
    }
    return 1;
}

