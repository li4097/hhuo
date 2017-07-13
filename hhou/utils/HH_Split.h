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
#ifndef HH_SPLIT_H
#define HH_SPLIT_H

#include <vector>
#include <map>
#include "../net/HH_Common.h"

namespace hhou
{
    /**
     * 定义一些常用的轮子
     */
    void SplitString(const string &s, vector<string> &v, const string &c)
    {
        size_t pos1, pos2;
        pos2 = s.find(c);
        if ((int)pos2 == -1)
            return;
        pos1 = 0;
        while(std::string::npos != pos2)
        {
            v.push_back(s.substr(pos1, pos2-pos1));
            pos1 = pos2 + c.size();
            pos2 = s.find(c, pos1);
        }
        if(pos1 != s.length())
            v.push_back(s.substr(pos1));
    }

    void SplitKV(const string &s, map<string, string> &mKV, const string &c)
    {
        size_t pos = s.find(c);
        if ((int)pos == -1)
            return;
        string strKey = s.substr(0, pos);
        string strValue = s.substr(pos + 1);
        mKV.insert(make_pair(strKey.erase(0, strKey.find_first_not_of(" ")), strValue.erase(0, strValue.find_first_not_of(" "))));
    }
}

#endif //HH_SPLIT_H