#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <unistd.h>


#include "../libfactlog.h"

int main(int argc, char** argv)
{

	int rtn = 0;
	unsigned char cmd;
	unsigned char buf[8192];
	

	printf("a. write buffer\n");
	printf("b. read  buffer\n");

	cmd = getchar();

	switch(cmd){

		case 'a':

			sprintf(buf, "AAABBBCCCDDD\nEEEFFFFGGGHHH\nIIIJJJKKKLLL\nMMMNNNOOOPPP\nQQQRRRSSSTTT\nUUVVVWWWXXXYYYZZZ\naaabbbcccddd\neeefffggghhh\niiijjjkkklll\nmmmnnnoooppp\nqqqrrrsssttt\nuuuvvvwwwxxxyyyzzz\n");

			rtn = LogWrite("/media/log.txt", buf, strlen(buf));
			if(rtn < 0){
				printf("[ERROR] : LogWrite faield\n");
			}
			else{
				printf("[INFO] : LogWrite rtn = %d\n", rtn);
			}

			break;

		case 'b':
		{
			int read_size;

			read_size = GetFileSize("/media/log.txt");
			if(read_size <= 0){
				printf("[ERROR] : read_size = %d\n");
				break;
			}

			printf("read_size = %d\n", read_size);

			rtn = LogRead("/media/log.txt", buf, read_size);
			if(rtn < 0){
				printf("[ERROR] : LogWrite faield\n");
			}
			else{
				printf("[INFO] : LogWrite rtn = %d\n", rtn);
			}

			printf("[INFO] : read : \n");
			printf("%s\n", buf);

			break;
		}
		default:
			break;
	}

	return 0;
}
																																					 
	
