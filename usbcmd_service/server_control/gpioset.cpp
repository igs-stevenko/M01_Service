#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>


int gpio14_up(void){
	
	int rtn = 0;
	int fd = 0;

	unsigned char buffer[] = "high";


	fd = open("/sys/class/gpio/gpio14/direction", O_RDWR);
	if(fd <= 0){
		return -1;
	}

	rtn = write(fd, buffer, strlen((const char *)buffer));
	if(rtn != strlen((const char *)buffer)){
		return -2;
	}

	if(fd)	close(fd);
		
	return 0;
}

int gpio14_down(void){
	
	int rtn = 0;
	int fd = 0;

	unsigned char buffer[] = "low";


	fd = open("/sys/class/gpio/gpio14/direction", O_RDWR);
	if(fd <= 0){
		return -1;
	}

	rtn = write(fd, buffer, strlen((const char *)buffer));
	if(rtn != strlen((const char *)buffer)){
		return -2;
	}

	if(fd)	close(fd);
	
	return 0;
}

