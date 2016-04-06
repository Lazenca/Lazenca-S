LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

APP_PLATFORM := android-8

LOCAL_MODULE    := LazencaS
LOCAL_SRC_FILES := detect/Engine.c	

LOCAL_LDLIBS := -llog -landroid -lz

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)

APP_PLATFORM := android-8

LOCAL_MODULE    := LoadEngine
LOCAL_SRC_FILES := LoadEngine.c

LOCAL_CFLAGS    := -fvisibility=hidden

LOCAL_LDLIBS := -llog -landroid -lz

include $(BUILD_SHARED_LIBRARY)