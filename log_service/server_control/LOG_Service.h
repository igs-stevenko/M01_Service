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

#include "../include/command.h"

#define ACTION_ERROR (-1)

#ifdef ALOGD
#ifdef LOG_TAG
#undef LOG_TAG  
#define LOG_TAG "NativeIGSPROTECTDaemon"
#endif

#define LOGD(msg,...)                 ALOGD("%s(%d):" msg ,__FUNCTION__,__LINE__,##__VA_ARGS__)
#endif

using namespace android;
namespace android
{

	class ILOGService : public IInterface
	{
		public:
			DECLARE_META_INTERFACE(LOGService);
	};

	class BpLOGService: public BpInterface<ILOGService> {
		
		public:
			BpLOGService(const sp<IBinder>& impl);
	
	};

	class BnLOGService: public BnInterface<ILOGService> {

		private:
			unsigned char resData[1048576];
			unsigned char ip[1024];
			int resDataLen;
		public:
			
			BnLOGService(void);
			~BnLOGService(void);

			virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);

	};
}

#endif

