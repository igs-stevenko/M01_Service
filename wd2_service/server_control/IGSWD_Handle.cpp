#include <getopt.h>
#include "WD_Service.h"

int main(int argc, char *argv[]) {

	sp < IServiceManager > sm = defaultServiceManager();
	sm->addService(String16("service.igswd2"), new WDService());
	ProcessState::self()->startThreadPool();
	IPCThreadState::self()->joinThreadPool();

	return 0;
}
