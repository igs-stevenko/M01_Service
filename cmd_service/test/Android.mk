LOCAL_PATH := $(call my-dir)
 
include $(CLEAR_VARS)

LOCAL_SHARED_LIBRARIES:= \
	libcmd_client \
	libcutils \
	libutils \

LOCAL_MODULE:= igs_cmd_client

LOCAL_SRC_FILES:= \
    main.cpp
   
LOCAL_CFLAGS += -Wno-unused-parameter
LOCAL_CFLAGS += -Wno-unused-label
LOCAL_CFLAGS += -Wno-unused-variable
LOCAL_CFLAGS += -Wno-unused-function
LOCAL_CFLAGS += -Wno-unused-private-field
include $(BUILD_EXECUTABLE)

