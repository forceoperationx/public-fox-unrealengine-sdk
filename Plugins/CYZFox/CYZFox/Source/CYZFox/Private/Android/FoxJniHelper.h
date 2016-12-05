#pragma once

#include "AndroidApplication.h"

#if PLATFORM_ANDROID

  typedef struct FoxJniMethodInfo_
  {
    JNIEnv* env;
    jclass  classID;
  	jmethodID methodID;
  } FoxJniMethodInfo;


namespace fox
{
	class FoxJniHelper
	{
	public:

    static JNIEnv* getEnv();
    static jobject getActivity();
		static bool getStaticMethodInfo(FoxJniMethodInfo &jniInfo,
			                              const char* classPath,
																		const char* methodName,
																		const char* args);
	};
}
#endif
