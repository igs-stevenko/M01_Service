#ifndef __BPWDCLIENT_H__
#define __BPWDCLIENT_H__

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
#include "../IWD/IWD_Client.h"

using namespace android;
namespace android
{
	class BpWDClient: public BpInterface<IWDClient> {

		public:

			BpWDClient(const sp<IBinder>& impl);
			int cmd_send(int mode);
			void SetCount(int);

		private:

			int Count;

	};
}


#endif
