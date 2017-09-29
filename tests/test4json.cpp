#include "../include/data/HH_Json.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    map<string, string> m;
    m["1"] = "1";
    m["2"] = "2";
    map<string, string> m1;
    m1["1"] = "1";
    m1["2"] = "2";
    vector<map<string, string>> s;
    s.push_back(m);
    s.push_back(m1);

    ////////////////////////////////
    string strRet;
    hhou::HHJson json;
    json.Write(m, strRet);
    cout << "Write ret: " << strRet << endl;

    /////////////////////////////////
    /*{
        "ret":"OK",
        "msg":"成功",
        "data":[{},{}]
    }*/
    string strIn = "[{ \"property\" : \"value\" }]";
    vector<map<string, string>> shit;
    json.Read(shit, strIn);
    cout << "Read ret: " << shit[0]["property"] << endl; 
    return 0;
}