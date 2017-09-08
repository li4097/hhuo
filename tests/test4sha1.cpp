#include "../include/utils/HH_Sha1.h"
#include "../include/utils/HH_Base64.h"
#include "../include/HH_Log.h"

int main(int argc, char *argv[])
{
    char shaHash[128];
    memset(shaHash, 0, sizeof(shaHash));
    string strMagicKey = "dGhlIHNhbXBsZSBub25jZQ==258EAFA5-E914-47DA-95CA-C5AB0DC85B11";
    hhou::Sha1(strMagicKey, shaHash);
    LOG(INFO) << "6666: " << shaHash;
	
	char result[1000] = {0};  
	string strShit = string(shaHash);
    hhou::Base64Encode(strShit, result);   
    LOG(INFO) << result;  
    return 0;
}