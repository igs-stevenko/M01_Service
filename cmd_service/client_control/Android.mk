LOCAL_PATH := $(call my-dir)
 
include $(CLEAR_VARS)

LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libutils \
    libbinder \

LOCAL_MODULE    := libcmd_client

LOCAL_SRC_FILES := \
    libcmd_client.cpp \
    BpCMDService.cpp \
    BpCMDClient.cpp \
	../ICmd/ICMD_Client.cpp \
	../ICmd/ICMD_Service.cpp

LOCAL_MODULE_TAGS := optional
include $(BUILD_SHARED_LIBRARY)

