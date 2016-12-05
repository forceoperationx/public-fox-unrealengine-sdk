// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "CYZFoxBlueprintLibraryPrivatePCH.h"
#include "CYZUEFox.h"
#include "CYZUEFoxUtil.h"
#include <string>

using namespace fox;

UCYZFoxBlueprintLibrary::UCYZFoxBlueprintLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

#if PLATFORM_ANDROID || PLATFORM_IOS
void UCYZFoxBlueprintLibrary::Activate(const FCYZFoxConfig config)
{
		CYZUEFoxConfig c;
		c.appId_ios = config.appId_ios;
		c.iosSalt = TCHAR_TO_UTF8(*(config.iosSalt));
		c.appKey_ios = TCHAR_TO_UTF8(*(config.appKey_ios));
		c.androidAppId = config.androidAppId;
		c.androidSalt = TCHAR_TO_UTF8(*(config.androidSalt));
		c.androidAppKey = TCHAR_TO_UTF8(*(config.androidAppKey));
		c.debugMode = config.debugMode;
		CYZUEFox::activate(c);
}

void UCYZFoxBlueprintLibrary::TrackInstall()
{
	CYZUEFox::trackInstall();
}

void UCYZFoxBlueprintLibrary::TrackInstallWithOption(const FCYZFoxTrackOption option)
{
	CYZUEFoxTrackOption opt;
	opt.redirectURL = TCHAR_TO_UTF8(*(option.redirectURL));
	opt.buid = TCHAR_TO_UTF8(*(option.buid));
	opt.optout = option.optout;
	CYZUEFox::trackInstall(opt);
}

void UCYZFoxBlueprintLibrary::TrackSession()
{
	CYZUEFox::trackSession();
}

void UCYZFoxBlueprintLibrary::TrackEvent(const FFoxEventAttr attr)
{
	if (attr.eventName.Len() == 0) return;
	CYZUEFoxEvent* e;
	e = new CYZUEFoxEvent(TCHAR_TO_UTF8(*(attr.eventName)), attr.ltvId);
	e->buid = TCHAR_TO_UTF8(*(attr.buid));
	e->orderId = TCHAR_TO_UTF8(*(attr.orderId));
	e->sku = TCHAR_TO_UTF8(*(attr.sku));
	e->itemName = TCHAR_TO_UTF8(*(attr.itemName));
	e->currency = TCHAR_TO_UTF8(*(attr.currency));
	e->price = attr.price;
	e->quantity = attr.quantity;
	e->eventValue = attr.eventValue;

	if (0 < attr.extraInfo.Num()) {
		for (auto& FCYZFoxEventParam : attr.extraInfo) {
			FString fKey = FCYZFoxEventParam.Name;
			FString fVal = FCYZFoxEventParam.Value;
			e->addParam(TCHAR_TO_UTF8(*fKey), TCHAR_TO_UTF8(*fVal));
		}
	}

	if (0 < attr.eventInfoJson.Len()) {
		e->eventInfo = CYZUEFoxUtil::fString2Json(attr.eventInfoJson);
	}

	CYZUEFox::trackEvent(e);
}

bool UCYZFoxBlueprintLibrary::IsConversionComplete()
{
	return CYZUEFox::isConversionCompleted();
}

void UCYZFoxBlueprintLibrary::TrackByBrowser(FString url)
{
	CYZUEFox::trackEventByBrowser(TCHAR_TO_UTF8(*url));
}

void UCYZFoxBlueprintLibrary::SetUserInfo(FString jsonStr) {
	TSharedPtr<FJsonObject> jsonObj = CYZUEFoxUtil::fString2Json(jsonStr);
	CYZUEFox::setUserInfo(jsonObj);
}

FString UCYZFoxBlueprintLibrary::GetUserInfo() {
	TSharedPtr<FJsonObject> jsonObj = CYZUEFox::getUserInfo();
	return fox::CYZUEFoxUtil::json2FString(jsonObj);
}

#else

void UCYZFoxBlueprintLibrary::Activate(const FCYZFoxConfig config) {}

void UCYZFoxBlueprintLibrary::TrackInstall() {}

void UCYZFoxBlueprintLibrary::TrackInstallWithOption(const FCYZFoxTrackOption option) {}

void UCYZFoxBlueprintLibrary::TrackSession() {}

void UCYZFoxBlueprintLibrary::TrackEvent(const FFoxEventAttr attr) {}

bool UCYZFoxBlueprintLibrary::IsConversionComplete() {return false;}

void UCYZFoxBlueprintLibrary::TrackByBrowser(FString url) {}

void UCYZFoxBlueprintLibrary::SetUserInfo(FString jsonStr) {}

FString UCYZFoxBlueprintLibrary::GetUserInfo() {return nullptr;}
#endif
