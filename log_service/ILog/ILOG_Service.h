#ifndef _ILOGSERVICE_H_
#define _ILOGSERVICE_H_
#include <stdio.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IBinder.h>
#include <binder/Binder.h>
#include <binder/ProcessState.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <utils/Log.h>
#include <utils/threads.h>

//#include "../server_control/BnLOGService.h"
#include "ILOG_Client.h"

using namespace android;
namespace android
{
	//class ILOGClient;

	class ILOGService : public IInterface
	{
		public:
			DECLARE_META_INTERFACE(LOGService);
			virtual sp<ILOGClient> getClient() = 0;
	};

}

#endif

