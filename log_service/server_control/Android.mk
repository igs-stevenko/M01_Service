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

LOCAL_CFLAGS += -Wno-unused-parameter
LOCAL_CFLAGS += -Wno-unused-label
LOCAL_CFLAGS += -Wno-unused-variable
LOCAL_CFLAGS += -Wno-unused-function

LOCAL_SRC_FILES := \
    BnLOGService.cpp \
    BnLOGClient.cpp \
    IGSLOG_Handle.cpp \
	getip.cpp \
	igs_curl.cpp \
	../ILog/ILOG_Service.cpp \
	../ILog/ILOG_Client.cpp

LOCAL_MODULE_TAGS := optional
include $(BUILD_EXECUTABLE)
