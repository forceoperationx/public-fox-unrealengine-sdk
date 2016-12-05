#ifndef __CYZUEFoxUtil_H_
#define __CYZUEFoxUtil_H_

#include "Json.h"
#include "Engine.h"

using namespace std;

namespace fox
{
  class CYZUEFoxUtil
  {
  public:
    static FString json2FString(TSharedPtr<FJsonObject> jsonPtr);

    static TSharedPtr<FJsonObject> fString2Json(FString jsonStr);

    static const char* map2char(map<string, string> m);


  };
}
#endif
