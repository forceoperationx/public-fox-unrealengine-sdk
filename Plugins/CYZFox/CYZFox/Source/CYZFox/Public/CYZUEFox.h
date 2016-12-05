#ifndef __CYZFox_H_
#define __CYZFox_H_

#include "CYZUEFoxEvent.h"
#include "CYZUEFoxTypes.h"
#include "Engine.h"

#if PLATFORM_ANDROID
#include "../Private/Android/FoxNativeTrackListener.h"
#endif

using namespace std;

namespace fox {

	struct CYZUEFoxConfig {
		int appId_ios = 0;
		const char* iosSalt = nullptr;
		const char* appKey_ios = nullptr;
		bool iosWebViewTrackingEnabled;

		int androidAppId = 0;
		const char* androidSalt = nullptr;
		const char* androidAppKey = nullptr;

		const char* foxServerURL = nullptr;
		const char* analyticsServerURL = nullptr;
		bool debugMode = 0;
	};

	struct CYZUEFoxTrackOption {
		bool optout;
		const char* redirectURL;
		const char* buid;
		CYZFoxInstallCallbackFunc onInstallComplete;
	};

	/**
	 *
	 */
	class CYZUEFox
	{
	public:
		static void activate(CYZUEFoxConfig config);
		static void trackInstall();
		static void trackInstall(CYZUEFoxTrackOption option);
		static void trackSession();
		static void trackEvent(CYZUEFoxEvent* event);

		static bool isConversionCompleted();
		static void trackEventByBrowser(const char* redirectURL);
		static void setUserInfo(TSharedPtr<FJsonObject> userInfo);
		static TSharedPtr<FJsonObject> getUserInfo();

	#if PLATFORM_ANDROID
	private:
		static FoxNativeTrackListener* foxTracklistener;
	#endif
	};

	#define FOX_CALLBACK_STATIC(__selector__, ...) std::bind(__selector__, ##__VA_ARGS__)
}

#endif
