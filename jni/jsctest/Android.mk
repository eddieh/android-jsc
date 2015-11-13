LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE    := libjsctest
LOCAL_SRC_FILES := jsctest.c

LOCAL_SHARED_LIBRARIES := libjs

include $(BUILD_SHARED_LIBRARY)
