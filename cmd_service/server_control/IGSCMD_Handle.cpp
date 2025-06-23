#include <getopt.h>
#include "CMD_Service.h"

int main(int argc, char *argv[]) {

	sp < IServiceManager > sm = defaultServiceManager();
	sm->addService(String16("service.igscmd"), new CMDService());
	ProcessState::self()->startThreadPool();
	IPCThreadState::self()->joinThreadPool();

	return 0;
}
