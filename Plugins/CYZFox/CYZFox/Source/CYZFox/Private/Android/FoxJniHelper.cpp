#include "CYZFoxPrivatePCH.h"
#if PLATFORM_ANDROID
#include "Android/AndroidApplication.h"
#include "FoxJniHelper.h"

using namespace fox;

JNIEnv* FoxJniHelper::getEnv()
{
	JNIEnv* env = FAndroidApplication::GetJavaEnv();
	return env;
}

jobject FoxJniHelper::getActivity()
{
  FoxJniMethodInfo jniInfo;
  bool isExist = FoxJniHelper::getStaticMethodInfo(jniInfo,
                                     "com/epicgames/ue4/GameActivity",
                                     "Get",
                                     "()Lcom/epicgames/ue4/GameActivity;");
  if (! isExist) return nullptr;
  jobject activityObj = jniInfo.env->CallStaticObjectMethod(jniInfo.classID, jniInfo.methodID, "");
  if (nullptr == activityObj) {
		FOXUE_LOG("----Activity is not found.");
		// UE_LOG("FoxUeJniHelper", Error, "----Activity is not found.");
		return nullptr;
	}
  return activityObj;
}

bool FoxJniHelper::getStaticMethodInfo(FoxJniMethodInfo &jniInfo, const char* classPath, const char* methodName, const char* args)
{
  if ((nullptr == classPath) ||
      (nullptr == methodName) ||
      (nullptr == args)) {
      return false;
  }

  JNIEnv *env = getEnv();
  if (!env) {
      FOXUE_LOG("Failed to get JNIEnv");
      return false;
  }

  jclass targetClass = FAndroidApplication::FindJavaClass(classPath);
  if (! targetClass) {
    FOXUE_LOG("TargetClass is not found.");
		// UE_LOG(LOG_TAG, Error, "----TargetClass is not found.");
		return false;
  }

  jmethodID methodID = env->GetStaticMethodID(targetClass, methodName, args);
  if (! methodID) {
    FOXUE_LOG("Failed to find static method id of %s", methodName);
		// UE_LOG(LOG_TAG, Error, "Failed to find static method id of %s", methodName);
    return false;
  }

  jniInfo.env = env;
  jniInfo.classID = targetClass;
  jniInfo.methodID = methodID;
  return true;
}

#endif
