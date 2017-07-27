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
#include "HH_Log.h"

hhou::HHFDEvent::HHFDEvent(HHPoller *poller, size_t bufSize)
        : m_pPoller(poller),
          m_bufIn(*this, bufSize),
          m_bufOut(*this, bufSize)
{
    LOG(INFO) << "create new fdEvent";
}

hhou::HHFDEvent::~HHFDEvent()
{

}

void hhou::HHFDEvent::OnRead()
{
    size_t n = m_bufIn.Space();
    char bufIn[TCP_BUFSIZE];

    ssize_t rSize = 0;
    do
    {
#ifdef HAVE_OPENSSL
        rSize = SSL_read(m_sSSL, bufIn, (n < TCP_BUFSIZE) ? n - 1 : TCP_BUFSIZE - 1);
        int nRet = SSL_get_error(m_sSSL, rSize);
        if (rSize <= 0)
        {
            if (nRet == SSL_ERROR_WANT_READ)
            {
                /// 需要继续读data
                continue;
            }
            else
            {
                /// 对端已经关闭ssl
                OnClosed();
            }
        }
        else
        {
            if(nRet == SSL_ERROR_NONE)
            {
                /// 拿出读到的数据
                m_bufIn.Write(bufIn, (size_t)rSize);
                hhou::HHParse parse;
                char bufOut[TCP_BUFSIZE];
                parse.ParseData(m_bufIn.GetStart(), m_bufIn.GetLength(), bufOut);
                m_bufOut.Write(bufOut, strlen(bufOut));
                if (m_bufOut.GetStart() > 0)
                {
                    eventInfo.status = Out;
                    m_pPoller->ChangeEvent(this);
                }
                m_bufIn.Remove((size_t)rSize);
            }
        }
#else
        rSize = recv(handler, bufIn, (n < TCP_BUFSIZE) ? n - 1 : TCP_BUFSIZE - 1, MSG_DONTWAIT);
        if (rSize <= 0)
        {
            if(errno == EAGAIN || errno == EWOULDBLOCK || errno == EINTR)
            {
                /// 需要继续读data
                continue;
            }
            /// 对端已经关闭socket
            OnClosed();
        }
        else
        {
            /// 拿出读到的数据
            m_bufIn.Write(bufIn, (size_t)rSize);
            {
                /// TODO
                /// 添加解析器的管理器
                /// 因为client存在分段传输数据的情况
                /// 多线程的情况下，解析管理器需要加锁机制
                hhou::HHParse *parse = hhou::HHParse::Instance().GetParser(handler);
                char bufOut[TCP_BUFSIZE];
                parse->ParseData(m_bufIn.GetStart(), (int) m_bufIn.GetLength(), bufOut, TCP_BUFSIZE);
                if (parse->CanResponse())
                {
                    m_bufOut.Write(bufOut, strlen(bufOut));
                    if (m_bufOut.GetStart() > 0)
                    {
                        eventInfo.status = Out;
                        m_pPoller->ChangeEvent(this);
                    }
                }
                m_bufIn.Remove((size_t) rSize);
            }
        }
        /// 判断是否还有后续的data
        rSize = (rSize == TCP_BUFSIZE) ? 1 : 0;
#endif
    }while(rSize);
}

void hhou::HHFDEvent::OnWrite()
{
    ssize_t sLength = m_bufOut.GetLength();
    do
    {
#ifdef HAVE_OPENSSL
        sLength = SSL_write(m_sSSL, m_bufOut.GetStart() + (m_bufOut.GetLength() - sLength), (size_t)sLength);
        int nRet = SSL_get_error(m_sSSL, sLength);
        if (sLength <= 0)
        {
            if (nRet == SSL_ERROR_WANT_WRITE)
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
            if(nRet == SSL_ERROR_NONE)
            {
                /// 剩余的data长度
                sLength = m_bufOut.GetLength() - sLength;
            }
        }
#else
        sLength = send(handler, m_bufOut.GetStart() + (m_bufOut.GetLength() - sLength), (size_t)sLength, MSG_DONTWAIT);
        if (sLength <= 0)
        {
            if(errno == EAGAIN || errno == EWOULDBLOCK || errno == EINTR)
            {
                /// 需要继续读data
                continue;
            }
            /// 关闭socket
            OnClosed();
        }
        else
        {
            /// 剩余的data长度
            sLength = m_bufOut.GetLength() - sLength;
        }
#endif
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
#ifdef HAVE_OPENSSL
    SSL_shutdown(m_sSSL);
    SSL_free(m_sSSL);
#endif
    closesocket(handler);
    delete this;
}