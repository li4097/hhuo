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
#include "parser/HH_Parse.h"
#include "HH_Log.h"

hhou::HHFDEvent::HHFDEvent(HHPoller *poller, size_t bufSize)
        : m_nTotalRecv(0),
          m_nTotalSend(0),
          m_pPoller(poller),
          m_bufIn(bufSize),
          m_bufOut(bufSize)
{
    LOG(INFO) << "create new fdEvent";
}

hhou::HHFDEvent::~HHFDEvent()
{

}

void hhou::HHFDEvent::OnRead()
{
    size_t n = m_bufIn.Space();
    ssize_t rSize = 0;
    do
    {
        char bufIn[TCP_BUFSIZE] = {0};
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
            OnClosed();
        }
        else
        {
            if(nRet == SSL_ERROR_NONE)
            {
                /// 拿出读到的数据
                m_nTotalRecv += rSize;
                m_bufIn.Write(bufIn, (size_t)rSize);
                hhou::HHParse *parse = hhou::HHParserMgr::Instance().GetParser(handler);
                if (parse != nullptr)
                {
                    char bufOut[TCP_BUFSIZE];
                    parse->ParseData(eventInfo.once, m_bufIn.GetStart(), (int)m_bufIn.GetLength(), bufOut, TCP_BUFSIZE);
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
        }
#else
        rSize = recv(handler, bufIn, (n < TCP_BUFSIZE) ? n - 1 : TCP_BUFSIZE - 1, 0);
        if (rSize <= 0)
        {
            if(errno == EAGAIN || errno == EWOULDBLOCK || errno == EINTR)
            {
                /// 需要继续读data
                continue;
            }
            OnClosed();
        }
        else
        {
            /// 拿出读到的数据
            m_nTotalRecv += rSize;
            m_bufIn.Write(bufIn, (size_t)rSize);
            hhou::HHParse *parse = hhou::HHParserMgr::Instance().GetParser(handler);
            if (parse != nullptr)
            {
                char bufOut[TCP_BUFSIZE];
                parse->ParseData(eventInfo.once, m_bufIn.GetStart(), (int)m_bufIn.GetLength(), bufOut, TCP_BUFSIZE);
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
#endif
    }while(rSize == TCP_BUFSIZE - 1);
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
                /// 需要继续写data
                continue;
            }
            OnClosed();
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
        sLength = send(handler, m_bufOut.GetStart() + (m_bufOut.GetLength() - sLength), (size_t)sLength, 0);
        if (sLength <= 0)
        {
            if(errno == EAGAIN || errno == EWOULDBLOCK || errno == EINTR)
            {
                /// 需要继续读data
                continue;
            }
            OnClosed();
        }
        else
        {
            /// 剩余的data长度
            m_nTotalSend += sLength;
            sLength = m_bufOut.GetLength() - sLength;
        }
#endif
    }while(sLength > 0);

    /// 是否是短连接
    if (eventInfo.once)
    {
        OnClosed();
    }
    else
    {
        /// 将data拷贝到发送缓冲区
        m_bufOut.Remove(m_bufOut.GetLength());
        eventInfo.status = In;
        m_pPoller->ChangeEvent(this);
    }
}

void hhou::HHFDEvent::OnTimeout()
{
    OnClosed();
}

void hhou::HHFDEvent::OnClosing()
{

}

void hhou::HHFDEvent::OnClosed()
{
#ifdef HAVE_OPENSSL
    SSL_shutdown(m_sSSL);
    SSL_free(m_sSSL);
#endif
    m_pPoller->DelEvent(this);
    closesocket(handler);
    delete this;
}