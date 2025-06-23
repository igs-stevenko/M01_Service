LOCAL_PATH := $(call my-dir)
 
include $(CLEAR_VARS)

LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libutils \
    libbinder \

LOCAL_MODULE    := igs_cmd_service

LOCAL_CPPFLAGS += -std=c++11
LOCAL_STATIC_LIBRARIES := libstdc++

LOCAL_CFLAGS += -Wno-unused-parameter
LOCAL_CFLAGS += -Wno-unused-label
LOCAL_CFLAGS += -Wno-unused-variable
LOCAL_CFLAGS += -Wno-unused-function

LOCAL_SRC_FILES := \
    BnCMDService.cpp \
    BnCMDClient.cpp \
    IGSCMD_Handle.cpp \
	../ICmd/ICMD_Service.cpp \
	../ICmd/ICMD_Client.cpp \
	do_command.cpp

LOCAL_MODULE_TAGS := optional
include $(BUILD_EXECUTABLE)
