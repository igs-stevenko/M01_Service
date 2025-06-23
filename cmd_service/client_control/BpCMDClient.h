#ifndef __BPCMDCLIENT_H__
#define __BPCMDCLIENT_H__

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
#include "../include/command.h"
#include "../ICmd/ICMD_Client.h"

using namespace android;
namespace android
{
	class BpCMDClient: public BpInterface<ICMDClient> {

		public:

			BpCMDClient(const sp<IBinder>& impl);
			int cmd_send(int mode);
			void SetShellCmd(const char *);
			const char* GetCmdResData();
			int GetCmdResDataLen();

		private:

			String8 ShellCmd;
			String8 CmdResData;
			int CmdResDataLen;


	};
}


#endif
