//
// Created by hhou on 17-9-25.
//

#include "../include/Im.h"
#include "HH_Log.h"

Im::Im() : m_bLogin(false)
{
    /// 初始化连接mysql
    string strHost = hhou::HHConfig::Instance().ReadStr("mysql", "host", "127.0.0.1");
    int port = hhou::HHConfig::Instance().ReadInt("mysql", "port", 3306);
    string strUser = hhou::HHConfig::Instance().ReadStr("mysql", "user", "");
    string strPass = hhou::HHConfig::Instance().ReadStr("mysql", "passwd", "");
    if (!m_mysql.ConnectDB(strHost, strUser, strPass, "im", port))
    {
        LOG(ERROR) << "Connect mysql host: " << strHost << ",port " << port << ",user " << strUser << " fail.";
    }
}

bool Im::Register(const string &strUser, const string &strNickName, const string &strPass, const string &strDesc)
{
    if (strUser.empty() || strPass.empty()) 
    {
        LOG(ERROR) << "Register User or pass is empty!";
        return false;
    }
    ostringstream os;
    os << "insert into t_user(f_name,f_nickname,f_pass,f_desc) values ('";
    os << strUser << "','";
    os << strNickName << "','";
    os << strPass << "','";
    os << strDesc << "');";
    return m_mysql.ExcuteSql(os.str());
}

bool Im::Login(const string &strUser, const string &strPass, string &strResult)
{
    if (strUser.empty() || strPass.empty()) 
    {
        LOG(ERROR) << "Login User or pass is empty!";
        return false;
    }
    ostringstream os;
    os << "select f_nickname,f_desc from t_user where f_name='" << strUser << "' and f_pass='" << strPass << "';";
    if (m_mysql.ExcuteSql(os.str()))
    {
        MYSQL_ROW row = m_mysql.GetRecord();
        string strNickName = row[0];
        string strDesc = row[1];
    }
    return true;
}

bool Im::GetFriends(const string &strToken, string &strResult)
{
    return true;
}

bool Im::GetOfflineMsg(string &strResult)
{
    return true;
}