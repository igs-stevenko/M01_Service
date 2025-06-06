#include <getopt.h>
#include "LOG_Service.h"


int main(int argc, char *argv[]) {

	sp < IServiceManager > sm = defaultServiceManager();
	sm->addService(String16("service.igslog"), new BnLOGService());
	ProcessState::self()->startThreadPool();
	IPCThreadState::self()->joinThreadPool();

	return 0;
}
