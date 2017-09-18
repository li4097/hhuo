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


#ifndef HH_BASE64_H
#define HH_BASE64_H

#include <openssl/evp.h>  
#include "../HH_Common.h"

namespace hhou
{
    /// base64编码  
	static int Base64Encode(const char *encoded, int encodedLength, char *decoded)  
	{      
	    return EVP_EncodeBlock((unsigned char*)decoded, (const unsigned char*)encoded, encodedLength);  
	}  
	  
	/// base解码  
	static int Base64Decode(const char *encoded, int encodedLength, char *decoded)   
	{      
	    return EVP_DecodeBlock((unsigned char*)decoded, (const unsigned char*)encoded, encodedLength);  
	}
}

#endif // HH_BASE64_H