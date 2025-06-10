#ifndef __BNLOGSERVICE_H__
#define __BNLOGSERVICE_H__

#include "../ILog/ILOG_Service.h"
#include "../include/command.h"

namespace android
{

	class BnLOGService: public BnInterface<ILOGService> {

		private:
			sp<ILOGClient> mClient;
			unsigned char resData[1048576];
			unsigned char ip[1024];
			int resDataLen;
		public:
			
			
			virtual sp<ILOGClient> getClient(){
				// 假設 mClient 是你在 BnLOGService 裡建好的 LOGClient 實例
				//printf("### [%s][%d] ###\n", __func__, __LINE__); 
				return mClient;
			}
			
			

			BnLOGService(void);
			~BnLOGService(void);

			virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);

	};
}


#endif
