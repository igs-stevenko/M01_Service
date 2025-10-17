LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE:=libfactlog

LOCAL_SRC_FILES:=libfactlog.c

LOCAL_SHARED_LIBRARIES:= \
	libutils \
	libcutils \

LOCAL_CFLAGS += -Wno-unused-parameter
LOCAL_CFLAGS += -Wno-unused-label
LOCAL_CFLAGS += -Wno-unused-variable

include $(BUILD_SHARED_LIBRARY)


