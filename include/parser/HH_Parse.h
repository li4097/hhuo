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
#ifndef HH_PARSE_H
#define HH_PARSE_H

#include "HH_Common.h"
#include "HH_Request.h"
#include "HH_Response.h"

namespace hhou
{
    /**
     * 应用层的处理回调
     * void *待处理包
     * int 待处理包的长度
     * void *相应包
     * */
    typedef function<int(void *, int, void *)> appDeal;

    /**
     * 解析数据的基础类
     */
    class HHParse
    {
    public:
        /**默认构造函数*/
        HHParse(appDeal appProc) : m_pDataDeal(appProc) {}
        virtual ~HHParse() {}

        /**先进行必要信息的解析(错误数据返回-1，数据不完整返回0，接收完全返回>0)*/
        void ParseData(bool bOnce, void *buf, int nLen, string &strRet);

        /**发送回调函数*/
        void SendData(string &strRet, int nSize);

        /**获取req的状态*/
        bool CanResponse() { return request.AllDone(); }

    private:
        appDeal m_pDataDeal;
        hhou::HHRequest request;  /// 加入解析的状态标志
        hhou::HHResponse response; /// 回包的对象

    };

    /**
     * 解析器的管理器
     */
    class HHParserMgr
    {
    public:
        /**默认构造函数*/
        HHParserMgr() {}
        virtual ~HHParserMgr() {}

        /**获取解析器，没有的话就给个新的*/
        hhou::HHParse *GetParser(const int fd);
        bool RmParser(const int fd);

        /**设置回调*/
        void AppCallback(appDeal appProc) {m_pDataDeal = appProc;}

        /**单例模式*/
        static HHParserMgr &Instance()
        {
            static HHParserMgr parserMgr;
            return parserMgr;
        }

    private:
        appDeal m_pDataDeal;
        mutex m_mutex; /// 锁
        map<int, HHParse *> m_mParsers;   /// fd对应的解析器
    };
}

#endif //HH_PARSE_H
