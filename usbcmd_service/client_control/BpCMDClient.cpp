#include <utils/Log.h>
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
#include "BpCMDClient.h"


namespace android
{


	sp<ICMDClient> ICMDClient::asInterface(const sp<IBinder>& obj) {
		sp<ICMDClient> intr;
		if (obj != NULL) {
			sp<IInterface> i = obj->queryLocalInterface(ICMDClient::ICMDClient::descriptor);
			if (i != NULL) {
				intr = static_cast<ICMDClient*>(i.get());
			} else {
				intr = new BpCMDClient(obj);
			}
		}
		return intr;
	}

	BpCMDClient::BpCMDClient(const sp<IBinder>& impl) :
		BpInterface<ICMDClient>(impl) {
		}

	int BpCMDClient::cmd_send(int mode) {

		Parcel data, reply;

		int rtn = 0;

		switch(mode){
			
			case REMOVE_CACHE :
			{
				break;
			}
			case GPIO14_UP :
			{
				remote()->transact(GPIO14_UP, data, &reply);
				break;
			}
			case GPIO14_DOWN :
			{
				remote()->transact(GPIO14_DOWN, data, &reply);
				break;
			}
			default:

				rtn = -1;

				break;
		}

		return rtn;
	}
}
