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
 *		0 : success
 *		< 0 : 錯誤
 */


int send_cmd_traceroute(char *resData, int *resDataLen);


/*	參數 : 
 *		PkgName : 遊戲的PackageName
 *
 *	return value :
 *		0 : success
 *		< 0 : 錯誤
 */

int send_cmd_cleargamecache(const char *PkgName);

};
#endif
