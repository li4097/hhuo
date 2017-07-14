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
#ifdef HH_HTTP
#include "HH_HttpRequest.h"
#include "HH_HttpResponse.h"
#else
#endif

int hhou::HHParse::ParseData(const char *buf, int nLen, char *strRet)
{
#ifdef HH_HTTP
    hhou::HH_HttpRequest request;
    request.Parse(buf, nLen);

    hhou::HH_HttpResponse response;
    response.MakeRes(strRet, "Ok");
#else

#endif
    return 1;
}