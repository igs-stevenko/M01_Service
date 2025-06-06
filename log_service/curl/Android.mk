LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE:=curl_test

LOCAL_SRC_FILES:=curl.cpp 

LOCAL_SHARED_LIBRARIES:= \
	libutils \
	libcutils \

LOCAL_LDFLAGS := $(LOCAL_PATH)/lib/libcurl.a

LOCAL_CFLAGS += -Wno-unused-parameter
LOCAL_CFLAGS += -Wno-unused-label
LOCAL_CFLAGS += -Wno-unused-variable

LOCAL_STATIC_LIBRARIES += libz
LOCAL_LDLIBS += -lz
LOCAL_CPPFLAGS += -std=c++11
LOCAL_STATIC_LIBRARIES := libstdc++

include $(BUILD_EXECUTABLE)


include $(CLEAR_VARS)
LOCAL_MODULE := libcurl_static
LOCAL_SRC_FILES := libs/libcurl.a
LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
include $(PREBUILT_STATIC_LIBRARY)
