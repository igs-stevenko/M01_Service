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

#include "libfactlog.h"

#define BUFFER_SIZE 2

int LogWrite(const char *filename, unsigned char *buf, int len){
	
	int rtn = 0;
	int fd = 0;

	fd = open(filename, O_RDWR | O_SYNC | O_CREAT | O_TRUNC, 0777);
	if(fd <= 0){
		printf("open %s fialed\n");
		return -1;
	}

	

	int remain = len;
	int write_len = 0;
	int write_total_len = 0;
	unsigned char *ptr = buf;
	int ptr_off = 0;

	while(remain > 0){
	
		if(remain > BUFFER_SIZE){
			write_len = BUFFER_SIZE;
		}
		else{
			write_len = remain;
		}

		rtn = write(fd, ptr+ptr_off, write_len);
		if(rtn < 0){
			printf("[ERROR] : write failed\n");
			rtn = -2;
			break;
		}
		else if(rtn == 0){
			break;
		}
	
		write_total_len += write_len;
		remain -= write_len;
		ptr_off += write_len;
	}

	if(rtn >= 0){
		rtn = write_total_len;
	}

	if(fd)	close(fd);

	return rtn;
}


int GetFileSize(const char *filename){

	int fd;
	int file_size;
	fd = open(filename, O_RDWR);
	if(fd <= 0){
		printf("open %s fialed\n");
		return -1;
	}

	file_size = lseek(fd, 0, SEEK_END);

	if(fd)	close(fd);

	return file_size;
}

int LogRead(const char *filename, unsigned char *buf, int len){
	
	int rtn = 0;
	int fd = 0;

	fd = open(filename, O_RDWR | O_SYNC);
	if(fd <= 0){
		printf("open %s fialed\n");
		return -1;
	}

	int remain = len;
	int read_len = 0;
	int read_total_len = 0;
	unsigned char *ptr = buf;
	int ptr_off = 0;

	while(remain > 0){
	
		if(remain > BUFFER_SIZE){
			read_len = BUFFER_SIZE;
		}
		else{
			read_len = remain;
		}

		rtn = read(fd, ptr+ptr_off, read_len);
		if(rtn < 0){
			printf("[ERROR] : write failed\n");
			rtn = -2;
			break;
		}
		else if(rtn == 0){
			break;
		}
		
		read_total_len += read_len;
		remain -= read_len;
		ptr_off += read_len;
	}

	if(rtn >= 0)
	  rtn = read_total_len;

	if(fd)	close(fd);

	return rtn;
}


																																				 
