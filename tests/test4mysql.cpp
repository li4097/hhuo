#include "../include/data/HH_Mysql.h"

int main(int argc, char *argv[])
{
    string strHost = "127.0.0.1";
    string strUse = "test";
    string strPass = "1234";
    string strDBName = "test";

    hhou::HHMysql mysql;
    /////////connect////////
    if (mysql.ConnectDB(strHost, strUse, strPass, strDBName, 3306))
    {
        ///////////excute sql////////////////
        if (mysql.SelectAll("tb_test"))
        {
            cout << "SelectAll ok" << endl;
            cout << "Rows: " << mysql.GetRowNum() << endl;

            /// 获取某一个值
            auto row = mysql.GetRecord();
            cout << "one: " << row[0] << endl;
            cout << "two: " << row[1] << endl;

            row = mysql.GetRecord();
            cout << "one: " << row[0] << endl;
            cout << "two: " << row[1] << endl;
        }
    }
    return 0;
}