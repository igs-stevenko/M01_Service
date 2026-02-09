#include <stdio.h>
#include <stdlib.h>
#include <utils/Log.h>
#include <time.h>
#include <string.h>

#include "../client_control/libwd_client.h"

#define BUFSIZE 5*1024

int main(void){

	int rtn = -1;
	unsigned char cmd;

	printf("Process Start\n");

	srand(time(NULL));

	while(1){

		printf("a. Init\n");
		printf("b. KeepAlive\n");
		printf("c. Loop KeepAlive\n");

		cmd = getchar();
		getchar();

		switch(cmd){

			case 'a':
			{
				rtn = send_cmd_init(30);
				if(rtn != 0){
					printf("send_cmd_init failed\n");
				}

			}

			case 'b':
			{
				rtn = send_cmd_keepalive();
				if(rtn != 0){
					printf("send_cmd_keepalive failed\n");
				}
				break;
			}

			case 'c':
			{
				rtn = send_cmd_init(30);
				if(rtn != 0){
					printf("send_cmd_init failed\n");
				}

				sleep(1);

				while(1){

					sleep(3);

					rtn = send_cmd_keepalive();
					if(rtn != 0){
						printf("send_cmd_keepalive failed\n");
						break;
					}
				}
				break;
			}


			default:
				break;
		}
	}
	return 0;
}




