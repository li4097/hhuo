//
// Created by hhou on 17-7-25.
//

#ifndef HHUO_IMGPROCESSOR_H
#define HHUO_IMGPROCESSOR_H

#include <set>
#include <string>
#include "parser/HH_Request.h"
#include "parser/HH_Response.h"
using namespace std;

class ImgProcessor
{
public:
    bool Processor(void *Request, int nLen, void *Reponse);

private:
    bool DoPost(hhou::HHRequest *req, hhou::HHResponse *res);
    bool DoGet(hhou::HHRequest *req, hhou::HHResponse *res);
};

#endif //HHUO_IMGPROCESSOR_H
