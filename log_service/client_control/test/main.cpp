#include <stdio.h>
#include <stdlib.h>
#include <utils/Log.h>
#include <time.h>

#include "../liblog_client.h"

int main(void){

	int rtn = -1;

	unsigned char cmd;
	const char *json_payload =
		"{"
		"\"Version\":\"1.0\","
		"\"Timestamp\":1749017468,"
		"\"MachineId\":\"0012D8000004\","
		"\"GameType\":\"Fish\","
		"\"MachineGameId\":23,"
		"\"MachineName\":\"GoldenParadise\","
		"\"MachineVersion\":\"S103US\","
		"\"LogType\":\"CheckMachineState\","
		"\"Signature\":\"c265483f72f2bdead55a3cf3a0eb89f7902d3e34\","
		"\"Data\":{\"RandCode\":1467921495},"
		"\"Metadata\":{\"Location\":\"US\",\"USState\":\"UNKNOWN\"}"
		"}";

	const char *domain = "log.awp-skill.com";
	const char *url = "https://54.187.105.103/log";
	unsigned char ip[1024] = {0x00};

	printf("Process Start\n");
	printf("a. POST_LOG\n");
	printf("b. GET_IP\n");
	printf("c. Loo Post TEST\n");

	cmd = getchar();
	getchar();

	switch(cmd){

		case 'a':
		{
			unsigned char resData[1048576] = {0x00};
			int resDataLen = 0;
			rtn = send_cmd_post(url, json_payload, (char *)resData, &resDataLen);
			if(rtn != 0){
				printf("[ERROR] : send_cmd_post failed, rtn = %d\n", rtn);
				exit(1);
			}

			printf("resData = %s\n", resData);
			printf("resDataLen = %d\n", resDataLen);

			break;
		}
		case 'b':
			rtn = send_cmd_getip(domain, (char *)ip);
			if(rtn != 0){
				printf("[ERROR] : send_cmd_getip failed, rtn = %d\n", rtn);
				exit(1);
			}

			printf("ip = %s\n", ip);
			break;

		case 'c':
		{	
			unsigned char resData[1048576] = {0x00};
			int resDataLen = 0;
			int count = 0;
			while(1){
				
				memset(resData, 0, sizeof(resData));
				resDataLen = 0;

				rtn = send_cmd_post(url, json_payload, (char *)resData, &resDataLen);
				if(rtn != 0){
					printf("[ERROR] : send_cmd_post failed, rtn = %d\n", rtn);
					break;
				}

				printf("resData = %s\n", resData);
				printf("resDataLen = %d\n", resDataLen);

				count++;

				printf("count = %d\n", count);

				sleep(5);
			}
			break;
		}
		default:
			break;
	}

	return 0;
}




