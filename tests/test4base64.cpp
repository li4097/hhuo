#include "../include/utils/HH_Base64.h"
#include "../include/HH_Log.h"

int main(int argc, char *argv[])
{
    string input = "shit";
    char decode[13];
    char output[13];
    hhou::Base64Encode(input.c_str(), input.size(), output);
    LOG(INFO) << "ret: " << output;
    hhou::Base64Decode(output, strlen(output), decode);
    LOG(INFO) << "ret: " << decode;
    return 0;
}