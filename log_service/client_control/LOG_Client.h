#ifndef _LOG_CLIENT_H_
#define _LOG_CLIENT_H_

#include <stdio.h>
#include <unistd.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IBinder.h>
#include <binder/Binder.h>
#include <binder/ProcessState.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
 #include <stddef.h>
#include <utils/String8.h>
#include "../include/command.h"
#include "error_code.h"

using namespace android;
namespace android
{


    class ILOGClient : public IInterface
	{
		public:
			DECLARE_META_INTERFACE(LOGClient);
			virtual int cmd_send(int mode)=0;
			String8 domain;
			String8 ip;
			String8 url;
			String8 postdata;
			String8 resData;
			int resDataLen;
	};

	class BpLOGClient: public BpInterface<ILOGClient> {
		
		public:
			BpLOGClient(const sp<IBinder>& impl);
			int cmd_send(int mode);
		
		private:
			

	};
}

#endif

