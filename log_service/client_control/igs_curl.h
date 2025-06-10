#ifndef __CURL_H__
#define __CURL_H__

enum{
	
	CURL_POST_FAILED = 1,
	GET_DATALEN_FAILED,
	

};

int PostData(char *url, char *postData, char *resData, int *resDataLen);

#endif
