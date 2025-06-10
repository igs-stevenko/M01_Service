#ifndef __GETIP_H__
#define __GETIP_H__

int getip(char *hostname, char *ip);

enum {

	SOCKET_FAILED=1,
	SET_TIMEOUT_FAILED,
	SET_BINDTODEVICE_FAILED,
	SEND_FAILED,
	RECV_FAILED

};

#endif
