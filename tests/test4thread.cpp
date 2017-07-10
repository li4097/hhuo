#include "HH_Thread.h"

bool bQuit = false;
int main(int argc, char *argv[])
{
    hhou::HHThread *pThread = new hhou::HHThread();
    pThread->StartThread();
    while (!bQuit);
    return 0;
}