#ifndef __WATCHDOGTHREAD_H__
#define __WATCHDOGTHREAD_H__
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
#include "../IWD/IWD_Client.h"
#include "../include/command.h"
#include "WatchdogThread.h"

using namespace android;
namespace android
{
	class BnWDClient : public BnInterface<IWDClient> {
	
		public:
			BnWDClient(void);
			virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);
		
			int cmd_send(int mode);
		private:
			sp<WatchdogThread> mWatchdog;
	};

}

#endif
