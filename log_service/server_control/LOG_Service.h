#ifndef _LOGSERVICE_H_
#define _LOGSERVICE_H_
#include <stdio.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IBinder.h>
#include <binder/Binder.h>
#include <binder/ProcessState.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <utils/Log.h>
#include <utils/threads.h>

#include "BnLOGService.h"
#include "LOG_Client.h"

using namespace android;
namespace android
{

	class LOGService : public BnLOGService{

		public : 
			LOGService(){
				//printf("### [%s][%d] ###\n", __func__, __LINE__); 
				mClient = new LOGClient();
			}


			virtual sp<ILOGClient> getClient() {
				//printf("### [%s][%d] ###\n", __func__, __LINE__); 
				return mClient;
			}

		private :

			sp<ILOGClient> mClient;

	};
}

#endif

