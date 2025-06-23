#include <utils/Log.h>

#include "BpCMDClient.h"
#include "BpCMDService.h"
#include "libcmd_client.h"
#include <android/log.h>

int send_cmd_traceroute(char *resData, int *resDataLen){

	int rtn = 0;
	const char *ShellCmd = "busybox traceroute 8.8.8.8 2>&1";

	if(resData == NULL){
		return NULL_POINT;
	}

	sp < IServiceManager > sm = defaultServiceManager();
	sp < IBinder > binder = sm->getService(String16("service.igscmd"));
	
	if(binder == 0)	return TRACEROUTE_BINDER_FAILED;
	
	sp<ICMDService> svc = interface_cast <ICMDService> (binder);
	sp<IBinder> clientBinder = svc->getClient()->asBinder();
	sp<ICMDClient> cs = interface_cast<ICMDClient>(clientBinder);

	cs->SetShellCmd(ShellCmd);

	rtn = cs->cmd_send(EXECUTE_CMD);
	if(rtn != 0){
		return TRACEROUTE_CMD_FAILED;
	}

	memcpy(resData, cs->GetCmdResData(), strlen(cs->GetCmdResData()) );
	*resDataLen = cs->GetCmdResDataLen();

	return rtn;
}

