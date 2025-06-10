#ifndef __BNLOGCLIENT_H__
#define __BNLOGCLIENT_H__
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

#include <binder/IInterface.h>
#include "../ILog/ILOG_Client.h"
#include "../include/command.h"
#include "getip.h"
#include "igs_curl.h"

using namespace android;
namespace android
{
	class BnLOGClient : public BnInterface<ILOGClient> {
		public:
			virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);
			unsigned char resData[1048576];
			unsigned char ip[1024];
			int resDataLen;


		
			int cmd_send(int mode);
			void setDomain(const char *);
			void setUrl(const char *);
			void setPost(const char *);
			const char* getIP();
			const char* getData();
			int getDataLen();

	};

}

#endif
