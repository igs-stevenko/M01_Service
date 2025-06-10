#ifndef __BPLOGCLIENT_H__
#define __BPLOGCLIENT_H__

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
#include "../ILog/ILOG_Client.h"

using namespace android;
namespace android
{
	class BpLOGClient: public BpInterface<ILOGClient> {

		public:

			BpLOGClient(const sp<IBinder>& impl);
			int cmd_send(int mode);
			void setDomain(const char *);
			void setUrl(const char *);
			void setPost(const char *);
			const char* getIP();
			const char* getData();
			int getDataLen();

		private:

			String8 domain;
			String8 ip;
			String8 url;
			String8 postdata;
			String8 resData;
			int resDataLen;


	};
}


#endif
