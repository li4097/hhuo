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

#include "HH_ListenEvent.h"

hhou::HHListenEvent::HHListenEvent(HHPoller *poller,
                                   const string &addr,
                                   const port_t &port)
        : m_pPoller(poller),
          m_connectionNum(0),
          m_strAddr(addr),
          m_port(port),
          flag(HHFast)
{
    cout << "Init ListenEvent" << endl;
}

SOCKET hhou::HHListenEvent::Init()
{
    sockaddr_in listenAddr;
#ifdef IPPROTO_IPV6
    handler = socket(AF_INET6, SOCK_STREAM, 0);
    listenAddr.sin_family = AF_INET6;
#eli
    handler = socket(AF_INET, SOCK_STREAM, 0);
    listenAddr.sin_family = AF_INET;
#endif
    if (!NonBlock(true))
    {
        cout << "NonBlock error, errno:" << errno << endl;
        return INVALID_SOCKET;
    }
    if (!Reuse(true))
    {
        cout << "Reuse error, errno:" << errno << endl;
        return INVALID_SOCKET;
    }
    listenAddr.sin_addr.s_addr = htonl(m_strAddr);
    listenAddr.sin_port = htons(m_port);
    if (bind(handler, &listenAddr, sizeof(listenAddr)) == -1)
    {
        cout << "bind error, errno:" << errno << endl;
        return INVALID_SOCKET;
    }
    if(-1 == listen(handler, Poller_MAX_FD))
    {
        cout << "listen error, errno:" << errno << endl;
        return INVALID_SOCKET;
    }
    return handler;
}

void hhou::HHListenEvent::OnConneting()
{

}