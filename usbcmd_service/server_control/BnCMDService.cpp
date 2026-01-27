#include <utils/Log.h>
#include <fcntl.h>
#include <cstddef>
#include <stdlib.h>
#include <cstdlib>
#include "BnCMDService.h"

namespace android 
{
	BnCMDService::BnCMDService(void){
	}

	BnCMDService::~BnCMDService(void){
	}

	status_t BnCMDService::onTransact(uint_t code, const Parcel& data, Parcel* reply, uint32_t flags) {

		int rtn = 0;
		int error_flag = 0;

		String16 token;

		switch (code) {

			case GET_CLIENT_TRANSACTION: 
				{
					// 確認呼叫 interface 正確
					CHECK_INTERFACE(ICMDService, data, reply);
					reply->writeStrongBinder(getClient()->asBinder());
					return NO_ERROR;
					break;
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
