#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <utils/Log.h>
#include <utils/threads.h>
#include <cutils/android_reboot.h>

#include "WatchdogThread.h"

#define TRIGGER_FILE "/media/game_trigger.flag"

namespace android{

	void CreateTriggerFile(void);
	void DetectTriggerFile(void);

	bool WatchdogThread::threadLoop(void){

		sleep(1);

		printf("### [%s][%d] ###\n", __func__, __LINE__); 


		if(Start == false){
			return true;
		}
		
		int NCount = GetNowCount();
		int TCount = GetTrigCount();

		if(NCount >= TCount){

			
			CreateTriggerFile();
			DetectTriggerFile();
			Start = false;
			android_reboot(ANDROID_RB_RESTART, 0, 0);
		}

		AddNowCount();

		printf("Now Count %d\n", NCount);
		printf("Trig Count %d\n", TCount);

		return true;
	}

	void WatchdogThread::SetPkgName(const char *Src){

		sprintf((char *)PkgName, "%s", Src);
	}

	void WatchdogThread::WatchdogStart(void){

		Start = true;
	}

	int WatchdogThread::GetNowCount(void){
		
		return NowCount;
	}

	void WatchdogThread::ClearNowCount(void){
		
		Mutex::Autolock _l(mLockNowCount);	
		NowCount = 0;
	}

	void WatchdogThread::AddNowCount(void){
		Mutex::Autolock _l(mLockNowCount);	
		NowCount++;
	}
	
	int WatchdogThread::GetTrigCount(void){
		
		return TriggerCount;
	}

	void WatchdogThread::SetTrigCount(int Count){
		
		Mutex::Autolock _l(mLockTrigCount);	
		TriggerCount = Count;
	}

	void CreateTriggerFile(void){

		int fd;

		fd = open(TRIGGER_FILE, O_RDWR | O_CREAT | O_SYNC, 0777);
		if(fd <= 0){
			printf("### [%s][%d] ###\n", __func__, __LINE__); 
			return;
		}

		close(fd);
	}

	void DetectTriggerFile(void){

		struct stat st;

		while(1){

			if(stat(TRIGGER_FILE, &st) != 0){
				break;
			}

			sleep(1);
		}
	}
}
