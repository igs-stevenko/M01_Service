#include "ICMD_Service.h"

namespace android {


const String16 ICMDService::descriptor("android.igs.ICMDService");

const String16& ICMDService::getInterfaceDescriptor() const {
    return ICMDService::descriptor;
}

ICMDService::ICMDService(void){
}

ICMDService::~ICMDService(void){
}


}  // namespace android

