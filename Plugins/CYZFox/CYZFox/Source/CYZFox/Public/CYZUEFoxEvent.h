#ifndef __CYZUEFoxEvent_H_
#define __CYZUEFoxEvent_H_

#include <map>
#include <string>
#include "Json.h"
#include "Engine.h"

using namespace std;

namespace fox
{

  class CYZUEFoxEvent
  {
  public:
    const char* eventName = nullptr;
    const char* buid = nullptr;
    uint const ltvId;
    uint eventValue = 0;
    const char* orderId = nullptr;
    const char* sku = nullptr;
    const char* itemName = nullptr;
    double price;
    uint quantity = 1;
    const char* currency = nullptr;
    map<string, string> extraInfo;
    TSharedPtr<FJsonObject> eventInfo;

    CYZUEFoxEvent(const char* eName): eventName(eName),ltvId(0){};
    CYZUEFoxEvent(const char* eName, uint ltvPointId): eventName(eName),ltvId(ltvPointId){};
    void addParam(const char* key, const char* value);

    static CYZUEFoxEvent* makePurchaseEvent(
                                          const char* const eventName,
                                          uint const ltvId,
                                          double price,
                                          const char* currency
                                          );

    #if PLATFORM_ANDROID
      const char* getExtraInfoStr();
      FString getEventInfoStr();
    #endif
  };


}

#endif
