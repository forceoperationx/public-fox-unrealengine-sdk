// F.O.X SDK
// co_cyberz_fox_support_ue_Fox.h
//
// Created by T.Hiraga
//
#ifndef _Inluded_co_cyberz_fox_support_ue_Fox
#define _Inluded_co_cyberz_fox_support_ue_Fox
#include <jni.h>
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL Java_co_cyberz_fox_support_ue_Fox_onCompleted
  (JNIEnv * env, jobject thiz, jlong delegate);

#ifdef __cplusplus
}
#endif
#endif
