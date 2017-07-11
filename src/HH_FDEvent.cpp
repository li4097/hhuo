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

#include "HH_FDEvent.h"
#include "HH_Poller.h"
#include "HH_CircularBuffer.h"

hhou::HHFDEvent::HHFDEvent(HHPoller *poller, size_t bufSize)
        : m_pPoller(poller),
          m_bufIn(*this, bufSize),
          m_bufOut(*this, bufSize)
{
    cout << "create new fdEvent" << endl;
}

hhou::HHFDEvent::~HHFDEvent()
{

}

void hhou::HHFDEvent::OnRead()
{
    int n = (int)m_bufIn.Space();
    char buf[TCP_BUFSIZE];

    int ret = 1;
    while (ret)
    {
        n = recv(handler, buf, (n < TCP_BUFSIZE) ? n : TCP_BUFSIZE, MSG_PEEK);
        if (n < 0)
        {
            /// 由于是非阻塞的模式,
            /// 所以当errno为EAGAIN时,表示当前缓冲区已无数据可读
            if(errno == EAGAIN)
                break;
        }
        else if (n == 0) /// 这里表示对端的socket已正常关闭.
        {
            cout << "fdEvent " << handler << " read erron" << errno << endl;
            eventInfo.status = Close;
            m_pPoller->DelEvent(this);
            closesocket(handler);
        }
        else
        {
            /// TODO<添加处理代码>
        }
        if(n == TCP_BUFSIZE)
            ret = 1;
        else
            ret = 0;
    }
}

void hhou::HHFDEvent::OnWrite()
{
    cout << "HHFDEvent OnWrite" << endl;
}

void hhou::HHFDEvent::OnTimeout()
{
    cout << "HHFDEvent OnTimeout" << endl;
}

void hhou::HHFDEvent::OnClosed()
{
    cout << "HHFDEvent OnClosed" << endl;
}