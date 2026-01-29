#ifndef _CMD_CLIENT_H_
#define _CMD_CLIENT_H_

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
#include "BnCMDClient.h"
#include "../include/command.h"

using namespace android;
namespace android
{
	class CMDClient : public BnCMDClient {

		public:
			CMDClient(){}
		
			int cmd_send(int mode){
				return 0;
			}

			void SetShellCmd(const char *cmd){
			}

			const char* GetCmdResData(){
				return NULL;
			}

			int GetCmdResDataLen(){
				return 0;
			}
			
			void SetPkgName(const char *cmd){
			}
	};

}

#endif

