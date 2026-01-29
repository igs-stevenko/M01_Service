#include "ICMD_Client.h"

namespace android {


const String16 ICMDClient::descriptor("android.igs.ICMDClient");

const String16& ICMDClient::getInterfaceDescriptor() const {
    return ICMDClient::descriptor;
}

ICMDClient::ICMDClient(void){
}

ICMDClient::~ICMDClient(void){
}


}  // namespace android

