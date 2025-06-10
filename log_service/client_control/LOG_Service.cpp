#include <utils/Log.h>
#include <fcntl.h>
#include <cstddef>
#include <stdlib.h>
#include <cstdlib>
#include "LOG_Service.h"
#include "LOG_Client.h"
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
}
