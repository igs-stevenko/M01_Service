#ifndef __BPCMDSERVICE_H__
#define __BPCMDSERVICE_H__
#include <binder/IInterface.h>
#include "../include/command.h"
#include "../ICmd/ICMD_Service.h"
#include "../ICmd/ICMD_Client.h"

using namespace android;
namespace android
{
	class BpCMDService: public BpInterface<ICMDService> {
		
		public:
			BpCMDService(const sp<IBinder>& impl);
			sp<ICMDClient> getClient();
	};

}

#endif
