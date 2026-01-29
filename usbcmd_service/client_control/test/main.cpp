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
	printf("a. usb up\n");
	printf("b. usb down\n");
	printf("c. loop test\n");

	cmd = getchar();
	getchar();

	switch(cmd){

		case 'a':
		{
			rtn = send_cmd_usbup();
			printf("rtn = %d\n", rtn);
			break;
		}
		case 'b':
		{
			rtn = send_cmd_usbdown();
			printf("rtn = %d\n", rtn);
			break;
		}
		case 'c':
		{
			while(1){
				rtn = send_cmd_usbup();
				if(rtn != 0){
					printf("rtn = %d\n", rtn);
					break;
				}	

				sleep(10);
				
				rtn = send_cmd_usbdown();
				if(rtn != 0){
					printf("rtn = %d\n", rtn);
					break;
				}

				sleep(10);
			}
			break;
		}

		default:
			break;
	}

	return 0;
}




