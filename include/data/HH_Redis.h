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

#ifndef HH_REDIS_H
#define HH_REDIS_H

#include <hiredis/hiredis.h>
#include "HH_Common.h"

namespace hhou
{
    /**
     * redis操作类
     */
    class HHRedis
    {
    public:
        /**
         * 默认构造函数
         */
        HHRedis();
        virtual ~HHRedis();

        /**
         * connect to redis sever
         */
        bool ConnectToRedis(const string &strHost, int nPort, struct timeval &timeout);

        /**
         * excute redis command
         */
        void Excute(const string &command, string &strRet);

    private:
        redisContext *m_pRedisConn; /// redis客户端对象
        redisReply *m_pRedisReply; /// redis具体操作

    };
}

#endif // HH_REDIS_H