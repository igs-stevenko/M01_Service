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
#include "BpLOGClient.h"


namespace android
{


	sp<ILOGClient> ILOGClient::asInterface(const sp<IBinder>& obj) {
		sp<ILOGClient> intr;
		if (obj != NULL) {
			//sp<IInterface> i = obj->queryLocalInterface(ILOGClient::getInterfaceDescriptor());
			sp<IInterface> i = obj->queryLocalInterface(ILOGClient::ILOGClient::descriptor);
			if (i != NULL) {
				intr = static_cast<ILOGClient*>(i.get());
			} else {
				intr = new BpLOGClient(obj);
			}
		}
		return intr;
	}

	BpLOGClient::BpLOGClient(const sp<IBinder>& impl) :
		BpInterface<ILOGClient>(impl) {
		}

	int BpLOGClient::cmd_send(int mode) {

		Parcel data, reply;
		//data.writeInterfaceToken(ILOGClient::getInterfaceDescriptor());

		int rtn = 0;

		switch(mode){
			case GET_IP :

				data.writeString8(domain);
				
				remote()->transact(GET_IP, data, &reply);
				
				ip = reply.readString8();
				rtn = reply.readInt32();

				break;

			case POST_LOG :

				data.writeString8(url);
				data.writeString8(postdata);

				remote()->transact(POST_LOG, data, &reply);

				resData = reply.readString8();
				resDataLen = reply.readInt32();
				rtn = reply.readInt32();

				break;

			default:

				rtn = -1;

				break;
		}

		return rtn;
	}


	void BpLOGClient::setDomain(const char *src) {
		printf("### [%s][%d] ###\n", __func__, __LINE__); 
		domain.setTo(src);	
		printf("### [%s][%d] ###\n", __func__, __LINE__); 
	}

	void BpLOGClient::setUrl(const char *src) {
		url.setTo(src);	
	}

	void BpLOGClient::setPost(const char *src) {
		postdata.setTo(src);	
	}

	const char* BpLOGClient::getIP(void) {
		return ip.string();
	}

	const char* BpLOGClient::getData(void) {
		return resData.string();
	}

	int BpLOGClient::getDataLen(void) {
		return resDataLen;
	}
}
