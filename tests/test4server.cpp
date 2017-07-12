#include "HH_ListenEvent.h"
#include "HH_EventLoop.h"
#include "HH_ServerBase.h"
#include "HH_Parse.h"

class Test4Parse : public hhou::HHParse
{
    virtual void ParseData(const string &strIn, string &strRet)
    {
        cout << strIn << endl;
    }
};

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
    Test4Server test;
    test.Run();
    return 0;
}