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

#include "HH_Mysql.h"

hhou::HHMysql::HHMysql()
{
    mysql_init(&m_mysql);
    cout << "Init mysql" << endl;
}

hhou::HHMysql::~HHMysql()
{
    mysql_close(&m_mysql);
}

bool hhou::HHMysql::ConnectDB(const string &strHost, const string &strUser, const string &strPass, const string &strDBName, const unsigned int &port)
{
    /// 设置字符
    if (mysql_options(&m_mysql, MYSQL_SET_CHARSET_NAME, "utf8"))
    {
        cout << "Set charset utf8 fail: " << mysql_error(&m_mysql) << endl;
    }

    /// 连接mysql
    if (!mysql_real_connect(&m_mysql,strHost.c_str(), strUser.c_str(), strPass.c_str(),strDBName.c_str(), port, NULL, 0))
    {
        cout << "Cannot connect to host: " << strHost << " port: " << port << " user: " << strUser << endl;
        mysql_close(&m_mysql);
        return false;
    }
    else
        cout << "Connect to mysql OK" << endl;
    return true;
}

bool hhou::HHMysql::SelectDB(const string &strDBName)
{
    if (!mysql_select_db(&m_mysql, strDBName.c_str()))
    {
        cout << "SelectDB failure" << mysql_error(&m_mysql) << endl;
        return false;
    }
    return true;
}

MYSQL_ROW hhou::HHMysql::GetRecord()
{
    return (row = mysql_fetch_row(m_pQuery));
}

bool hhou::HHMysql::SelectAll(const string &strTableName)
{
    ostringstream Ostr;
    Ostr << "select * from " << strTableName;
    return ExcuteSql(Ostr.str());
}

void hhou::HHMysql::SeekData(my_ulonglong offset)
{
    mysql_data_seek(m_pQuery, offset);
}

bool hhou::HHMysql::ExcuteSql(const string &str)
{
    if (mysql_query(&m_mysql, str.c_str()))
    {
        cout << "ExcuteSql sql: " << str << " fail: " << mysql_error(&m_mysql) << endl;
        return false;
    }
    m_pQuery = mysql_store_result(&m_mysql);
    return true;
}

bool hhou::HHMysql::DelRecord(const string &strTableName, const string &strWhere)
{
    ostringstream Ostr;
    Ostr << "delete from " << strTableName << " where " << strWhere;
    return mysql_query(&m_mysql, Ostr.str().c_str()) > 0;
}

bool hhou::HHMysql::InsertRecord(const string &strTableName, const string &strVal)
{
    ostringstream Ostr;
    Ostr << "insert into " << strTableName << " values(" << strVal << ")";
    return (bool)mysql_query(&m_mysql, Ostr.str().c_str());
}

bool hhou::HHMysql::SelectRecord(const string &strTableName, const string &strSelect, const string &strWhere)
{
    ostringstream Ostr;
    Ostr << "select " << strSelect << " from " << strTableName;
    if (strWhere.size() > 0)
        Ostr << " where " << strWhere;
    return ExcuteSql(Ostr.str());
}

bool hhou::HHMysql::UpdateRecord(const string &strTableName, const string &strVal, const string &strWhere)
{
    ostringstream Ostr;
    Ostr << "update " << strTableName << " set " << strVal;
    if (strWhere.size() > 0)
        Ostr << " where " << strWhere;
    return (bool)mysql_query(&m_mysql, Ostr.str().c_str());
}

bool hhou::HHMysql::IsEnd()
{
    return mysql_eof(m_pQuery);
}

my_ulonglong hhou::HHMysql::GetRowNum()
{
    return (mysql_num_fields(m_pQuery));
}

string hhou::HHMysql::GetFieldName(int FieldNum)
{
    m_pField = mysql_fetch_field_direct(m_pQuery, (unsigned int)FieldNum);
    return string(m_pField->name);
}