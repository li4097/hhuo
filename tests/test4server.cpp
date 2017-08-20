#include "../include/net/HH_ListenEvent.h"
#include "../include/net/HH_EventLoop.h"
#include "../include/net/HH_ServerBase.h"
#include "../app/ImgProcessor.h"
#include "../include/HH_Log.h"

class Test4Server : public hhou::HHServerBase
{
public:
    Test4Server()
    {

    }

    ~Test4Server()
    {

    }

    bool Init()
    {
        return true;
    }

    int DealData(void *first, int nFisrtLen, void *second)
    {
        ImgProcessor processor;
        return (int)processor.Processor(first, nFisrtLen, second);
    }

    void Run()
    {
        std::shared_ptr<hhou::HHEventLoop> pLoop(new hhou::HHEventLoop());
        std::shared_ptr<hhou::HHListenEvent> pListen(new hhou::HHListenEvent(pLoop->Poller()));
        if (!pListen->Init())
            return;

        string strHost = hhou::HHConfig::Instance().ReadStr("listener", "host", "0.0.0.0");
        int port = hhou::HHConfig::Instance().ReadInt("listener", "port", 9999);
        if (pListen->Listen(strHost, port))
        {
            LOG(INFO) << "Server Listen Addr: " << strHost <<" , port: " << port;
        }
        pLoop->Loop(hhou::HHConfig::Instance().ReadInt("loop", "timeout", 60));
    }
};

int main(int argc, char *argv[])
{
    hhou::HHLog log(hhou::HHConfig::Instance().ReadStr("log", "path", "../log"), hhou::HHConfig::Instance().ReadInt("log", "tostderror", 1) == 1);
    Test4Server test;
    test.Run();
    return 0;
}