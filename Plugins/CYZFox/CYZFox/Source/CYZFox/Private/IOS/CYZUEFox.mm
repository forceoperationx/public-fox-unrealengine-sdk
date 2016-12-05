//
//  CYZUEFox.m
//  EarthWarrior3D
//
//  Created by 呉 維 on 2016/06/13.
//
//
#include "CYZFoxPrivatePCH.h"
#import <CYZFox/CYZFox.h>
#include "CYZUEFoxIOSUtility.mm"

using namespace fox;

void CYZUEFox::activate(CYZUEFoxConfig config) {
    CYZFoxConfig* foxConfig = [CYZFoxConfig configWithAppId:config.appId_ios salt:CYZUEFoxStringFromUTF8String(config.iosSalt) appKey:CYZUEFoxStringFromUTF8String(config.appKey_ios)];

    if (config.foxServerURL) {
        [foxConfig setFoxServerURL:CYZUEFoxStringFromUTF8String(config.foxServerURL)];
    }
    if (config.analyticsServerURL) {
        [foxConfig setAnalyticsServerURL:CYZUEFoxStringFromUTF8String(config.analyticsServerURL)];
    }
    if (config.debugMode) {
        [foxConfig enableDebugMode];
    }
    if (config.iosWebViewTrackingEnabled) {
        [foxConfig enableWebViewTracking];
    }

    [foxConfig activate];
}

void CYZUEFox::trackInstall() {
    [CYZFox trackInstall];
}

void CYZUEFox::trackInstall(CYZUEFoxTrackOption option) {
    CYZFoxTrackOption* foxOption = [CYZFoxTrackOption new];
    foxOption.redirectURL = CYZUEFoxStringFromUTF8String(option.redirectURL);
    foxOption.buid = CYZUEFoxStringFromUTF8String(option.buid);
    foxOption.optout = option.optout;

    [CYZFox trackInstallWithOption:foxOption];
}

void CYZUEFox::trackSession() {
    [CYZFox trackSession];
}

void CYZUEFox::trackEvent(CYZUEFoxEvent* event) {
    CYZFoxEvent* foxEvent = [[CYZFoxEvent alloc]initWithEventName:CYZUEFoxStringFromUTF8String(event->eventName) ltvId:event->ltvId];
    foxEvent.buid = CYZUEFoxStringFromUTF8String(event->buid);

    // set extraInfo: get NSDictionary from std::map
    for (auto& elem : event->extraInfo) {
        [foxEvent addExtraValue:CYZUEFoxStringFromUTF8String(elem.second.c_str())
                         forKey:CYZUEFoxStringFromUTF8String(elem.first.c_str())];
    }

    foxEvent.value = event->eventValue;
    foxEvent.orderId = CYZUEFoxStringFromUTF8String(event->orderId);
    foxEvent.sku = CYZUEFoxStringFromUTF8String(event->sku);
    foxEvent.itemName = CYZUEFoxStringFromUTF8String(event->itemName);
    foxEvent.price = event->price;
    foxEvent.quantity = event->quantity;
    foxEvent.currency = CYZUEFoxStringFromUTF8String(event->currency);
    foxEvent.eventInfo = CYZUEFoxJsonToDictionary(event->eventInfo);

    [CYZFox trackEvent:foxEvent];
}

bool CYZUEFox::isConversionCompleted() {
    return [CYZFox isConversionCompleted];
}

TSharedPtr<FJsonObject> CYZUEFox::getUserInfo() {
    NSDictionary* userInfo = [CYZFox getUserInfo];
    if (userInfo) {
        return CYZUEFoxDictionaryToJson(userInfo);
    }
    return nullptr;
}

void CYZUEFox::setUserInfo(TSharedPtr<FJsonObject> jsonObj) {
    NSDictionary* userInfo = CYZUEFoxJsonToDictionary(jsonObj);
    if (userInfo) {
        [CYZFox setUserInfo:userInfo];
    }
}

void CYZUEFox::trackEventByBrowser(const char* redirectURL) {
    [CYZFox trackEventByBrowser:CYZUEFoxStringFromUTF8String(redirectURL)];
}
