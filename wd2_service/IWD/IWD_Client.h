#ifndef _IWDCLIENT_H_
#define _IWDCLIENT_H_
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

using namespace android;
namespace android
{

	class IWDClient : public IInterface
	{
		public:
			DECLARE_META_INTERFACE(WDClient);
			virtual int cmd_send(int mode)=0;
			virtual void SetCount(int)=0;
	};
}

#endif

