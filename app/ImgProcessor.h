//
// Created by hhou on 17-7-25.
//

#ifndef HHUO_IMGPROCESSOR_H
#define HHUO_IMGPROCESSOR_H

#include <set>
#include <string>
#include "parser/HH_ThRequest.h"
#include "parser/HH_ThResponse.h"
using namespace std;

class ImgProcessor
{
public:
    bool Process(void *Request, void *Reponse);

private:
    bool DoPost(hhou::HHThRequest *req, hhou::HHThResponse *res);
    bool DoGet(hhou::HHThRequest *req, hhou::HHThResponse *res);
};

#endif //HHUO_IMGPROCESSOR_H
