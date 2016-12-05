#include "CYZFoxPrivatePCH.h"
#include "Json.h"
#if PLATFORM_ANDROID
#include "FoxJniHelper.h"
#include "CYZUEFoxUtil.h"
#include "FoxNativeTrackListener.h"
#include <android/log.h>
#include <string>
#include <string.h>
#define LOG_TAG ("CYZFox")
#endif

namespace fox {
#if PLATFORM_ANDROID
  FoxNativeTrackListener* CYZUEFox::foxTracklistener;
#endif

  void CYZUEFox::activate(CYZUEFoxConfig config)
  {
    #if PLATFORM_ANDROID
    jobject activity = FoxJniHelper::getActivity();
    FoxJniMethodInfo minfo;
    bool exists = FoxJniHelper::getStaticMethodInfo(minfo,
                                                    "co/cyberz/fox/support/ue/Fox",
                                                    "init",
                                                    "(Landroid/content/Context;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Z)V"
                                                   );
    if (exists) {
      int appId = config.androidAppId;
      jstring appKey = minfo.env->NewStringUTF(config.androidAppKey);
      jstring appSalt = minfo.env->NewStringUTF(config.androidSalt);
      jstring foxServerURL = minfo.env->NewStringUTF(config.foxServerURL);
      jstring analyticsServerURL = minfo.env->NewStringUTF(config.analyticsServerURL);
      jboolean isDebug = (jboolean)config.debugMode;
      minfo.env->CallStaticVoidMethod(minfo.classID,
                                      minfo.methodID,
                                      activity,
                                      appId,
                                      appKey,
                                      appSalt,
                                      foxServerURL,
                                      analyticsServerURL,
                                      isDebug);
    }
    #endif
  }

  void CYZUEFox::trackInstall()
  {
    #if PLATFORM_ANDROID
    FoxJniMethodInfo minfo;
    bool exists = FoxJniHelper::getStaticMethodInfo(
                                                    minfo,
                                                    "co/cyberz/fox/support/ue/Fox",
                                                    "trackInstall",
                                                    "()V"
                                                   );
    if (exists) minfo.env->CallStaticVoidMethod(minfo.classID,minfo.methodID);
    #endif
  }

