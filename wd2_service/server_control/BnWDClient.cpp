#include "BnWDClient.h"

using namespace android;
namespace android
{

	BnWDClient::BnWDClient(void){

		printf("### [%s][%d] ###\n", __func__, __LINE__); 
		mWatchdog = new WatchdogThread();
		mWatchdog->run();
	}


	int BnWDClient::cmd_send(int mode) {
		return 0;
	}

	
	status_t BnWDClient::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags) {

		int rtn = 0;
		int error_flag = 0;

		printf("### [%s][%d] ###\n", __func__, __LINE__); 

		switch (code) {

			case INIT:
				{
					String8 PkgName;
					int TrigCount;
					
					mWatchdog->ClearNowCount();
					
					//PkgName = data.readString8();
					TrigCount = data.readInt32();

					//printf("[INFO] : PkgName = %s\n", PkgName.string());
					printf("[INFO] : TrigCount = %d\n", TrigCount);

					//mWatchdog->SetPkgName(PkgName.string());
					mWatchdog->SetTrigCount(TrigCount);

					mWatchdog->WatchdogStart();
					
					break;
				}
			case KEEPALIVE :
				{
					printf("---> KKEPALIVE <---\n");

					mWatchdog->ClearNowCount();

					break;
				}

			default:

				error_flag = 1;

				break;
		}

		return rtn;
	}
};
