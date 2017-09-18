#include "../include/data/HH_Redis.h"
#include "../include/HH_Log.h"

int main(int argc, char *argv[])
{
    hhou::HHRedis redis;
    string strHost = "127.0.0.1";
    struct timeval timeout = {2, 0};
    if (redis.ConnectToRedis(strHost, 6379, timeout))
    {
        LOG(INFO) << "Connected OK";
        string strRet;
        redis.Excute("SET shit fuck", strRet);
        if (strRet == "OK")
            LOG(INFO) << "Set: " << strRet;
        redis.Excute("GET shit", strRet);
        LOG(INFO) << "Ret: " << strRet;
    }
    return 0;
}