#include "../include/utils/HH_Base64.h"
#include "../include/HH_Log.h"

int main(int argc, char *argv[])
{
    string shit = "shit111";  
    char result[1000] = {0}; /// 编码的结果  
    hhou::Base64Encode(shit.c_str(), shit.length(), result);  
    LOG(INFO) << result;  
    
	char org[1000] = {0};    /// 解码的结果
    hhou::Base64Decode(result, strlen(result), org);  
    LOG(INFO) << org;  
    return 0;
}
