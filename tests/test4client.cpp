#include "../include/net/HH_ClientBase.h"
#include "../include/HH_Log.h"

int main(int argc, char *argv[])
{
    hhou::HHClientBase client;
    if (client.Connect("127.0.0.1", 9999))
    {
        LOG(INFO) << "OK";
        string strData = "shit";
        client.Send(strData);
    }
    else
    {
        LOG(INFO) << "Fail";
    }
    while (true);
    return 0;
}
