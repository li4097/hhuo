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

#ifndef HH_COMMON_H
#define HH_COMMON_H

#if (defined(__unix__) || defined(unix)) && !defined(USG)
#include <sys/param.h>
#endif

// -----------------------------------
// 输入输出函数必须包含
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;

#ifndef _WIN32
// ----------------------------------------
// common unix includes / defines
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#define Errno errno

// 统一成WIN32的用法
#define closesocket close
#define INVALID_SOCKET -1
#define SOCKET_ERROR -1
typedef int SOCKET;

#ifndef INADDR_NONE
#define INADDR_NONE ((unsigned long) -1)
#endif // INADDR_NONE
#endif // _WIN32

// ----------------------------------------
// Generic
#ifndef SOL_IP
#define SOL_IP IPPROTO_IP
#endif

// ----------------------------------------
// 系统判断适配

#ifdef SOLARIS
// ----------------------------------------
// Solaris
typedef unsigned short port_t;
#define s6_addr16 _S6_un._S6_u8
#define MSG_NOSIGNAL 0

#elif defined __FreeBSD__
// ----------------------------------------
// FreeBSD
# if __FreeBSD_version >= 400014
#  define s6_addr16 __u6_addr.__u6_addr16
#  if !defined(MSG_NOSIGNAL)
#   define MSG_NOSIGNAL 0
#  endif
#  include <netinet/in.h>
typedef	in_addr_t ipaddr_t;
typedef	in_port_t port_t;
#  define IPV6_ADD_MEMBERSHIP IPV6_JOIN_GROUP
#  define IPV6_DROP_MEMBERSHIP IPV6_LEAVE_GROUP
# else
#  error FreeBSD versions prior to 400014 does not support ipv6
# endif

#elif defined MACOSX
// ----------------------------------------
// Mac OS X
#include <string.h>
#include <mach/port.h>
typedef unsigned long ipaddr_t;
#define s6_addr16 __u6_addr.__u6_addr16
#define MSG_NOSIGNAL 0 // oops - thanks Derek
#define IPV6_ADD_MEMBERSHIP IPV6_JOIN_GROUP
#define IPV6_DROP_MEMBERSHIP IPV6_LEAVE_GROUP

#elif defined _WIN32
// ----------------------------------------
// Win32
#pragma comment(lib, "wsock32.lib")
typedef unsigned long ipaddr_t;
typedef unsigned short port_t;
typedef int socklen_t;
#define MSG_NOSIGNAL 0
#define SHUT_RDWR 2
#include <winsock.h>
#define Errno WSAGetLastError()

#else
// ----------------------------------------
// LINUX
typedef unsigned long ipaddr_t;
typedef unsigned short port_t;
#endif

// ----------------------------
// SSL
#ifdef HAVE_OPENSSL
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <openssl/bio.h>
#endif // HAVE_OPENSSL

// socket的初始化
class SocketInitializer
{
public:
    SocketInitializer()
    {
#ifdef _WIN32
        if (WSAStartup(0x101, &m_wsadata))
        {
            exit(-1);
        }
#endif
    }

    ~SocketInitializer()
    {
#ifdef _WIN32
        WSACleanup();
#endif
    }

private:
#ifdef _WIN32
    WSADATA m_wsadata;
#endif
};

/**都是放到配置文件中的*/
enum
{
    /**poller最大监听的fd数量*/
    #define Poller_MAX_FD 8096

    /**poller最大事件数量*/
    #define Poller_MAX_EVENT 1024

    /**默认最大超时时间(单位：s)*/
    #define TIMEOUT 60

    /**开启线程的默认值*/
    #define THREAD_NUM 10

    /**event数据的默认值*/
    #define CIRCULAR_BUFFSIZE 80960
    #define TCP_BUFSIZE 8096

    /**mysql cfg*/
    #define HOST "127.0.0.1"
    #define PORT 3306
    #define USER "test"
    #define PASSWORD "1234"
    #define DBNAME "test"
};

/**事件的类型，0--紧急处理，1--队列中等候被处理*/
enum HHEventFlags
{
    HHQueue = 0,
    HHFast
};

/**状态的类型，0--in，1--out, 2--close*/
enum HHEventStatus
{
    In = 0,
    Out,
    Close
};

/**SOCKET的基本信息*/
struct HHEventInfo
{
    HHEventFlags flags;
    HHEventStatus status;
    int nType; /// 0--listenfd,1--commonfd
};

#endif //HH_COMMON_H