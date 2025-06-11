#ifndef __LIBLOG_CLIENT_H__
#define __LIBLOG_CLIENT_H__

/* Error Code寫在另一份Header檔內 */
#include "error_code.h"

extern "C" {

/*	return value :
 *	SUCCESS = 0
 *	CURL_POST_FAILED = 1
 *	GET_DATALEN_FAILED = 2
 *	POST_BINDER_FAILED = 3
 *	NULL_URL = 4
 */
int send_cmd_post(const char *url, const char *data, char *resData, int *resDataLen);



/*
 * return value
 * SUCCESS = 0
 * SOCKET_FAILED = 1
 * SET_TIMEOUT_FAILED = 2
 * SET_BINDTODEVICE_FAILED = 3
 * SEND_FAILED = 4
 * RECV_FAILED = 5
 * GETIP_BINDER_FAILED = 6
 * NULL_DOMAIN = 7
 * */
int send_cmd_getip(const char *domain, char *ip);
};
#endif
