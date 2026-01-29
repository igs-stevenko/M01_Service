#include <utils/Log.h>

#include "BpCMDClient.h"
#include "BpCMDService.h"
#include "libcmd_client.h"
#include <android/log.h>

int send_cmd_traceroute(char *resData, int *resDataLen){

	int rtn = 0;
	const char *ShellCmd = "busybox traceroute  -m 10 220.181.38.148";

	if(resData == NULL){
		return PARM_ERROR;
	}

	sp < IServiceManager > sm = defaultServiceManager();
	sp < IBinder > binder = sm->getService(String16("service.igscmd"));
	
	if(binder == 0)	return BINDER_FAILED;
	
	sp<ICMDService> svc = interface_cast <ICMDService> (binder);
	sp<IBinder> clientBinder = svc->getClient()->asBinder();
	sp<ICMDClient> cs = interface_cast<ICMDClient>(clientBinder);

	cs->SetShellCmd(ShellCmd);

	rtn = cs->cmd_send(EXECUTE_CMD);
	if(rtn != 0){
		return BINDER_FAILED;
	}

	memcpy(resData, cs->GetCmdResData(), strlen(cs->GetCmdResData()) );
	*resDataLen = cs->GetCmdResDataLen();

	return rtn;
}

int send_cmd_cleargamecache(const char *PkgName){

	int rtn = 0;

	if(PkgName == NULL){
		return PARM_ERROR;
	}

	sp < IServiceManager > sm = defaultServiceManager();
	sp < IBinder > binder = sm->getService(String16("service.igscmd"));
	
	if(binder == 0)	return BINDER_FAILED;
	
	sp<ICMDService> svc = interface_cast <ICMDService> (binder);
	sp<IBinder> clientBinder = svc->getClient()->asBinder();
	sp<ICMDClient> cs = interface_cast<ICMDClient>(clientBinder);

	cs->SetPkgName(PkgName);

	rtn = cs->cmd_send(CLEAR_GAME_CACHE);
	if(rtn != 0){
		return BINDER_FAILED;
	}

	return rtn;
}

