//
// Created by hhou on 17-7-25.
//

#include "ImgProcessor.h"
#include "../include/HH_Log.h"

bool ImgProcessor::Processor(void *Request, int nLen, void *Reponse)
{
    auto req = static_cast<hhou::HH_HttpRequest *>(Request);
    auto res = static_cast<hhou::HH_HttpResponse *>(Reponse);

    /// 判断是get还是post
    hhou::HttpMethodType type = req->GetMethodType();
    if (type == hhou::HTTP_METHOD_GET)
        DoGet(req, res);
    else
        DoPost(req, res);
    return true;
}

bool ImgProcessor::DoGet(hhou::HH_HttpRequest *req, hhou::HH_HttpResponse *res)
{
    /// get img url: xxxxx/getimg?id=xxxx&w=20&h=30
    string strRet = "OK";
    string method = req->GetMethod();
    if (method == "/")  /// test?
    {
        res->SetContent(strRet);
    }
    else if (method == "/getimg")
    {
        /// 解析后面具体的参数
        string strID, strW, strH;
        req->GetParam("id", strID);
        req->GetParam("w", strW);
        req->GetParam("h", strH);
        LOG(INFO) << "GetImg ID: " << strID << " width: " << strW << " height: " << strH;
    }
    return true;
}

bool ImgProcessor::DoPost(hhou::HH_HttpRequest *req, hhou::HH_HttpResponse *res)
{
    /// opst img url: xxxxx/uploadimg
    string strRet = "OK";
    string method = req->GetMethod();
    if (method == "/")  /// test?
    {
        res->SetContent(strRet);
    }
    else if (method == "/uploadimg")
    {
        /// 上传图片的不设置参数
        req->GetContent(strRet);
    }
    return true;
}