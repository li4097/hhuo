//
// Created by hhou on 17-7-25.
//

#ifndef HHUO_WSPROCESSOR_H
#define HHUO_WSPROCESSOR_H

#include <set>
#include <string>
#include "HH_WsRequest.h"
#include "HH_WsResponse.h"
using namespace std;

class WsProcessor
{
public:
    bool Process(void *Request, void *Reponse);
};

#endif //HHUO_WSPROCESSOR_H
