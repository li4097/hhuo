//
// Created by hhou on 17-7-25.
//

#ifndef HHUO_IMGPROCESSOR_H
#define HHUO_IMGPROCESSOR_H

#include <set>
#include <string>
using namespace std;

class ImgProcessor
{
public:
    bool Processor(void *Request, int nLen, void *Reponse);

private:
    bool DoPost() { return true;}
    bool DoGet() { return true;}
};

#endif //HHUO_IMGPROCESSOR_H
