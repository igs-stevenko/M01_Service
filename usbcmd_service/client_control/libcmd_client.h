#ifndef __LIBCMD_CLIENT_H__
#define __LIBCMD_CLIENT_H__

/* Error Code寫在另一份Header檔內 */
#include "error_code.h"

extern "C" {

/*	參數 : 
 *		resData : 執行traceroute後得到的字串，得到的回傳字串最長的長度是5K
 *		resDataLen : 執行traceroute後得到的字串長度
 *
 *	return value :
 *		0 : success
 *		1 : 執行traceroute指令錯誤
 *		2 : binder錯誤
 *		3 : 傳入的參數錯誤
 */
int send_cmd_usbup(void);
int send_cmd_usbdown(void);

};
#endif
