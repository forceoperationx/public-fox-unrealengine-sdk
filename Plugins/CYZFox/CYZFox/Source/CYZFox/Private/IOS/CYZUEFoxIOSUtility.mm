#import <Foundation/Foundation.h>
#include "CYZFoxPrivatePCH.h"
#include "CYZUEFoxUtil.h"

static NSString* CYZUEFoxStringFromUTF8String(const char *bytes) {
    if (bytes) {
        return [NSString stringWithUTF8String:bytes];
    } else {
        return nil;
    }
}

static NSDictionary* CYZUEFoxJsonToDictionary(TSharedPtr<FJsonObject> jsonPtr) {
    FOXUE_LOG("CYZUEFoxJsonToDictionary");
    FString jsonStr = fox::CYZUEFoxUtil::json2FString(jsonPtr);
    NSString* nsJsonStr = CYZUEFoxStringFromUTF8String(TCHAR_TO_UTF8(*jsonStr));
    FOXUE_LOG("JSON to dictionary: %@", nsJsonStr);
    if (nsJsonStr && nsJsonStr.length > 0) {
        FOXUE_LOG("string to dictionary");
        NSError* err = nil;
        NSDictionary* dict = [NSJSONSerialization JSONObjectWithData:[nsJsonStr dataUsingEncoding:NSUTF8StringEncoding]  options:0 error:&err];
        if (err) {
            FOXUE_LOG("dictionary write err!! : %@", err);
        }
        return dict;
    }

    return nil;
}

static TSharedPtr<FJsonObject> CYZUEFoxDictionaryToJson(NSDictionary* dict) {
    TSharedPtr<FJsonObject> jsonPtr;
    if (dict) {
        NSError* err = nil;
        FOXUE_LOG("dictionary to JSON");
        NSData* jsonData = [NSJSONSerialization dataWithJSONObject:dict options:0 error:&err];
        if (err) {
            FOXUE_LOG("json read err: %@", err);
        }
        if(jsonData) {
            NSString* objcStr = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
            FOXUE_LOG("JSON String: %@", objcStr);
            const char* cJsonStr = [objcStr UTF8String];
            jsonPtr = fox::CYZUEFoxUtil::fString2Json(FString(cJsonStr));
        }
    }
    return jsonPtr;
}
