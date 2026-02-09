#ifndef _WD_CLIENT_H_
#define _WD_CLIENT_H_

#include <stdio.h>
#include <unistd.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>
#include <binder/IBinder.h>
#include <binder/Binder.h>
#include <binder/ProcessState.h>
#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
 #include <stddef.h>
#include <utils/String8.h>
#include "BnWDClient.h"
#include "../include/command.h"

using namespace android;
namespace android
{
	class WDClient : public BnWDClient {

		public:
			WDClient(){}
		
			int cmd_send(int mode){
				return 0;
			}

			void SetCount(int){
			}
	};
}

#endif

