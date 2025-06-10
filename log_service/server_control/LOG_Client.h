#ifndef _LOG_CLIENT_H_
#define _LOG_CLIENT_H_

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
#include "BnLOGClient.h"
#include "../include/command.h"

using namespace android;
namespace android
{
	class LOGClient : public BnLOGClient {

		public:
			LOGClient(){}
		
			int cmd_send(int mode){
				return 0;
			}
			void setDomain(const char *){
			}
			void setUrl(const char *){
			}
			void setPost(const char *){
			}
			const char* getIP(){
				return NULL;
			}
			const char* getData(){
				return NULL;
			}
			int getDataLen(){
				return 0;
			}
	};

}

#endif

