//
// Created by mao.liu on 2017/7/11.
//

#include "../include/net/HH_EventBase.h"
#include "../include/net/HH_Task.h"
#include "utils/HH_ThreadPool.h"
#include "../include/HH_Log.h"

class testShit : public hhou::HHEventBase
{
    /**读操作*/
    virtual void OnRead() {cout << "OnRead" << endl;}

    /**写操作*/
    virtual void OnWrite() {cout << "OnWrite" << endl;}

    /**超时操作*/
    virtual void OnTimeout() {cout << "OnTimeout" << endl;}
};

bool bQuit = false;
int main(int argc, char *argv[])
{

    return 0;
}