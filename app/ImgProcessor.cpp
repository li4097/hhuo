//
// Created by hhou on 17-7-25.
//

#include "ImgProcessor.h"
#include "../include/HH_Log.h"

bool ImgProcessor::Process(void *Request, int nLen, void *Reponse)
{
    auto req = static_cast<hhou::HHRequest *>(Request);
    auto res = static_cast<hhou::HHResponse *>(Reponse);

    /// 判断是get还是post
    hhou::HttpMethodType type = req->GetMethodType();
    if (type == hhou::HTTP_METHOD_GET)
        DoGet(req, res);
    else
        DoPost(req, res);
    return true;
}

bool ImgProcessor::DoGet(hhou::HHRequest *req, hhou::HHResponse *res)
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

bool ImgProcessor::DoPost(hhou::HHRequest *req, hhou::HHResponse *res)
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
        res->SetContent(strRet);
    }
    return true;
}