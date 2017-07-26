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

#include "HH_HttpResponse.h"

int hhou::HH_HttpResponse::MakeRes(char *strResp, int nSize, const string &strResContentType)
{
    int nPos = snprintf(strResp, nSize, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\nContent-Type: %s\r\n",
            (int)m_strContent.size(), strResContentType.c_str());
    for (auto it = m_mHeaders.begin(); it != m_mHeaders.end(); it++)
        nPos += snprintf(strResp + nPos, nSize - nPos, "%s: %s\r\n",
                         it->first.c_str(), it->second.c_str());
    snprintf(strResp + nPos, nSize - nPos, "\r\n%s", m_strContent.c_str());
    return 1;
}