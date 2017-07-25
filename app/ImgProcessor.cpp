//
// Created by hhou on 17-7-25.
//

#include "ImgProcessor.h"
#include "../include/parser/HH_HttpRequest.h"
#include "../include/parser/HH_HttpResponse.h"
#include "../include/HH_Log.h"

bool ImgProcessor::Processor(void *Request, int nLen, void *Reponse)
{
    hhou::HH_HttpRequest *req = static_cast<hhou::HH_HttpRequest *>(Request);
    hhou::HH_HttpResponse *res = static_cast<hhou::HH_HttpResponse *>(Reponse);

    hhou::HttpMethodType type = req->GetMethodType();
    LOG(INFO) << "Request type: " << (hhou::HttpMethodType)type;

    string method = req->GetMethod();
    LOG(INFO) << "Request method: " << method;
    return true;
}