LOCAL_PATH := $(call my-dir)
 
include $(CLEAR_VARS)

LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libutils \
    libbinder \

LOCAL_MODULE    := liblog_client

LOCAL_SRC_FILES := \
    liblog_client.cpp \
    BpLOGService.cpp \
    BpLOGClient.cpp \
	../ILog/ILOG_Client.cpp \
	../ILog/ILOG_Service.cpp

LOCAL_MODULE_TAGS := optional
include $(BUILD_SHARED_LIBRARY)

