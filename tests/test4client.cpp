#include "../include/net/HH_ClientBase.h"
#include "../include/HH_Log.h"

int main(int argc, char *argv[])
{
    hhou::HHClientBase client;
    if (client.Connect("127.0.0.1", 9999))
    {
        LOG(INFO) << "OK";
    }
    else
    {
        LOG(INFO) << "Fail";
    }
    return 0;
}
