#include "HH_Log.h"

int main(int argc, char *argv[])
{
    hhou::HHLog log("../log");
    LOG(INFO) << "Found " << " cookies";
    LOG(ERROR) << "ssss";
    LOG(WARNING) << "12";
    return 0;
}