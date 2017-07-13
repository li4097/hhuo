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

#include "HH_Common.h"
#include "HH_ListenEvent.h"
#include "HH_Poller.h"
#include "HH_FDEvent.h"

hhou::HHListenEvent::HHListenEvent(HHPoller *poller)
        : m_pPoller(poller)
{
    eventInfo.flags = HHFast;
    if (Init())
        cout << "Init ListenEvent" << endl;
    else
    {
        cout << "Init ListenEvent fail" << endl;
        exit(1);
    }
}

bool hhou::HHListenEvent::Init()
{
    bool bRet = true;
#ifdef HAVE_OPENSSL
    SSL_load_error_strings(); /// 加载SSL错误信息
    if (!SSL_library_init()) /// 初始化ssl
    {
        cout << "SSL_library_init failed" << endl;
        bRet = false;
    }
    m_sCtx = SSL_CTX_new(SSLv23_method());
    if (!m_sCtx)
    {
        cout << "SSL_CTX_new failed" << endl;
        bRet = false;
    }
    m_errBio = BIO_new_fd(2, BIO_NOCLOSE);
    if (SSL_CTX_use_certificate_file(m_sCtx, m_strCert.c_str(), SSL_FILETYPE_PEM) < 0)
    {
        cout << "SSL_CTX_use_certificate_file failed" << endl;
        bRet = false;
    }
    if (SSL_CTX_use_PrivateKey_file(m_sCtx, m_strKey.c_str(), SSL_FILETYPE_PEM) < 0)
    {
        cout << "SSL_CTX_use_PrivateKey_file failed" << endl;
        bRet = false;
    }
    if (SSL_CTX_check_private_key(m_sCtx) < 0)
    {
        cout << "SSL_CTX_check_private_key failed" << endl;
        bRet = false;
    }
    cout << "Init openssl ListenEvent" << endl;
#endif
    return bRet;
}

bool hhou::HHListenEvent::Listen(const string &addr, const port_t &port, size_t listenFds)
{
    struct sockaddr_in listenAddr;
    memset(&listenAddr, 0, sizeof(listenAddr));
    handler = socket(AF_INET, SOCK_STREAM, 0);
    if (!NonBlock(true))
    {
        cout << "NonBlock error, errno:" << errno << endl;
        return false;
    }
    if (!Reuse(true))
    {
        cout << "Reuse error, errno:" << errno << endl;
        return false;
    }
    listenAddr.sin_family = AF_INET;
    listenAddr.sin_addr.s_addr = inet_addr(addr.c_str());
    listenAddr.sin_port = htons(port);
    if (bind(handler, (struct sockaddr *)&listenAddr, sizeof(listenAddr)) == -1)
    {
        cout << "bind error, errno:" << errno << endl;
        return false;
    }
    if(listen(handler, listenFds) == -1)
    {
        cout << "listen error, errno:" << errno << endl;
        return false;
    }

    /// 添加到epoll的监控中
    {
        eventInfo.status = In;
        eventInfo.flags = HHFast;
        eventInfo.nType = 0;
        m_pPoller->AddEvent(this);
    }
    return true;
}

void hhou::HHListenEvent::OnConneting()
{
    struct sockaddr_in raddr;
    socklen_t rsz = sizeof(raddr);
    int fd;
    while ((fd = accept4(handler, (struct sockaddr *) &raddr, &rsz, SOCK_CLOEXEC)) >= 0)
    {
        /// 有新的connection
        HHFDEvent *pNew = new HHFDEvent(m_pPoller);
        pNew->handler = (SOCKET)fd;
        pNew->eventInfo.status = In;
        pNew->eventInfo.flags = HHQueue;
        pNew->eventInfo.nType = 1;
        pNew->NonBlock(true);
        pNew->KeepAlive(true);
#ifdef HAVE_OPENSSL
        /// 基于ctx产生一个新的SSL
        pNew->m_sSSL = ssl_new(m_sCtx);
        /// 将连接用户的socket加入到SSL
        SSL_set_fd(pNew->m_sSSL, pNew->handler);
        /// 建立SSL连接
        if (SSL_accept(pNew->m_sSSL) == -1)
        {
            cout << "Create openssl connection with " << pNew->handler << " fail" << endl;
        }
#endif
        m_pPoller->AddEvent(pNew);
        m_pPoller->UpdateConnNums(1);
    }
}