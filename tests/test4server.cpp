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
		m_Loop->Stop();
    }

    bool Init()
    {
		m_Loop = make_shared<hhou::HHEventLoop>();
		m_Loop->Init(hhou::HHConfig::Instance().ReadStr("listener", "host", "0.0.0.0"), hhou::HHConfig::Instance().ReadInt("listener", "port", 9999));
        return true;
    }
	
	void Run()
	{
		m_Loop->Start();
	}

    int HttpData(void *first, int nFisrtLen, void *second)
    {
        ImgProcessor processor;
        return (int)processor.Processor(first, nFisrtLen, second);
    }

    int AppData(int nOp, void *first, int nFisrtLen, string &second)
    {
        return 1;
    }
	
	std::shared_ptr<hhou::HHEventLoop> m_Loop;
};

int main(int argc, char *argv[])
{
    hhou::HHLog log(hhou::HHConfig::Instance().ReadStr("log", "path", "../log"), hhou::HHConfig::Instance().ReadInt("log", "tostderror", 1) == 1);
    Test4Server test;
	test.Init();
    test.Run();
	
	Test4Server test1;
	test1.Init();
    test1.Run();
	while(true) {sleep(1000);}
    return 0;
}