//
// Created by hhou on 17-7-25.
//

#ifndef HHUO_IMGPROCESSOR_H
#define HHUO_IMGPROCESSOR_H

#include <set>
#include <string>
#include "../include/parser/HH_HttpRequest.h"
#include "../include/parser/HH_HttpResponse.h"
using namespace std;

class ImgProcessor
{
public:
    bool Processor(void *Request, int nLen, void *Reponse);

private:
    bool DoPost(hhou::HH_HttpRequest *req, hhou::HH_HttpResponse *res);
    bool DoGet(hhou::HH_HttpRequest *req, hhou::HH_HttpResponse *res);
};

#endif //HHUO_IMGPROCESSOR_H
