#ifndef __BNWDSERVICE_H__
#define __BNWDSERVICE_H__

#include "../IWD/IWD_Service.h"
#include "../include/command.h"

namespace android
{

	class BnWDService: public BnInterface<IWDService> {

		private:
			sp<IWDClient> mClient;
		public:
			
			
			virtual sp<IWDClient> getClient(){
				// 假設 mClient 是你在 BnWDService 裡建好的 WDClient 實例
				return mClient;
			}
			
			

			BnWDService(void);
			~BnWDService(void);

			virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);

	};
}


#endif
