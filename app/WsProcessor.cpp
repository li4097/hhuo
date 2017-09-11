//
// Created by hhou on 17-7-25.
//

#include "WsProcessor.h"
#include "../include/HH_Log.h"

bool WsProcessor::Process(void *Request, void *Reponse)
{
	auto data = static_cast<hhou::HHMsg *>(Reponse);
	auto msg = static_cast<hhou::HHMsg *>(Request);
	LOG(INFO) << "Msg: " << msg->m_strMsg << " size: " << msg->m_strMsg.length();
	data->m_nOp = 1;
	data->m_strMsg = "666";
    return true;
}