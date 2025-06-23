#include "BnCMDClient.h"
#include "do_command.h"

namespace android
{

	static unsigned char CmdResData[5120] = {0x00};

	void BnCMDClient::SetShellCmd(const char *shellcmd){
	}
	
	const char* BnCMDClient::GetCmdResData(){
		return NULL;
	}

	int BnCMDClient::GetCmdResDataLen(){
		return 0;
	}
	
	int BnCMDClient::cmd_send(int mode) {
		return 0;
	}
	
	status_t BnCMDClient::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags) {

		int rtn = 0;
		int error_flag = 0;

		printf("### [%s][%d] ###\n", __func__, __LINE__); 
		//CHECK_INTERFACE(ICMDService, data, reply);

		switch (code) {


			case EXECUTE_CMD :
				{
					printf("---> EXECUTE_CMD <---\n");

					int len;
					String8 ShellCmd;
					String8 ResData;

					ShellCmd = data.readString8();

					printf("[INFO] : ShellCmd = %s\n", ShellCmd.string());

					memset(CmdResData, 0, sizeof(CmdResData));

					rtn = do_command(ShellCmd.string(), CmdResData, &len);
					if(rtn != 0){
						rtn = 1;
					}

					ResData.setTo((const char *)CmdResData);
					reply->writeString8(ResData);
					reply->writeInt32(len);
					reply->writeInt32(rtn);

					break;
				}

			default:

				error_flag = 1;

				break;
		}

		return rtn;
	}
};
