#ifndef __BPLOGSERVICE_H__
#define __BPLOGSERVICE_H__
#include <binder/IInterface.h>
#include "../include/command.h"
#include "../ILog/ILOG_Service.h"
#include "../ILog/ILOG_Client.h"

using namespace android;
namespace android
{
	class BpLOGService: public BpInterface<ILOGService> {
		
		public:
			BpLOGService(const sp<IBinder>& impl);
			sp<ILOGClient> getClient();
	};

}

#endif
