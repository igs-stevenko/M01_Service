#ifndef __BNCMDSERVICE_H__
#define __BNCMDSERVICE_H__

#include "../ICmd/ICMD_Service.h"
#include "../include/command.h"

namespace android
{

	class BnCMDService: public BnInterface<ICMDService> {

		private:
			sp<ICMDClient> mClient;
			//unsigned char resData[1048576];
			//unsigned char cmd_buf[1024];
			//int resDataLen;
		public:
			
			
			virtual sp<ICMDClient> getClient(){
				// 假設 mClient 是你在 BnCMDService 裡建好的 CMDClient 實例
				return mClient;
			}
			
			

			BnCMDService(void);
			~BnCMDService(void);

			virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);

	};
}


#endif
