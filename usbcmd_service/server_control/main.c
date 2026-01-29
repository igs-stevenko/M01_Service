#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 5*1024
int do_command(const char *Cmd, unsigned char *RtnBuffer, int *RtnBufferLen){

	int rtn = 0;

    FILE *fp;
	char Buf[BUFSIZE] = {0x00};
    char PerBuffer[1024] = {0x00};
	int TotalLen = 0;

    // 呼叫 busybox 的 ls 指令
    fp = popen(Cmd, "r");
    if (fp == NULL) {
        perror("popen failed");
        return -1;
    }

    // 讀取 busybox 輸出
    while (fgets(PerBuffer, sizeof(PerBuffer), fp) != NULL) {
		
		TotalLen += strlen(PerBuffer);
		if(TotalLen > sizeof(Buf)){	
			break;
		}

		strncat(Buf, PerBuffer, sizeof(Buf) - strlen(Buf) - 1);
		memset(PerBuffer, 0, sizeof(PerBuffer));
	}
		
	if(TotalLen > sizeof(Buf)){	
		return -2;
	}

    pclose(fp);

	memcpy(RtnBuffer, Buf, strlen(Buf));
	*RtnBufferLen = strlen(Buf);

	return rtn;
}


int main(void){

	int rtn = 0;
	char RtnBuffer[BUFSIZE] = {0x00};
	int RtnBufferLen = 0;



	rtn = do_command("busybox traceroute 8.8.8.8", RtnBuffer, &RtnBufferLen);
	if(rtn < 0){
		printf("[ERROR] : do_command failed, rtn = %d\n", rtn);
		exit(EXIT_FAILURE);
	}

	printf("RtnBuffer : \n");
	printf("%s", RtnBuffer);
	

	printf("RtnBufferLen : %d\n", RtnBufferLen);

    return 0;

}


