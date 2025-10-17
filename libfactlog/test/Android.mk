LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE:=test_factlog

LOCAL_SRC_FILES:=main.c

LOCAL_SHARED_LIBRARIES:= \
	libutils \
	libcutils \
	libfactlog \

LOCAL_CFLAGS += -Wno-unused-parameter
LOCAL_CFLAGS += -Wno-unused-label
LOCAL_CFLAGS += -Wno-unused-variable

include $(BUILD_EXECUTABLE)

