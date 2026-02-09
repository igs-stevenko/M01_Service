#ifndef __LIBWD_CLIENT_H__
#define __LIBWD_CLIENT_H__

/* Error Code寫在另一份Header檔內 */
#include "error_code.h"

extern "C" {


/*
 *  Parm :
 *		How many secs for watchdog assert reboot if didn't call keepalive
 *		Once this function be called, it start watchdog service
 *	return value :
 *		0 : success
 *		<0 : error
 */
int send_cmd_init(int);



/*	
 *	return value :
 *		0 : success
 *		<0 : error
 */
int send_cmd_keepalive(void);

};
#endif
