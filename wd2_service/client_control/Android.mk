LOCAL_PATH := $(call my-dir)
 
include $(CLEAR_VARS)

LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libutils \
    libbinder \

LOCAL_MODULE    := libwd2_client

LOCAL_SRC_FILES := \
    libwd_client.cpp \
    BpWDService.cpp \
    BpWDClient.cpp \
	../IWD/IWD_Client.cpp \
	../IWD/IWD_Service.cpp

LOCAL_MODULE_TAGS := optional
include $(BUILD_SHARED_LIBRARY)

