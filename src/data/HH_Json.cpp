#include "HH_Json.h"

bool hhou::HHJson::ExistK(const string &strContent, const string &strK)
{
    HHJReader reader;
    HHJVal val;
    if (reader.parse(strContent, val))
    {
        if (val[strK].isNull())
        {
            /// 不存在字段
            return false;
        }
    }
    else  /// 解析出错，则认为不存在次字段
    {
        return false;
    }
    return true;
}

bool hhou::HHJson::Read(vector<map<string, string> > &vKV, const string &strContent)
{
    HHJReader reader;
    HHJVal val;
    if (reader.parse(strContent, val))
    {
        for (int n = 0; n < (int)val.size(); n++)
        {
            map<string, string> mVal;
            HHJMembs keys = val[n].getMemberNames();
            for (HHJMembs::iterator it = keys.begin(); it != keys.end(); it++)
            {
                mVal.insert(make_pair(*it, val[n][*it].asString()));
            }
            vKV.push_back(mVal);
        }
    }
    else
    {
        return false;
    }
    return true;
}

bool hhou::HHJson::Write(vector<map<string, string> > &vContent, string &strRet)
{
    HHJVal root, array;
    HHJWriter writer;
    for (vector<map<string, string> >::iterator it = vContent.begin(); it != vContent.end(); it++)
    {
        HHJVal val;
        map<string, string> each = (*it);
        for (map<string, string>::iterator iter = each.begin(); iter != each.end(); iter++)
        {
            val[iter->first] = iter->second;
        }
        array.append(val);
    }
    strRet = writer.write(array);
    return true;
}