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

#include "HH_Response.h"

bool hhou::HHResponse::WSEncodeFrame(const string &strRet)
{
    return true;
}

int hhou::HHResponse::MakeRes(string &strRes, const string &strResContentType)
{
    ostringstream os;
    os << "HTTP/1.1 200 OK\r\nContent-Length: " << m_strContent.size()
       << "\r\nContent-Type: " << strResContentType << "\r\n";
    for (auto it = m_mHeaders.begin(); it != m_mHeaders.end(); it++)
    {
        os << it->first << ": " << it->second << "\r\n";
    }
    os << "\r\n" << m_strContent;
    strRes = os.str();
    return 1;
}

int hhou::HHResponse::MakeWBRes(string &strRes, const string &strResContentType)
{
    ostringstream os;
    os << "HTTP/1.1 101 Switching Protocols\r\nContent-Length: " << m_strContent.size()
       << "\r\nContent-Type: " << strResContentType
       << "\r\nConnection: upgrade\r\nUpgrade: websocket\r\n";
    for (auto it = m_mHeaders.begin(); it != m_mHeaders.end(); it++)
    {
        os << it->first << ": " << it->second << "\r\n";
    }
    os << "\r\n" << m_strContent;
    strRes = os.str();
    return 1;
}
