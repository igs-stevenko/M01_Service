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

using namespace android;
namespace android{

	class WatchdogThread : public Thread {

		public :

			WatchdogThread(){
				Start = false;
			};
			~WatchdogThread(){
			};

			void WatchdogStart(void);
			void SetPkgName(const char *);
			int GetNowCount(void);
			void ClearNowCount(void);
			void AddNowCount(void);
			int GetTrigCount(void);
			void SetTrigCount(int);

		private:

			bool threadLoop();
			bool Start;
			int TriggerCount;
			int NowCount;
			Mutex mLockTrigCount;
			Mutex mLockNowCount;
			unsigned char PkgName[128];

	};
}

