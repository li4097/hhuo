#include "../include/utils/HH_Base64.h"
#include "../include/HH_Log.h"

int main(int argc, char *argv[])
{
    string input = "shitaaaaaa";
    string decode;
    string output;
    output = hhou::Base64Encode((unsigned char *)input.c_str(), input.size());
    LOG(INFO) << "ret: " << output;
    decode = hhou::Base64Decode(output);
    LOG(INFO) << "ret: " << decode;
    return 0;
}
