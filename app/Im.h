//
// Created by hhou on 17-9-25.
//

#ifndef HHUO_IM_H
#define HHUO_IM_H

#include <string>
using namespace std;

/**
 * Im相关的代码
 * 采用protobuf封装数据
 */
 class Im 
 {
 public:
    /**登录的操作（返回用户的一些基本信息）*/
    bool Login(const string &strUser, const string &strPass, string &strResult);

    /**登录成功后，则通过token进行操作（获取或者推送此用户的好友信息）*/
    bool GetFriends(const string &strToken, string &strResult);

    /**推送离线时的消息（量多，会分批推送），返回为false，则离线消息推送完毕*/
    bool GetOfflineMsg(string &strResult);

 private:
    bool m_bLogin; /// 是否登录成功

 };

 #endif //HHUO_IM_H