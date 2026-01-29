#ifndef _ICMDCLIENT_H_
#define _ICMDCLIENT_H_
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

	class ICMDClient : public IInterface
	{
		public:
			DECLARE_META_INTERFACE(CMDClient);
			virtual int cmd_send(int mode)=0; 


	};
}

#endif

