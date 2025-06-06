#include <utils/Log.h>

#include "LOG_Client.h"
#include "liblog_client.h"
#include <android/log.h>

int send_cmd_getip(const char *domain, char *ip){

	int rtn = 0;
	
	sp < IServiceManager > sm = defaultServiceManager();
	sp < IBinder > binder = sm->getService(String16("service.igslog"));
	
	if(binder == 0)	return -GETIP_BINDER_FAILED;
	
	sp<ILOGClient> cs = interface_cast < ILOGClient > (binder);

	cs->domain.setTo(domain);

	rtn = cs->cmd_send(GET_IP);

	memcpy(ip, cs->ip.string(), strlen(cs->ip.string()));

	return rtn;
}


int send_cmd_post(const char *url, const char *data, char *resData, int *resDataLen){

	int rtn = 0;
	
	sp < IServiceManager > sm = defaultServiceManager();
	sp < IBinder > binder = sm->getService(String16("service.igslog"));
	
	if(binder == 0)	return -POST_BINDER_FAILED;
	
	sp<ILOGClient> cs = interface_cast < ILOGClient > (binder);

	cs->url.setTo(url);
	cs->postdata.setTo(data);

	rtn = cs->cmd_send(POST_LOG);

	memcpy(resData, cs->resData.string(), cs->resDataLen);
	*resDataLen = cs->resDataLen;

	return rtn;
}


