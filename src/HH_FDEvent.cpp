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
#include "HH_Parse.h"

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
    size_t n = m_bufIn.Space();
    char buf[TCP_BUFSIZE];

    ssize_t rSize = 0;
    do
    {
        rSize = recv(handler, buf, (n < TCP_BUFSIZE) ? n : TCP_BUFSIZE, MSG_DONTWAIT);
        if (rSize <= 0)
        {
            if(errno == EAGAIN || errno == EWOULDBLOCK || errno == EINTR)
            {
                /// 需要继续读data
                continue;
            }
            else
            {
                /// 对端已经关闭socket
                OnClosed();
            }
        }
        else
        {
            /// 拿出读到的数据
            m_bufIn.Write(buf, (size_t)rSize);
            string strIn, strOut;
            HHParse parse;
            strIn = m_bufIn.GetStart();
            parse.ParseData(strIn, strOut);
            if (strOut.length() > 0)
            {
                eventInfo.status = Out;
                m_pPoller->ChangeEvent(this);
            }
            m_bufIn.Remove((size_t)rSize);
        }
        /// 判断是否还有后续的data
        rSize = (rSize == TCP_BUFSIZE) ? 1 : 0;
    }while(rSize);
}

void hhou::HHFDEvent::OnWrite()
{
    ssize_t sLength = m_bufOut.GetLength();
    do
    {
        sLength = send(handler, m_bufOut.GetStart() + (m_bufOut.GetLength() - sLength), (size_t)sLength, MSG_DONTWAIT);
        if (sLength <= 0)
        {
            if(errno == EAGAIN || errno == EWOULDBLOCK || errno == EINTR)
            {
                /// 需要继续读data
                continue;
            }
            else
            {
                /// 关闭socket
                OnClosed();
            }
        }
        else
        {
            /// 剩余的data长度
            sLength = m_bufOut.GetLength() - sLength;
        }
    }while(sLength > 0);

    /// 将data拷贝到发送缓冲区
    m_bufOut.Remove(m_bufOut.GetLength());
    eventInfo.status = In;
    m_pPoller->ChangeEvent(this);
}

void hhou::HHFDEvent::OnTimeout()
{
    OnClosed();
}

void hhou::HHFDEvent::OnClosed()
{
    eventInfo.status = Close;
    m_pPoller->DelEvent(this);
    m_pPoller->UpdateConnNums(-1);
    closesocket(handler);
    delete this;
}