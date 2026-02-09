#include <utils/Log.h>

#include "BpWDClient.h"
#include "BpWDService.h"
#include "libwd_client.h"
#include <android/log.h>

int send_cmd_init(int count){

	int rtn = 0;

	sp < IServiceManager > sm = defaultServiceManager();
	sp < IBinder > binder = sm->getService(String16("service.igswd2"));
	
	if(binder == 0)	return BINDER_FAILED;
	
	sp<IWDService> svc = interface_cast <IWDService> (binder);
	sp<IBinder> clientBinder = svc->getClient()->asBinder();
	sp<IWDClient> cs = interface_cast<IWDClient>(clientBinder);

	cs->SetCount(count);

	rtn = cs->cmd_send(INIT);
	if(rtn != 0){
		return BINDER_FAILED;
	}

	return rtn;
}

int send_cmd_keepalive(void){

	int rtn = 0;

	sp < IServiceManager > sm = defaultServiceManager();
	sp < IBinder > binder = sm->getService(String16("service.igswd2"));
	
	if(binder == 0)	return BINDER_FAILED;
	
	sp<IWDService> svc = interface_cast <IWDService> (binder);
	sp<IBinder> clientBinder = svc->getClient()->asBinder();
	sp<IWDClient> cs = interface_cast<IWDClient>(clientBinder);

	rtn = cs->cmd_send(KEEPALIVE);
	if(rtn != 0){
		return BINDER_FAILED;
	}

	return rtn;
}

