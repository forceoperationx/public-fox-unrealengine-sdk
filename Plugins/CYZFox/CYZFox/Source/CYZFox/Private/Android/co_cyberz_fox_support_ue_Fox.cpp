// F.O.X SDK
// co_cyberz_fox_support_ue_Fox.cpp
//
// Created by T.Hiraga
//
#include "CYZFoxPrivatePCH.h"
#if PLATFORM_ANDROID
#include <jni.h>
#include "co_cyberz_fox_support_ue_Fox.h"
#include "FoxNativeTrackListener.h"
#include "CYZUEFox.h"

using namespace fox;

JNIEXPORT void JNICALL Java_co_cyberz_fox_support_ue_Fox_onCompleted
  (JNIEnv * env, jobject thiz, jlong delegate) {
    FoxNativeTrackListener* listener = reinterpret_cast<FoxNativeTrackListener*>(delegate);
    if (listener != nullptr) listener->onInstallComplete();
}
#endif
