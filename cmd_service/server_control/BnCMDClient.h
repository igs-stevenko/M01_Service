#ifndef __BNCMDCLIENT_H__
#define __BNCMDCLIENT_H__
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
#include "../ICmd/ICMD_Client.h"
#include "../include/command.h"

using namespace android;
namespace android
{
	class BnCMDClient : public BnInterface<ICMDClient> {
		public:
			virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);
		
			int cmd_send(int mode);
			void SetShellCmd(const char *);
			const char* GetCmdResData();
			int GetCmdResDataLen();
	};

}

#endif
