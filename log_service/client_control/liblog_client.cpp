#include <utils/Log.h>

#include "BpLOGClient.h"
#include "BpLOGService.h"
#include "liblog_client.h"
#include <android/log.h>

int send_cmd_getip(const char *domain, char *ip){

	int rtn = 0;

	if(strlen(domain) == 0)
	  return 4;

	sp < IServiceManager > sm = defaultServiceManager();
	sp < IBinder > binder = sm->getService(String16("service.igslog"));
	
	if(binder == 0)	return GETIP_BINDER_FAILED;
	
	sp<ILOGService> svc = interface_cast <ILOGService> (binder);
	sp<IBinder> clientBinder = svc->getClient()->asBinder();
	sp<ILOGClient> cs = interface_cast<ILOGClient>(clientBinder);

	cs->setDomain(domain);

	rtn = cs->cmd_send(GET_IP);
	memcpy(ip, cs->getIP(), strlen(cs->getIP()) );

	return rtn;
}


int send_cmd_post(const char *url, const char *data, char *resData, int *resDataLen){

	int rtn = 0;

	if(strlen(url) == 0)
	  return 7;

	sp < IServiceManager > sm = defaultServiceManager();
	sp < IBinder > binder = sm->getService(String16("service.igslog"));
	
	if(binder == 0)	return POST_BINDER_FAILED;
		
	sp<ILOGService> svc = interface_cast <ILOGService> (binder);
	sp<IBinder> clientBinder = svc->getClient()->asBinder();
	sp<ILOGClient> cs = interface_cast<ILOGClient>(clientBinder);
	
	cs->setUrl(url);
	cs->setPost(data);

	rtn = cs->cmd_send(POST_LOG);

	memcpy(resData, cs->getData(), cs->getDataLen());
	*resDataLen = cs->getDataLen();
	
	return rtn;
}


