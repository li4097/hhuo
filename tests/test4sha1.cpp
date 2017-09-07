#include "../include/utils/HH_Sha1.h"
#include "../include/utils/HH_Base64.h"
#include "../include/HH_Log.h"

int main(int argc, char *argv[])
{
    char shaHash[128];
    memset(shaHash, 0, sizeof(shaHash));

    string strMagicKey = "dGhlIHNhbXBsZSBub25jZQ==258EAFA5-E914-47DA-95CA-C5AB0DC85B11";
    hhou::Sha1(strMagicKey.c_str(), shaHash);
    LOG(INFO) << "6666: " << shaHash;
    string shit = hhou::Base64Encode((const unsigned char *)shaHash, strlen(shaHash));
    LOG(INFO) << "6666: " << shit;
    return 0;
}