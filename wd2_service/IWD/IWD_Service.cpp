#include "IWD_Service.h"

namespace android {


const String16 IWDService::descriptor("android.igs.IWDService");

const String16& IWDService::getInterfaceDescriptor() const {
    return IWDService::descriptor;
}

IWDService::IWDService(void){
}

IWDService::~IWDService(void){
}


}  // namespace android

