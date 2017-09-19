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

#include <memory>
#include "../../include/HH_Common.h"
#include "../../include/net/HH_ListenEvent.h"
#include "../../include/net/HH_Poller.h"
#include "../../include/net/HH_FDEvent.h"
#include "../../include/parser/HH_Parse.h"
#include "../../include/HH_Log.h"

hhou::HHListenEvent::HHListenEvent(shared_ptr<HHPoller> poller)
        : m_Poller(poller)
{
    eventInfo.flags = HHFast;
    LOG(INFO) << "Init ListenEvent";
}

hhou::HHListenEvent::~HHListenEvent()
{
    closesocket(handler);
#ifdef HAVE_OPENSSL
    SSL_CTX_free(m_sCtx);
    BIO_free(m_errBio);
#endif
}

#ifdef HAVE_OPENSSL
    bool hhou::HHListenEvent::Init(const string &strCert, const string &strKey)
    {
        if (strCert.empty() || strKey.empty())
        {
            LOG(ERROR) << "SSL certificate is empty";
            return false;
        }
        LOG(INFO) << "SSL cert: " << strCert << " , key: " << strKey;
        SSL_load_error_strings(); /// 加载SSL错误信息
        if (!SSL_library_init()) /// 初始化ssl
        {
            LOG(ERROR) << "SSL_library_init failed";
            return false;
        }
        m_sCtx = SSL_CTX_new(SSLv23_method());
        if (!m_sCtx)
        {
            LOG(ERROR) << "SSL_CTX_new failed";
            return false;
        }
        m_errBio = BIO_new_fd(2, BIO_NOCLOSE);
        if (SSL_CTX_use_certificate_file(m_sCtx, strCert.c_str(), SSL_FILETYPE_PEM) < 0)
        {
            LOG(ERROR) << "SSL_CTX_use_certificate_file failed";
            return false;
        }
        if (SSL_CTX_use_PrivateKey_file(m_sCtx, strKey.c_str(), SSL_FILETYPE_PEM) < 0)
        {
            LOG(ERROR) << "SSL_CTX_use_PrivateKey_file failed";
            return false;
        }
        if (SSL_CTX_check_private_key(m_sCtx) < 0)
        {
            LOG(ERROR) << "SSL_CTX_check_private_key failed";
            return false;
        }
        LOG(INFO) << "Init ssl ListenEvent";
        return true;
    }
#else
    bool hhou::HHListenEvent::Init()
    {
        return true;
    }
#endif

bool hhou::HHListenEvent::Listen(const string &addr, const port_t &port, int listenFds)
{
    struct sockaddr_in listenAddr;
    memset(&listenAddr, 0, sizeof(listenAddr));
    handler = socket(AF_INET, SOCK_STREAM, 0);
    if (!NonBlock(true))
    {
        LOG(ERROR) << "NonBlock error, errno:" << errno;
        return false;
    }
    if (!Reuse(true))
    {
        LOG(ERROR) << "Reuse error, errno:" << errno;
        return false;
    }
	if (!ReusePort(true))
    {
        LOG(ERROR) << "ReusePort error, errno:" << errno;
        return false;
    }
    listenAddr.sin_family = AF_INET;
    listenAddr.sin_addr.s_addr = inet_addr(addr.c_str());
    listenAddr.sin_port = htons(port);
    if (bind(handler, (struct sockaddr *)&listenAddr, sizeof(listenAddr)) == -1)
    {
        LOG(ERROR) << "bind error, errno:" << errno;
        return false;
    }
    if(listen(handler, listenFds) == -1)
    {
        LOG(ERROR) << "listen error, errno:" << errno;
        return false;
    }

    /// 添加到epoll的监控中
    {
        eventInfo.status = In;
        eventInfo.flags = HHFast;
        eventInfo.nType = 0;
        m_Poller->AddEvent(this);
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
        auto pNew = new HHFDEvent(m_Poller);
        pNew->handler = (SOCKET)fd;
        pNew->eventInfo.status = In;
        pNew->eventInfo.flags = HHQueue;
        pNew->eventInfo.nType = 1;
        pNew->NonBlock(true);
        /// 设置解析器
        auto parser = HHParserMgr::Instance().GetParser(fd);
        pNew->SetRecvCallBack(bind(&HHParse::ParseData, parser, _1, _2));
        pNew->SetSendCallBack(bind(&HHParse::SendData, parser, _1, _2));
#ifdef SHORT_CONN
        pNew->KeepAlive(false);
#else
        pNew->KeepAlive(true);
#endif
        pNew->SetIpAndPort(raddr.sin_addr.s_addr, raddr.sin_port);
#ifdef HAVE_OPENSSL
        /// 基于ctx产生一个新的SSL
        pNew->m_sSSL = SSL_new(m_sCtx);
        /// 将连接用户的socket加入到SSL
        SSL_set_fd(pNew->m_sSSL, pNew->handler);

        /// 建立SSL连接
        bool bConnected = true;
        int nError = -1;
        while(SSL_accept(pNew->m_sSSL) != 1)
        {
            if (SSL_get_error(pNew->m_sSSL, nError) != SSL_ERROR_WANT_READ)
            {
                bConnected = false;
                break;
            }
        }
        if (!bConnected)
        {
            LOG(ERROR) << "Create ssl connection with " << pNew->handler << " ,error: " << nError;
            SSL_CTX_free(m_sCtx);
            m_sCtx = nullptr;
            delete pNew;
            pNew = nullptr;
        }
#endif
        m_Poller->AddEvent(pNew);
    }
}
