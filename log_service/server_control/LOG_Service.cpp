#include <utils/Log.h>
#include <fcntl.h>
#include <cstddef>
#include <stdlib.h>
#include <cstdlib>
#include "LOG_Service.h"
#include "getip.h"
#include "igs_curl.h"

#define LINK_TARGET "/ramdisk/libil2cppDecrypted.so"

namespace android
{

	IMPLEMENT_META_INTERFACE(LOGService, "android.igs.ILOGService");
	BpLOGService::BpLOGService(const sp<IBinder>& impl) :
		BpInterface<ILOGService>(impl) {
			printf("### [%s][%d] ###\n", __func__, __LINE__); 
		}

	BnLOGService::BnLOGService(void){

	}

	BnLOGService::~BnLOGService(void){
		
	}
	
	status_t BnLOGService::onTransact(uint_t code, const Parcel& data, Parcel* reply, uint32_t flags) {

		int rtn = 0;
		int error_flag = 0;


		data.checkInterface(this);

		switch (code) {

			case GET_IP :
			{
				printf("---> GET_IP <---\n");
				
				String8 rtnData;
				String8 domain;
				
				memset(ip, 0, sizeof(ip));

				domain = data.readString8();
//				printf("domain = %s\n", domain.string());
				rtn = getip((char *)(domain.string()), (char *)ip);
//				printf("ip = %s\n", ip);
				rtnData.setTo((const char *)ip);
				
				reply->writeInt32(rtn);
				reply->writeString8(rtnData);
				
				break;
			}
			case POST_LOG :
			{	
				printf("---> POST_LOG <---\n");
	
				String8 rtnData;
				String8 jsonData;
				String8 url;
				
				memset(resData, 0, sizeof(resData));
				resDataLen = 0;

				url = data.readString8();
				jsonData = data.readString8();

//				printf("url = %s\n", url.string());
//				printf("jsonData = %s\n", jsonData.string());

				rtn = PostData((char *)(url.string()), (char *)(jsonData.string()),(char *)resData, &resDataLen);

//				printf("resData = %s", resData);
//				printf("resDataLen = %d\n", resDataLen);

				rtnData.setTo((const char *)resData);
				reply->writeInt32(rtn);
				reply->writeString8(rtnData);
				reply->writeInt32(resDataLen);
				break;
			}
			default:
				
				error_flag = 1;
				
				break;
		}

		if(error_flag == 1){
			return ACTION_ERROR;
		}

		return NO_ERROR;
	}
}
