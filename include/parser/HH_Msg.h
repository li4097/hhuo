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
#ifndef HH_MSG_H
#define HH_MSG_H

#include "HH_Common.h"

namespace hhou
{
    /**
     * 消息的类
     * nID:消息的ID
     * nOp:消息的类型
     * ......
     * strMsg:消息体
     */
    class HHMsg
    {
    public:
        HHMsg(int &nID, int &nOp, const string &strMsg) 
            : m_nID(nID), m_nOp(nOp), m_strMsg(move(strMsg))
        {}
        virtual ~HHMsg() {}

        /**
         * 追加消息体（每块接收）
         */
        void Append(const string &strMsg) { m_strMsg.append(move(strMsg)); }

        /**
         * 执行处理
         */
        int Process();

    private:
        /**websocket的处理*/
        int WSProcess();

        /**自定义协议的处理*/
        int CMProcess();

    private:
        int m_nID;  /// 消息的ID
        int m_nOp;  /// 消息的类型
        string m_strMsg;    /// 消息体
        string m_strRet;    /// 等着返回的消息体
    };
}

#endif //HH_MSG_H
