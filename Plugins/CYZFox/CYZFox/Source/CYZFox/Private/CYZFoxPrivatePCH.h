// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#include "Engine.h"

#include "CYZFoxModule.h"
#include "CYZUEFox.h"

// You should place include statements to your module's private header files here.  You only need to
// add includes for headers that are used in most of your module's source files though.

// #define FOXUE_DEBUG 1

#ifdef FOXUE_DEBUG
    #if PLATFORM_ANDROID
        #ifndef FOXUE_LOG
        #include <android/log.h>
        #define FOXUE_LOG(format, ...) __android_log_print(ANDROID_LOG_DEBUG, "FOXUE_LOG", format, ##__VA_ARGS__)
    #endif

    #elif PLATFORM_IOS
        #ifndef FOXUE_LOG
        #include <Foundation/Foundation.h>
        #define FOXUE_LOG(format, ...) NSLog(@"[FOXUE_LOG] " format, ##__VA_ARGS__)
    #endif

    #else
        #define FOXUE_LOG(...)
    #endif

#else
    #define FOXUE_LOG(...)
#endif
