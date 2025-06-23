#include <stdio.h>
#include <stdlib.h>
#include <utils/Log.h>
#include <time.h>

#include "../libcmd_client.h"

#define BUFFER_LEN 1024*5

int main(void){

	int rtn = -1;

	unsigned char cmd;

	printf("Process Start\n");
	printf("a. busybox traceroute 8.8.8.8\n");

	cmd = getchar();
	getchar();

	switch(cmd){

		case 'a':
		{
			unsigned char resData[BUFFER_LEN] = {0x00};
			int resDataLen = 0;
			rtn = send_cmd_traceroute((char *)resData, &resDataLen);
			if(rtn != 0){
				printf("[ERROR] : send_cmd_traceroute rtn = %d\n", rtn);
				exit(1);
			}

			printf("resData = %s\n", resData);
			printf("resDataLen = %d\n", resDataLen);

			break;
		}

		default:
			break;
	}

	return 0;
}




