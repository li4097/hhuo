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

#include <glog/logging.h>
#include "HH_Common.h"

#ifndef HH_LOG_H
#define HH_LOG_H

namespace hhou
{
    /**
     * 日志管理类
     */
    class HHLog
    {
    public:
        /**
         * 默认构造函数
         */
        HHLog(const string &strDir, bool bStdErr = false, const int nLevel = 0 /**0=info,1=warning,2=error,3=fatal*/)
        {
            if (access(strDir.c_str(), 0) == -1)
            {
                int flag = mkdir(strDir.c_str(), 0777);
                if (flag != 0)
                {
                    cout << "Create log dir: " << strDir << " error" << endl;
                    exit(0);
                }
            }

            /// 初始化glog
            google::InitGoogleLogging("");
            google::SetLogDestination(google::GLOG_FATAL, strDir + "/Fatal_");
            google::SetLogDestination(google::GLOG_ERROR, strDir + "/Error_");
            google::SetLogDestination(google::GLOG_WARNING, strDir + "/Warning_");
            google::SetLogDestination(google::GLOG_INFO, strDir + "/Info_");

            /// 配置glog
            FLAGS_logtostderr = bStdErr; /// 是否将所有日志输出到stderr而非文件
            FLAGS_alsologtostderr = bStdErr;/// 是否将所有日志输出到文件和stderr
            FLAGS_minloglevel = nLevel; /// 记录的最小级别
            FLAGS_logbufsecs = 10; /// 缓冲日志输出，默认30秒
            FLAGS_max_log_size = 10; /// 日志文件最大尺寸
            FLAGS_stop_logging_if_full_disk = true; /// 当磁盘写满时停止日志输出
        }

        virtual ~HHLog()
        {
            /// 释放google
            google::ShutdownGoogleLogging();
        }
    };
}

#endif // HH_LOG_H