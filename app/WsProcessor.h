//
// Created by hhou on 17-7-25.
//

#ifndef HHUO_WSPROCESSOR_H
#define HHUO_WSPROCESSOR_H

#include <set>
#include <string>
#include "parser/HH_Websocket.h"
using namespace std;

class WsProcessor
{
public:
    bool Process(void *Request, int nLen, void *Reponse);
	
};

#endif //HHUO_WSPROCESSOR_H
