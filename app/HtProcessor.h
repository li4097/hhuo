//
// Created by hhou on 17-7-25.
//

#ifndef HHUO_THPROCESSOR_H
#define HHUO_THGPROCESSOR_H

#include <set>
#include <string>
#include "parser/HH_ThRequest.h"
#include "parser/HH_ThResponse.h"
using namespace std;

class HtProcessor
{
public:
    bool Process(void *Request, void *Reponse);

private:
    bool DoPost(hhou::HHThRequest *req, hhou::HHThResponse *res);
    bool DoGet(hhou::HHThRequest *req, hhou::HHThResponse *res);
};

#endif //HHUO_THPROCESSOR_H
