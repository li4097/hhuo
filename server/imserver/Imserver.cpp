#include "HH_ListenEvent.h"
#include "HH_EventLoop.h"
#include "HH_ServerBase.h"
#include "app/include/HtProcessor.h"
#include "app/include/WsProcessor.h"
#include "HH_Log.h"

class IMServer : public hhou::HHServerBase
{
public:
    IMServer()
    {

    }

    ~IMServer()
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

    int DataDeal(hhou::LinkType nType, void *first, void *second)
    {
		switch (nType)
		{
			case 0:
			{
				HtProcessor processor;
				return (int)processor.Process(first, second);				
			}
				break;
			case 1:
			{
				WsProcessor processor;
				return (int)processor.Process(first, second);
			}
				break;
			case 2:
			{
				
			}
				break;
			default:
				break;
		}
		return 0;
    }
	
	std::shared_ptr<hhou::HHEventLoop> m_Loop;
};

int main(int argc, char *argv[])
{
    hhou::HHLog log(hhou::HHConfig::Instance().ReadStr("log", "path", "../log"), hhou::HHConfig::Instance().ReadInt("log", "tostderror", 1) == 1);
    IMServer im;
	im.Init();
    im.Run();
	
	while(true) {sleep(1000);}
    return 0;
}