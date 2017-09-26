#include "../include/net/HH_ListenEvent.h"
#include "../include/net/HH_EventLoop.h"
#include "../include/net/HH_ServerBase.h"
#include "../include/parser/HH_Parse.h"
#include "../include/HH_Config.h"
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
		m_Loop = make_shared<hhou::HHEventLoop>();
		m_Loop->Init("0.0.0.0", 9999, "/mnt/hgfs/CPP/imserver/certificate/cacert.pem", "/mnt/hgfs/CPP/imserver/certificate/privkey.pem");
        return true;
    }
	
	void Run()
	{
		m_Loop->Start();
	}

    int DataDeal(hhou::LinkType nType, int fd, void *first, void *second)
    {
        LOG(INFO) << "buf: " << (char *)first << ", fd: " << fd;
		auto iter = hhou::HHParserMgr::Instance().GetParser(fd);
        return 1;
    }
    std::shared_ptr<hhou::HHEventLoop> m_Loop;
};

int main(int argc, char *argv[])
{
    Test4Server ts;
	ts.Init();
    ts.Run();

    while(true) {sleep(1000);}
    return 0;
}