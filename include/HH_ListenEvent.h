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

#ifndef HHUO_HHLISTENEVENT_H
#define HHUO_HHLISTENEVENT_H

#include "HH_EventBase.h"

namespace hhou
{
    class HHPoller;
    class HHFDEvent;
    /**
     * 监听对象
     */
    class HHListenEvent : public HHEventBase
    {
        friend class HHPoller;
    public:
        HHListenEvent(HHPoller *poller);

        /**初始化*/
        bool Init();

        /**监听接口(包括bind的动作)*/
        bool Listen(const string &addr, const port_t &port, size_t listenFds = Poller_MAX_FD);

        /**
         * 连接的处理
         */
        void OnConneting();

        /**
         * poller获取
         */
        HHPoller *GetPoller() { return m_pPoller; }

    private:
        HHPoller *m_pPoller; /// poller对象
        size_t m_connectionNum; /// 连接的总数

#ifdef HAVE_OPENSSL
        static SSL_CTX *m_sCtx;
        static BIO* m_errBio;
        string m_strCert;
        string m_strKey;
#endif
    };
}
#endif // HHUO_HHLISTENEVENT_H