#include <utils/Log.h>

#include "BpCMDClient.h"
#include "BpCMDService.h"
#include "libcmd_client.h"
#include <android/log.h>

int send_cmd_usbup(void){

	int rtn = 0;

	sp < IServiceManager > sm = defaultServiceManager();
	sp < IBinder > binder = sm->getService(String16("service.usbcmd"));
	
	if(binder == 0)	return TRACEROUTE_BINDER_FAILED;
	
	sp<ICMDService> svc = interface_cast <ICMDService> (binder);
	sp<IBinder> clientBinder = svc->getClient()->asBinder();
	sp<ICMDClient> cs = interface_cast<ICMDClient>(clientBinder);


	rtn = cs->cmd_send(GPIO14_UP);
	if(rtn != 0){
		return CMD_FAILED;
	}

	return rtn;
}

int send_cmd_usbdown(void){

	int rtn = 0;

	sp < IServiceManager > sm = defaultServiceManager();
	sp < IBinder > binder = sm->getService(String16("service.usbcmd"));
	
	if(binder == 0)	return TRACEROUTE_BINDER_FAILED;
	
	sp<ICMDService> svc = interface_cast <ICMDService> (binder);
	sp<IBinder> clientBinder = svc->getClient()->asBinder();
	sp<ICMDClient> cs = interface_cast<ICMDClient>(clientBinder);


	rtn = cs->cmd_send(GPIO14_DOWN);
	if(rtn != 0){
		return CMD_FAILED;
	}

	return rtn;
}

