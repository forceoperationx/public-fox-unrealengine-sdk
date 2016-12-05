#include "CYZFoxPrivatePCH.h"
#include "CYZUEFoxUtil.h"
#include "Json.h"
#include "Templates/SharedPointer.h"
#include <map>
#include <string>

using namespace std;

namespace fox
{
    FString CYZUEFoxUtil::json2FString(TSharedPtr<FJsonObject> jsonPtr) {
        FString jsonStr;
        if (!jsonPtr.IsValid()) return jsonStr;

        TSharedRef<TJsonWriter<TCHAR>> jsonWriter = TJsonWriterFactory<>::Create(&jsonStr);
        if (FJsonSerializer::Serialize(jsonPtr.ToSharedRef(), jsonWriter))
        {
          FOXUE_LOG("json2FString success: %s", TCHAR_TO_UTF8(*jsonStr));
        } else {
          FOXUE_LOG("json2FString failed");
        }
        return jsonStr;
    }

    TSharedPtr<FJsonObject> CYZUEFoxUtil::fString2Json(FString jsonStr) {
        TSharedRef<TJsonReader<TCHAR>> jsonReader = TJsonReaderFactory<TCHAR>::Create(jsonStr);
        TSharedPtr<FJsonObject> jsonObject = MakeShareable(new FJsonObject());
        if (FJsonSerializer::Deserialize(jsonReader, jsonObject) && jsonObject.IsValid()) {
          return jsonObject;
        }
        return nullptr;
    }

    const char* CYZUEFoxUtil::map2char(map<string, string> m) {
      const char* extraInfoStr = nullptr;
      if (m.size() == 0) return extraInfoStr;
      for(auto itr = m.begin(); itr != m.end(); ++itr) {
        string key(itr->first);
        string val(itr->second);
        if (extraInfoStr != nullptr && 0 < strlen(extraInfoStr)) {
          string tmp(extraInfoStr);
          extraInfoStr = (tmp + "&" + key + "=" + val).c_str();
        } else {
          extraInfoStr = (key + "=" + val).c_str();
        }
      }
      return extraInfoStr;
    }

}
