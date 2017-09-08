#include "../include/utils/HH_Base64.h"
#include "../include/HH_Log.h"

int main(int argc, char *argv[])
{
    string shit = "shit111";  
    char result[1000] = {0}; /// 编码的结果  
    hhou::Base64Encode(shit, result);  
    LOG(INFO) << result;  
    
	char org[1000] = {0};    /// 解码的结果
	string strShit = string(result);
    hhou::Base64Decode(strShit, org);  
    LOG(INFO) << org;  
    return 0;
}
