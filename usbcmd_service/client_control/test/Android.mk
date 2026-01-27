LOCAL_PATH := $(call my-dir)
 
include $(CLEAR_VARS)

LOCAL_SHARED_LIBRARIES := \
	libusbcmd_client \
	libcutils \
	libutils \

LOCAL_MODULE    := igs_usbcmd_client

LOCAL_SRC_FILES := \
    main.cpp
   
LOCAL_MODULE_TAGS := optional
include $(BUILD_EXECUTABLE)

