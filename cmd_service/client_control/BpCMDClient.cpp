#include <utils/Log.h>
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
#include "BpCMDClient.h"


namespace android
{


	sp<ICMDClient> ICMDClient::asInterface(const sp<IBinder>& obj) {
		sp<ICMDClient> intr;
		if (obj != NULL) {
			sp<IInterface> i = obj->queryLocalInterface(ICMDClient::ICMDClient::descriptor);
			if (i != NULL) {
				intr = static_cast<ICMDClient*>(i.get());
			} else {
				intr = new BpCMDClient(obj);
			}
		}
		return intr;
	}

	BpCMDClient::BpCMDClient(const sp<IBinder>& impl) :
		BpInterface<ICMDClient>(impl) {
		}

	int BpCMDClient::cmd_send(int mode) {

		Parcel data, reply;
		//data.writeInterfaceToken(ICMDClient::getInterfaceDescriptor());

		int rtn = 0;

		switch(mode){
			case EXECUTE_CMD :
			{
				data.writeString8(ShellCmd);
				
				remote()->transact(EXECUTE_CMD, data, &reply);
				
				CmdResData = reply.readString8();
				CmdResDataLen = reply.readInt32();
				rtn = reply.readInt32();

				break;
			}
			case CLEAR_GAME_CACHE :
			{
				data.writeString8(PkgName);
				remote()->transact(CLEAR_GAME_CACHE, data, &reply);
			}

			default:
			{
				rtn = -1;

				break;
			}
		}

		return rtn;
	}

	void BpCMDClient::SetShellCmd(const char *src) {
		ShellCmd.setTo(src);	
	}

	const char* BpCMDClient::GetCmdResData(void) {
		return CmdResData.string();
	}

	int BpCMDClient::GetCmdResDataLen(void) {
		return CmdResDataLen;
	}

	void BpCMDClient::SetPkgName(const char *src) {
		PkgName.setTo(src);	
	}
}
