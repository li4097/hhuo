#include "../include/net/HH_ListenEvent.h"
#include "../include/net/HH_EventLoop.h"
#include "../include/net/HH_ServerBase.h"
#include "../include/parser/HH_Parse.h"
#include "../include/HH_Log.h"

int shit(void *one, int len, void *two)
{
    cout << "::one " << (char *)one << " len: " << len << " ::two" << (char *)two << endl;
    return 1;
}

class Test4Server : public hhou::HHServerBase
{
public:
    Test4Server()
    {
        SetCallBack(shit);
    }

    ~Test4Server()
    {

    }

    bool Init()
    {
        return true;
    }

    void Run()
    {
        hhou::HHEventLoop *pLoop = new hhou::HHEventLoop();
        hhou::HHListenEvent *pListen = new hhou::HHListenEvent(pLoop->Poller());
        pListen->Listen("0.0.0.0", 9999);
        pLoop->Loop(500);
    }
};


int main(int argc, char *argv[])
{
    hhou::HHLog log("../log");
    Test4Server test;
    test.Run();
    return 0;
}