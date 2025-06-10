#include <utils/Log.h>
#include <fcntl.h>
#include <cstddef>
#include <stdlib.h>
#include <cstdlib>
#include "BnLOGService.h"
#include "getip.h"
#include "igs_curl.h"

namespace android 
{

	//extern sp<ILOGClient> g_clientInstance; 

	BnLOGService::BnLOGService(void){
	}

	BnLOGService::~BnLOGService(void){
		
	}

	status_t BnLOGService::onTransact(uint_t code, const Parcel& data, Parcel* reply, uint32_t flags) {

		int rtn = 0;
		int error_flag = 0;


		String16 token;
		//data.checkInterface(this);
		//CHECK_INTERFACE(ILOGService, data, reply);
		

		switch (code) {

			case GET_CLIENT_TRANSACTION: 
				{
					// 確認呼叫 interface 正確
					CHECK_INTERFACE(ILOGService, data, reply);

					//sp<ILOGClient> client = getClient();

					//printf("BnLOGService::onTransact GET_CLIENT_TRANSACTION → client = %p\n", (void *)getClient()->asBinder());

					// 回傳 mClient 的 Binder
					//reply->writeStrongBinder(client);
					reply->writeStrongBinder(getClient()->asBinder());
					//reply->writeStrongBinder(g_clientInstance->asBinder());
					return NO_ERROR;
				}

			default:
				error_flag = 1;
				
				break;
		}

		if(error_flag == 1){
			return -1;
		}

		return NO_ERROR;
	}
};
