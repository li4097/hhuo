#include "../include/utils/HH_Gzip.h"
#include "../include/HH_Log.h"

int main(int argc, char *argv[])
{
    string strTest = "shit;";
    char decode[1024];
    char out[1024];
    ulong len;
    hhou::gzcompress((Byte *)strTest.c_str(), strTest.size(), (Byte *)decode, &len);
    LOG(INFO) << "Encode: " << decode << " len: " << len;

    hhou::gzdecompress((Byte *)decode, len, (Byte *)out, &len);
    out[len] = '\0';
    LOG(INFO) << "Decode: " << out << " len: " << len;
    return 0;
}