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

#ifndef HH_MYSQL_H
#define HH_MYSQL_H

#include <mysql/mysql.h>
#include <sstream>
#include "../HH_Common.h"

namespace hhou
{
    /**
    This is a C++ incapsulation of the mysql C API
    In order to use this:
    1.set the project include directory includes the include directory under mysql directory
    2.set the project library directory includes the lib/opt directory under mysql directory
    3.set the addtional dependency of the linker of the project 'libmysql.lib'
    After all of the above work, you can simply add this CMysql class in your project,and can conviently use it
    If you find any bugs, please connect me : loveyou12300liumao@163.com
    */
    class HHMysql
    {
    public:
        /**
         * 默认构造函数
         */
        HHMysql();
        virtual ~HHMysql();

        /**
         * 字段操作
         */
        unsigned int GetFieldNum();
        string GetFieldName(int FieldNum);

        /**
         * 是否最后
         */
        bool IsEnd();

        /**
         * 查找指定数据
         */
        void SeekData(my_ulonglong offset);

        /**
         * 连接mysql
         */
        bool ConnectDB(const string &strHost, const string &strUser, const string &strPass, const string &strDBName, const unsigned int &port);

        /**
         * 选择数据库名称
         */
        bool SelectDB(const string &strDBName);

        /**
         * 得到结果（一个记录）
         */
        MYSQL_ROW GetRecord();

        /**
         * 得到记录数
         */
        my_ulonglong GetRowNum();

        /**
         * 更新记录(其实这样并不能满足需求)
         */
        bool UpdateRecord(const string &strTableName, const string &strVal, const string &strWhere = "");

        /**
         * 选择记录
         */
        bool SelectRecord(const string &strTableName, const string &strSelect, const string &strWhere = "");

        /**
         * 插入记录
         */
        bool InsertRecord(const string &strTableName, const string &strVal);

        /**
        * 删除记录
        */
        bool DelRecord(const string &strTableName, const string &strWhere);

        /**
        * 选择所有记录
        */
        bool SelectAll(const string &strTableName);

        /**
         * 执行sql语句
         */
        bool ExcuteSql(const string &str);

    private:
        MYSQL m_mysql; /// 数据库链接句柄
        MYSQL_FIELD *m_pField; /// 字段信息（结构体）

    public:
        MYSQL_RES *m_pQuery; /// 结果集
        MYSQL_ROW row; /// 记录集
    };
}

#endif // HH_MYSQL_H