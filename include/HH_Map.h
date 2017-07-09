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

#ifndef HH_MAP_H
#define HH_MAP_H

#include <map>
#include <algorithm>
using namespace std;

namespace hhou
{
    /*
     * 管理socket句柄的map管理类
     * 或者其他的有相似需求的功能类
     * */
    template <typename T, typename X>
    class HHMap
    {
        typedef map<T, X>::iterator hhIter;
        typedef map<T, X>::const_iterator hhCIter;
    public:
        /*
         * 重载复制
         * */
        HHMap(const HHMap& map) {m_theMap.insert(map.begi(), map.end());}
        HHMap& operator=(const HHMap &map) {m_theMap.insert(map.begi(), map.end());}

        /*
         * 增删改查
         * */
        bool AddItem(T key, X value)
        {
            hhCIter it = m_theMap.find(key);
        }

    private:
        map<T, X> m_theMap;

    };
}

#endif //HH_MAP_H