#include "LOG_Client.h"
#include <utils/Log.h>

#ifdef LOG_TAG
#undef LOG_TAG
#define LOG_TAG "NativeIOtgManagerService"
#endif

namespace android
{
	IMPLEMENT_META_INTERFACE(LOGClient, "android.igs.ILOGClient");
	BpLOGClient::BpLOGClient(const sp<IBinder>& impl) :
		BpInterface<ILOGClient>(impl) {
		}

	int BpLOGClient::cmd_send(int mode) {
		
		Parcel data, reply;
		data.writeInterfaceToken(ILOGClient::getInterfaceDescriptor());
		
		int rtn = 0;

		switch(mode){
			case GET_IP :
				
				data.writeString8(domain);
				
				remote()->transact(GET_IP, data, &reply);

				rtn = reply.readInt32();
			
				ip = reply.readString8();
				break;

			case POST_LOG :

				data.writeString8(url);
				data.writeString8(postdata);

				remote()->transact(POST_LOG, data, &reply);

				rtn = reply.readInt32();

				resData = reply.readString8();
				resDataLen = reply.readInt32();

				break;

			default:

				rtn = -1;

				break;
		}

		return rtn;
	}
}
