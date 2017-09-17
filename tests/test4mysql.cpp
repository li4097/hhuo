#include "../include/data/HH_Mysql.h"

int main(int argc, char *argv[])
{
    string strHost = "127.0.0.1";
    string strUse = "hhou1";
    string strPass = "hhou-1";
    string strDBName = "im";
    
    hhou::HHMysql mysql;
    /////////connect////////
    if (mysql.ConnectDB(strHost, strUse, strPass, strDBName, 3306))
    {
        ///////////excute sql////////////////
        if (mysql.SelectAll("t_user"))
        {
            cout << "SelectAll ok" << endl;

            /// 获取某一个值
            MYSQL_ROW row;
            while ((row = mysql.GetRecord()))
            {
                for (auto i = 0 ; i < mysql.GetFieldNum(); i++)
                {
                    cout << "key: " << mysql.GetFieldName(i) << ", value:" << row[i] << endl;
                }
            }            
        }
    }
    return 0;
}