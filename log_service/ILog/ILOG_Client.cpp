#include "ILOG_Client.h"

namespace android {

//IMPLEMENT_META_INTERFACE(LOGClient, "android.igs.ILOGClient");

const String16 ILOGClient::descriptor("android.igs.ILOGClient");

const String16& ILOGClient::getInterfaceDescriptor() const {
    return ILOGClient::descriptor;
}

ILOGClient::ILOGClient(void){
}

ILOGClient::~ILOGClient(void){
}


}  // namespace android

