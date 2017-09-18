//
// Created by hhou on 17-7-25.
//

#include "../include/WsProcessor.h"
#include "../include/Im.h"
#include "HH_Log.h"

bool WsProcessor::Process(void *Request, void *Reponse)
{
	auto res = static_cast<hhou::HHMsg *>(Reponse);
	auto req = static_cast<hhou::HHMsg *>(Request);

    return true;
}