  void CYZUEFox::trackInstall(CYZUEFoxTrackOption option)
  {
    #if PLATFORM_ANDROID
    FoxJniMethodInfo minfo;
    bool exists = FoxJniHelper::getStaticMethodInfo(
                                                    minfo,
                                                    "co/cyberz/fox/support/ue/Fox",
                                                    "trackInstall",
                                                    "(Ljava/lang/String;Ljava/lang/String;ZJ)V"
                                                   );
    if (exists) {
      jstring redirectUrl = minfo.env->NewStringUTF(option.redirectURL);
      jstring buid = minfo.env->NewStringUTF(option.buid);
      jboolean isOptOut = (jboolean)option.optout;
      foxTracklistener = new FoxNativeTrackListener(option.onInstallComplete);
      jlong delegate = (jlong)(unsigned long long) foxTracklistener;
      minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, redirectUrl, buid, isOptOut, delegate);
    }
    #endif
  }


  void CYZUEFox::trackSession()
  {
    #if PLATFORM_ANDROID
    FoxJniMethodInfo minfo;
    bool exists = FoxJniHelper::getStaticMethodInfo(minfo,
                                                    "co/cyberz/fox/support/ue/Fox",
                                                    "trackSession",
                                                    "()V"
                                                   );
    if (exists) {
      minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID);
    }
    #endif
  }

  void CYZUEFox::trackEvent(CYZUEFoxEvent* event)
  {
    #if PLATFORM_ANDROID
    if (event == nullptr) return;
    JNIEnv *env = FoxJniHelper::getEnv();
    int ltvId = event->ltvId;
    jstring buid = env->NewStringUTF(event->buid);
    jdouble price = (jdouble) event->price;
    jstring sku = env->NewStringUTF(event->sku);
    jstring currency = env->NewStringUTF(event->currency);
    jstring eventName = env->NewStringUTF(event->eventName);
    int value = event->eventValue;
    jstring orderId = env->NewStringUTF(event->orderId);
    jstring itemName = env->NewStringUTF(event->itemName);
    int quantity = event->quantity;
    FString cEventInfo = CYZUEFoxUtil::json2FString(event->eventInfo);
    jstring eventInfo = (jstring)env->NewStringUTF(TCHAR_TO_UTF8(*cEventInfo));
    const char* cExtraInfo = event->getExtraInfoStr();
    jstring extraInfo = env->NewStringUTF(cExtraInfo);

    FoxJniMethodInfo minfo;
    std::string args;
    args.append("(")
        .append("I")                  // ltvId
        .append("Ljava/lang/String;") // buid
        .append("D")                  // price
        .append("Ljava/lang/String;") // sku
        .append("Ljava/lang/String;") // currency
        .append("Ljava/lang/String;") // eventName
        .append("I")                  // value
        .append("Ljava/lang/String;") // orderId
        .append("Ljava/lang/String;") // itemName
        .append("I")                  // quantity
        .append("Ljava/lang/String;") // eventInfo
        .append("Ljava/lang/String;") // extraInfo
        .append(")V");

    bool exists = FoxJniHelper::getStaticMethodInfo(minfo,
                                                    "co/cyberz/fox/support/ue/Fox",
                                                    "trackEvent",
                                                    args.c_str()
                                                   );
    if (exists) {
      minfo.env->CallStaticVoidMethod(minfo.classID,
                                      minfo.methodID,
                                      ltvId,
                                      buid,
                                      price,
                                      sku,
                                      currency,
                                      eventName,
                                      value,
                                      orderId,
                                      itemName,
                                      quantity,
                                      eventInfo,
                                      extraInfo);

    }


    #endif
  }

  bool CYZUEFox::isConversionCompleted()
  {
    bool isCompleted = false;
    #if PLATFORM_ANDROID
    FoxJniMethodInfo minfo;
    bool exists = FoxJniHelper::getStaticMethodInfo(
                                                  minfo,
                                                  "co/cyberz/fox/support/ue/Fox",
                                                  "isConversionCompleted",
                                                  "()Z"
                                                  );
    if (exists) {
      isCompleted = minfo.env->CallStaticBooleanMethod(minfo.classID, minfo.methodID);
    }
    #endif
    return isCompleted;
  }

  /**
   * ブラウザで計測
   */
  void CYZUEFox::trackEventByBrowser(const char* url)
  {
    #if PLATFORM_ANDROID
    FoxJniMethodInfo minfo;
    bool exists = FoxJniHelper::getStaticMethodInfo(
                                                  minfo,
                                                  "co/cyberz/fox/support/ue/Fox",
                                                  "trackEventByBrowser",
                                                  "(Ljava/lang/String;)V"
                                                  );
    if (exists) {
      jstring jUrl = minfo.env->NewStringUTF(url);
      minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, jUrl);
    }
    #endif
  }

  /**
   * ユーザー情報セット
   */
  void CYZUEFox::setUserInfo(TSharedPtr<FJsonObject> userInfo)
  {
    #if PLATFORM_ANDROID
    FoxJniMethodInfo minfo;
    bool exists = FoxJniHelper::getStaticMethodInfo(
                                                  minfo,
                                                  "co/cyberz/fox/support/ue/Fox",
                                                  "setUserInfo",
                                                  "(Ljava/lang/String;)V"
                                                  );
    if (exists) {
      FString userInfoStr = CYZUEFoxUtil::json2FString(userInfo);
      jstring jUserInfo = minfo.env->NewStringUTF(TCHAR_TO_UTF8(*userInfoStr));
      minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID, jUserInfo);
    }
    #endif
  }

  TSharedPtr<FJsonObject> CYZUEFox::getUserInfo()
  {
    #if PLATFORM_ANDROID
    FoxJniMethodInfo minfo;
    bool exists = FoxJniHelper::getStaticMethodInfo(
                                                  minfo,
                                                  "co/cyberz/fox/support/ue/Fox",
                                                  "getUserInfo",
                                                  "()Ljava/lang/String;"
                                                  );
    if (exists) {
      jstring jUserInfoStr = (jstring) minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID);
      const char* cUserInfo = minfo.env->GetStringUTFChars(jUserInfoStr, nullptr);
      if (cUserInfo != nullptr) {
        return CYZUEFoxUtil::fString2Json(UTF8_TO_TCHAR(cUserInfo));
      }
    }
    #endif
    return nullptr;
  }

}
