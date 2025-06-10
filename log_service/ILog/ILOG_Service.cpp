#include "ILOG_Service.h"

namespace android {

//IMPLEMENT_META_INTERFACE(LOGService, "android.igs.ILOGService");

const String16 ILOGService::descriptor("android.igs.ILOGService");

const String16& ILOGService::getInterfaceDescriptor() const {
    return ILOGService::descriptor;
}

ILOGService::ILOGService(void){
}

ILOGService::~ILOGService(void){
}


}  // namespace android

