#include "IWD_Client.h"

namespace android {


const String16 IWDClient::descriptor("android.igs.IWDClient");

const String16& IWDClient::getInterfaceDescriptor() const {
    return IWDClient::descriptor;
}

IWDClient::IWDClient(void){
}

IWDClient::~IWDClient(void){
}


}  // namespace android

