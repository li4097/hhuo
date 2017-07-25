#include "../include/net/HH_ListenEvent.h"
#include "../include/net/HH_EventLoop.h"
#include "../include/net/HH_ServerBase.h"
#include "../include/parser/HH_Parse.h"
#include "../include/HH_Log.h"
#include "../app/ImgProcessor.h"

int DealData(void *first, int nFisrtLen, void *second)
{
    ImgProcessor processor;
    return processor.Processor(first, nFisrtLen, second);
}

class Test4Server : public hhou::HHServerBase
{
public:
    Test4Server()
    {
        SetCallBack(DealData);
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
        if (pListen->Listen("0.0.0.0", 9999))
        {
            LOG(INFO) << "Server Listen Addr: 0.0.0.0, port: 9999";
        }
        pLoop->Loop(500);
    }
};

int main(int argc, char *argv[])
{
    hhou::HHLog log("../log", true);
    Test4Server test;
    test.Run();
    return 0;
}