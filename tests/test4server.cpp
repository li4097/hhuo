#include "../include/net/HH_ServerBase.h"
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
	
	void Run()
	{
		
	}

    int DataDeal(hhou::LinkType nType, void *first, void *second)
    {
        return 1;
    }
};

int main(int argc, char *argv[])
{
    while(true) {sleep(1000);}
    return 0;
}