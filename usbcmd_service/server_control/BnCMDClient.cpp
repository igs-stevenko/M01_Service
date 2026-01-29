#include "BnCMDClient.h"
#include "do_command.h"
#include "gpioset.h"

namespace android
{

	int BnCMDClient::cmd_send(int mode) {
		return 0;
	}
	
	status_t BnCMDClient::onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags) {

		int rtn = 0;
		int error_flag = 0;

		switch (code) {

			case REMOVE_CACHE:
			{	
				printf("---> REMOVE_CACHE <---\n");
				
				break;
			}
			case GPIO14_UP:
			{
				printf("---> GPIO14_UP <---\n");
				gpio14_up();
				break;
			}
			case GPIO14_DOWN:
			{
				printf("---> GPIO14_DOWN <---\n");
				gpio14_down();
				break;
			}
			default:

				error_flag = 1;

				break;
		}

		return rtn;
	}
};
