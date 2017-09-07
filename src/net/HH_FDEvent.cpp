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
#include "HH_Log.h"

hhou::HHFDEvent::HHFDEvent(shared_ptr<HHPoller> poller, size_t bufSize)
        : m_nTotalRecv(0),
          m_nTotalSend(0),
          m_Poller(poller),
          m_bufIn(bufSize),
          m_bufOut(bufSize),
          m_recvProc(nullptr)
{
    
}

hhou::HHFDEvent::~HHFDEvent()
{

}

void hhou::HHFDEvent::OnRead()
{
    size_t n = m_bufIn.Space();
    ssize_t rSize = 0;
    while (true)
    {
        char bufIn[TCP_BUFSIZE] = {0};
#ifdef HAVE_OPENSSL
        rSize = SSL_read(m_sSSL, bufIn, (n < TCP_BUFSIZE) ? n - 1 : TCP_BUFSIZE - 1);
        int nRet = SSL_get_error(m_sSSL, rSize);
        if (nRet == SSL_ERROR_NONE)
        {
            /// 接受成功
        }
        else if (nRet == SSL_ERROR_WANT_READ)
        {
            continue;
        }
        else
        {
            eventInfo.status = Close;
        }
#else
        rSize = recv(handler, bufIn, (n < TCP_BUFSIZE) ? n - 1 : TCP_BUFSIZE - 1, 0);
        if (rSize < 0)
        {
            if(errno == EAGAIN || errno == EINTR || errno == EWOULDBLOCK)
            {
                /// 需要继续读data
                continue;
            }
            eventInfo.status = Close;
        }
        else if (rSize == 0)
        {
            eventInfo.status = Close;
        }
#endif
        if (eventInfo.status == Close)
        {            
            OnClosing();
            break;
        }
        m_nTotalRecv += rSize;

        /// 是否还有空间接收data(解析数据)
        if ((size_t)rSize > m_bufIn.Space())
        {
            if (!m_recvProc(eventInfo.once, m_bufIn.GetStart(), (int)m_bufIn.GetLength()))
			{
				OnClosing();
				break;
			}
            m_bufIn.Remove(m_bufIn.GetLength());
        }
        m_bufIn.Write(bufIn, (size_t)rSize);
        if (rSize != TCP_BUFSIZE - 1) break;
    }

    /// 最后一块的data解析
    if (!m_recvProc(eventInfo.once, m_bufIn.GetStart(), (int)m_bufIn.GetLength()))
	{
		OnClosing();
		return;
	}
    m_bufIn.Remove(m_bufIn.GetLength());
    
    /// 是否有数据发送
    string strRet;
    m_sendProc(strRet, (int)m_bufOut.Space());
    if (!strRet.empty())
    {
        m_bufOut.Write(strRet.c_str(), strRet.length());
        eventInfo.status = Out;
        m_Poller->ChangeEvent(this);
    }
}

void hhou::HHFDEvent::OnWrite()
{
    ssize_t sLength = m_bufOut.GetLength();
    while (true)
    {
#ifdef HAVE_OPENSSL
        sLength = SSL_write(m_sSSL, m_bufOut.GetStart() + (m_bufOut.GetLength() - sLength), (size_t)sLength);
        int nRet = SSL_get_error(m_sSSL, sLength);
        if(nRet == SSL_ERROR_NONE)
        {
            /// 发送成功
        }
        else if (nRet == SSL_ERROR_WANT_WRITE)
        {
            continue;
        }
        else
        {
            eventInfo.status = Close;
        }
#else
        sLength = send(handler, m_bufOut.GetStart() + (m_bufOut.GetLength() - sLength), (size_t)sLength, 0);
        if (sLength < 0)
        {
            if(errno == EAGAIN || errno == EINTR || errno == EWOULDBLOCK)
            {
                /// 需要继续读data
                continue;
            }
            eventInfo.status = Close;
        }
#endif
        if (eventInfo.status == Close)
        {
            OnClosing();
            break;
        }
        m_nTotalSend += sLength;
        m_bufOut.Remove((size_t)sLength);
        sLength = m_bufOut.GetLength() - sLength;
        if (sLength > 0) continue;

        /// 是否还有数据发送
        string strRet;
        m_sendProc(strRet, (int)m_bufOut.Space());
        if (!strRet.empty())
        {
            m_bufOut.Write(strRet.c_str(), strRet.length());
            continue;
        }

        /// 是否是短连接
        if (eventInfo.once)
        {
            OnClosing();
        }
        else
        {
            /// 将data拷贝到发送缓冲区
            eventInfo.status = In;
            m_Poller->ChangeEvent(this);
        }
        break;
    }
}

void hhou::HHFDEvent::OnTimeout()
{
    if (eventInfo.status != Close)
    {  
        OnClosing();
    }
    OnClosed();
}

void hhou::HHFDEvent::OnClosing()
{
    m_Poller->DelEvent(this);
#ifdef HAVE_OPENSSL
    SSL_shutdown(m_sSSL);
    SSL_free(m_sSSL);
#endif
    closesocket(handler);
}

void hhou::HHFDEvent::OnClosed()
{
    delete this;
}
