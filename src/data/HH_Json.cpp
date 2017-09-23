/*
Copyright (C) 2004  loveyou12300liumao@163.com

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#include "../../include/data/HH_Json.h"
#include "../../include/HH_Log.h"

bool hhou::HHJson::ExistK(const string &strContent, const string &strK)
{
    if (strContent.empty() || strK.empty())
    {
        LOG(ERROR) << "ExistK strContent or strK empty.";
        return false;
    }
    bool bRet = false;
    Json::CharReaderBuilder builder;
    Json::CharReader* reader(builder.newCharReader());
    JSONCPP_STRING errs;
    Json::Value root;
    bool ok = reader->parse(strContent.c_str(), strContent.c_str() + strContent.length(), &root, &errs);
    if (ok && !root.get(strK, "UTF-8" ).asString().empty())
    {
        bRet = true;
    }
    delete reader;
    reader = nullptr;
    return bRet;
}

bool hhou::HHJson::Read(vector<map<string, string>> &vKV, const string &strContent)
{
    if (strContent.empty())
    {
        LOG(ERROR) << "strContent empty.";
        return false;
    }
    bool bRet = false;
    Json::CharReaderBuilder builder;
    Json::CharReader* reader(builder.newCharReader());
    JSONCPP_STRING errs;
    Json::Value val;
    bool ok = reader->parse(strContent.c_str(), strContent.c_str() + strContent.length(), &val, &errs);
    if (ok)
    {
        for (int n = 0; n < (int)val.size(); n++)
        {
            map<string, string> mVal;
            Json::Value::Members keys = val[n].getMemberNames();
            for (Json::Value::Members::iterator it = keys.begin(); it != keys.end(); it++)
            {
                mVal.insert(make_pair(*it, val[n][*it].asString()));
            }
            vKV.push_back(mVal);
        }
        bRet = true;
    }
    else
    {
        LOG(ERROR) << "Parse error." << errs;
    }
    delete reader;
    reader = nullptr;
    return bRet;
}

bool hhou::HHJson::Read(map<string, string> &vKV, const string &strContent)
{
    if (strContent.empty())
    {
        LOG(ERROR) << "strContent empty.";
        return false;
    }
    bool bRet = false;
    Json::CharReaderBuilder builder;
    Json::CharReader* reader(builder.newCharReader());
    JSONCPP_STRING errs;
    Json::Value val;
    bool ok = reader->parse(strContent.c_str(), strContent.c_str() + strContent.length(), &val, &errs);
    if (ok)
    {
        Json::Value::Members keys = val.getMemberNames();
        for (Json::Value::Members::iterator it = keys.begin(); it != keys.end(); it++)
        {
            vKV.insert(make_pair(*it, val[*it].asString()));
        }
        bRet = true;
    }
    else
    {
        LOG(ERROR) << "Parse error." << errs;
    }
    delete reader;
    reader = nullptr;
    return bRet;
}

bool hhou::HHJson::Write(vector<map<string, string>> &vContent, string &strRet)
{
    Json::Value root, array;
    Json::StreamWriterBuilder builder;
    for (vector<map<string, string>>::iterator it = vContent.begin(); it != vContent.end(); it++)
    {
        Json::Value val;
        map<string, string> each = (*it);
        for (map<string, string>::iterator iter = each.begin(); iter != each.end(); iter++)
        {
            val[iter->first] = iter->second;
        }
        array.append(val);
    }
    strRet = Json::writeString(builder, array);
    return true;
}

bool hhou::HHJson::Write(map<string, string> &vContent, string &strRet)
{
    Json::Value root;
    Json::StreamWriterBuilder builder;
    for (map<string, string>::iterator iter = vContent.begin(); iter != vContent.end(); iter++)
    {
        root[iter->first] = iter->second;
    }
    strRet = Json::writeString(builder, root);
    return true;
}