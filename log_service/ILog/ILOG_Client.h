#ifndef _ILOGCLIENT_H_
#define _ILOGCLIENT_H_
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

//#include "../server_control/BnLOGClient.h"

using namespace android;
namespace android
{

	class ILOGClient : public IInterface
	{
		public:
			DECLARE_META_INTERFACE(LOGClient);
			virtual int cmd_send(int mode)=0; 
			virtual void setDomain(const char *)=0;
			virtual void setUrl(const char *)=0;
			virtual void setPost(const char *)=0;
			virtual const char* getIP()=0;
			virtual const char* getData()=0;
			virtual int getDataLen()=0;

	};
}

#endif

