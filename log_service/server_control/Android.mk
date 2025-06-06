LOCAL_PATH := $(call my-dir)
 
include $(CLEAR_VARS)

LOCAL_SHARED_LIBRARIES := \
    libcutils \
    libutils \
    libbinder \

LOCAL_MODULE    := igs_log_service

LOCAL_LDFLAGS := $(LOCAL_PATH)/curl/lib/libcurl.a
LOCAL_STATIC_LIBRARIES += libz
LOCAL_LDLIBS += -lz
LOCAL_CPPFLAGS += -std=c++11
LOCAL_STATIC_LIBRARIES := libstdc++

LOCAL_SRC_FILES := \
    LOG_Service.cpp \
    IGSLOG_Handle.cpp \
	getip.cpp \
	igs_curl.cpp

LOCAL_MODULE_TAGS := optional
include $(BUILD_EXECUTABLE)
