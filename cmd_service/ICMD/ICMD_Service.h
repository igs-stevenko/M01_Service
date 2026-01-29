#ifndef _ICMDSERVICE_H_
#define _ICMDSERVICE_H_
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

#include "ICMD_Client.h"

using namespace android;
namespace android
{
	class ICMDService : public IInterface
	{
		public:
			DECLARE_META_INTERFACE(CMDService);
			virtual sp<ICMDClient> getClient() = 0;
	};

}

#endif

