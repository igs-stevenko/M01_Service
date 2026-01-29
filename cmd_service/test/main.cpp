#include <stdio.h>
#include <stdlib.h>
#include <utils/Log.h>
#include <time.h>
#include <string.h>

#include "../client_control/libcmd_client.h"

#define BUFSIZE 5*1024

int main(void){

	int rtn = -1;
	unsigned char cmd;

	printf("Process Start\n");

	srand(time(NULL));

	while(1){

		printf("a. TraceRoute----\n");
		printf("b. Clear Game Cache\n");

		cmd = getchar();
		getchar();

		switch(cmd){

			case 'a':
			{
				char resData[BUFSIZE] = {0x00};
				int RtnBufferLen = 0;
				rtn = send_cmd_traceroute(resData, &RtnBufferLen);
				if(rtn != 0){
					printf("send_cmd_traceroute failed\n");
				}
				else{
					printf("RtnBufferLen = %d\n", RtnBufferLen);
					printf("%s\n", resData);
				}
				break;
			}
			case 'b':
			{
				rtn = send_cmd_cleargamecache("com.IGS.MedalTower");
				if(rtn != 0){
					printf("send_cmd_cleargamecache failed\n");
				}

				break;
			}

			default:
				break;
		}
	}
	return 0;
}




