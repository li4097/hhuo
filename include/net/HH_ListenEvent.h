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
        HHListenEvent(shared_ptr<HHPoller> poller);
        virtual ~HHListenEvent();

        /**初始化*/
        bool Init(const string &strCert = "", const string &strKey = "");

        /**监听接口(包括bind的动作)*/
        bool Listen(const string &addr, const port_t &port, int listenFds = 8096);

        /**
         * 连接的处理
         */
        void OnConneting();

    private:
        shared_ptr<HHPoller> m_Poller; /// poller对象
#ifdef HAVE_OPENSSL
        SSL_CTX *m_sCtx;
        BIO* m_errBio;
#endif
    };
}
#endif // HHUO_HHLISTENEVENT_H