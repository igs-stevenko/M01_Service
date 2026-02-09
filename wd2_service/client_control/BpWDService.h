#ifndef __BPWDSERVICE_H__
#define __BPWDSERVICE_H__
#include <binder/IInterface.h>
#include "../include/command.h"
#include "../IWD/IWD_Service.h"
#include "../IWD/IWD_Client.h"

using namespace android;
namespace android
{
	class BpWDService: public BpInterface<IWDService> {
		
		public:
			BpWDService(const sp<IBinder>& impl);
			sp<IWDClient> getClient();
	};

}

#endif
