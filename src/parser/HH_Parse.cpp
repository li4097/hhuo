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

#include "HH_Parse.h"

///////////////////////////////
/// 库和功能代码分开
CommitObject DealObject;
bool SetCallBack(CommitObject obj)
{
    DealObject = obj;
    return true;
}
///////////////////////////////

int hhou::HHParse::ParseData(const char *buf, int nLen, char *strRet)
{
    void *first = (void *)buf;
    void *second = (void *)strRet;
#ifdef BE_HTTP
    request.Parse(buf, nLen);
    first = (void *)&request;
    second = (void *)&response;
#endif
    (*DealObject)(first, nLen, second);
    return 1;
}