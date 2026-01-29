#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define BUFSIZE 5*1024

int do_command(const char *Cmd, unsigned char *RtnBuffer, int *RtnBufferLen){

	int rtn = 0;

    FILE *fp;
	char Buf[BUFSIZE] = {0x00};
    char PerBuffer[1024] = {0x00};
	int TotalLen = 0;
	int status = 0;
	int exit_code = -1;

    // 呼叫 busybox 的 ls 指令
    fp = popen(Cmd, "r");
    if (fp == NULL) {
        perror("popen failed");
        return -1;
    }

    // 讀取 busybox 輸出
    while (fgets(PerBuffer, sizeof(PerBuffer), fp) != NULL) {
		
		TotalLen += strlen(PerBuffer);
		if((unsigned int)TotalLen > sizeof(Buf)){	
			break;
		}

		strncat(Buf, PerBuffer, sizeof(Buf) - strlen(Buf) - 1);
		memset(PerBuffer, 0, sizeof(PerBuffer));
	}
		
	if((unsigned int)TotalLen > sizeof(Buf)){	
		return -2;
	}

    status = pclose(fp);
	
	if (WIFEXITED(status)) {
        exit_code = WEXITSTATUS(status);
    }

	if (exit_code == 0) {
		rtn = 0;
	} else {
		rtn = -3;
	}


	memcpy(RtnBuffer, Buf, strlen(Buf));
	*RtnBufferLen = strlen(Buf);

	return rtn;
}



int do_traceroute(unsigned char *RtnBuffer, int *RtnBufferLen){

	int rtn = 0;

	rtn = do_command("busybox traceroute 8.8.8.8 2>&1", RtnBuffer, RtnBufferLen);
	if(rtn < 0){
		printf("[ERROR] : do_command failed, rtn = %d\n", rtn);
		return -1;
	}

    return 0;

}

