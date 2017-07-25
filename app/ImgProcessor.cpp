//
// Created by hhou on 17-7-25.
//

#include "ImgProcessor.h"
#include "../include/HH_Log.h"

bool ImgProcessor::Processor(void *Request, int nLen, void *Reponse)
{
    auto req = static_cast<hhou::HH_HttpRequest *>(Request);
    auto res = static_cast<hhou::HH_HttpResponse *>(Reponse);

    hhou::HttpMethodType type = req->GetMethodType();
    LOG(INFO) << "Request type: " << type;

    /// 判断是get还是post
    if (type == hhou::HTTP_METHOD_GET)
    {
        DoGet(req, res);
    }
    else
    {
        DoPost(req, res);
    }
    return true;
}

bool ImgProcessor::DoGet(hhou::HH_HttpRequest *req, hhou::HH_HttpResponse *res)
{
    string method = req->GetMethod();
    LOG(INFO) << "Request method: " << method;

    /// get img url: xxxxx/getImg?id=xxxx&w=20&h=30
    return true;
}

bool ImgProcessor::DoPost(hhou::HH_HttpRequest *req, hhou::HH_HttpResponse *res)
{
    return true;
}