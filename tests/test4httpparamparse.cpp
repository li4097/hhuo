#include "../hhou/parser/HH_HttpParser.h"

int main(int argc, char *argv[])
{
    char *strTest = "fuck=1234&shit=345";
    hhou::HHHttpParamParser httpParamParser(strTest, strlen(strTest));
    cout << "key:fuck,value:" << httpParamParser.GetParam("fuck") << endl;
    cout << "key:shit,value:" << httpParamParser.GetParam("shit") << endl;
    return 0;
}