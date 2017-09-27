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

#ifndef HH_CLIENTBASE_H
#define HH_CLIENTBASE_H

#include "../HH_Common.h"
#include "../HH_Log.h"

namespace hhou
{
    /**
     * client的基类
     * 阻塞类型
     * 后续添加新的服务继承自即可
     */
    class HHClientBase
    {
    public:
        HHClientBase() {}
        virtual ~HHClientBase() {}
        
        /**连接server*/
        bool Connect(const string &strHost, const int nPort)
        {
            m_handler = socket(AF_INET, SOCK_STREAM, 0);
            if(m_handler < 0)
            {
                LOG(ERROR) << "Connect socket error."; 
                return false;
            }
            struct sockaddr_in ser_addr; 
            memset(&ser_addr, 0, sizeof(ser_addr)); 
            ser_addr.sin_family = AF_INET;  
            inet_aton(strHost.c_str(), (struct in_addr *)&ser_addr.sin_addr);
            ser_addr.sin_port = htons(nPort);
            if(connect(m_handler, (struct sockaddr *)&ser_addr, sizeof(ser_addr)) < 0)  
            {  
                LOG(ERROR) << "Connect to " << strHost << ", port " << nPort << " error."; 
                return false;
            }  
            return true;
        }

        /**recv*/
        bool Recv(char *buf, int nLen)
        {
            int rLen = recv(m_handler, buf, nLen, 0); 
            if (rLen <= 0)
            {
                LOG(ERROR) << "Connection closed.";
                closesocket(m_handler);
                return false;
            }
            return true;
        } 

        /**send*/
        bool Send(const string &strData)
        {
            ssize_t sLength = strData.length();
            while (true)
            {
                sLength = send(m_handler, strData.c_str() + (strData.length() - sLength), (size_t)sLength, 0);
                if (sLength <= 0)
                {
                    LOG(ERROR) << "Connection closed.";
                    closesocket(m_handler);
                    return false;
                }
                sLength = strData.length() - sLength;
                if (sLength <= 0) break;
            }
            return true;
        }

    private:
        SOCKET m_handler;  /// 句柄对象
    };
}

#endif //HH_CLIENTBASE_H