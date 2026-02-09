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
#include "BpWDClient.h"


namespace android
{


	sp<IWDClient> IWDClient::asInterface(const sp<IBinder>& obj) {
		sp<IWDClient> intr;
		if (obj != NULL) {
			sp<IInterface> i = obj->queryLocalInterface(IWDClient::IWDClient::descriptor);
			if (i != NULL) {
				intr = static_cast<IWDClient*>(i.get());
			} else {
				intr = new BpWDClient(obj);
			}
		}
		return intr;
	}

	BpWDClient::BpWDClient(const sp<IBinder>& impl) :
		BpInterface<IWDClient>(impl) {
		}

	int BpWDClient::cmd_send(int mode) {

		Parcel data, reply;

		int rtn = 0;

		switch(mode){
			case INIT:
			{
				data.writeInt32(Count);
				remote()->transact(INIT, data, &reply);
				break;
			}
			case KEEPALIVE :
			{
				remote()->transact(KEEPALIVE, data, &reply);
				
				break;
			}
			default:
			{
				rtn = -1;

				break;
			}
		}

		return rtn;
	}

	void BpWDClient::SetCount(int Src){

		Count = Src;
	}
}
