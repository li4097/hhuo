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
        HHMsg(int nID, int nOp, bool bCompleted = false, const string &strMsg = "")
                : m_nID(nID), m_nOp(nOp), m_bCompleted(bCompleted), m_strMsg(move(strMsg)) {}
        virtual ~HHMsg() {}

    public:
        int m_nID;  /// 消息的ID
        int m_nOp;  /// 消息的类型
        bool m_bCompleted;  /// 是否是完整包
        string m_strMsg;    /// 消息体
    };
}

#endif //HH_MSG_H
