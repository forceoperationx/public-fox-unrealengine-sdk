#include "CYZFoxPrivatePCH.h"
#include "CYZUEFoxEvent.h"
#if PLATFORM_ANDROID
#include "CYZUEFoxUtil.h"
#include "Base64.h"
#endif

using namespace std;
using namespace fox;

CYZUEFoxEvent* CYZUEFoxEvent::makePurchaseEvent(
                                    const char* mEventName,
                                    uint const mLtvId,
                                    double mPrice,
                                    const char* mCurrency)
{
  #if PLATFORM_ANDROID
  CYZUEFoxEvent* e = new CYZUEFoxEvent(mEventName, mLtvId);
  e->price = mPrice;
  e->currency = mCurrency;
  return e;
  #else
  return nullptr;
  #endif
}

void CYZUEFoxEvent::addParam(const char* k, const char* v)
{
  #if PLATFORM_ANDROID
  this->extraInfo.insert(map<string, string>::value_type(k, v));
  FOXUE_LOG("addParam - count: %i", (unsigned int)this->extraInfo.size());
  #endif
}

#if PLATFORM_ANDROID
const char* CYZUEFoxEvent::getExtraInfoStr()
{
  if (this->extraInfo.size() == 0) return nullptr;
  FOXUE_LOG("getExtraInfoStr - count: %i", (unsigned int)this->extraInfo.size());
  return CYZUEFoxUtil::map2char(this->extraInfo);
}

FString CYZUEFoxEvent::getEventInfoStr()
{
  FString jsonStr = CYZUEFoxUtil::json2FString(this->eventInfo);
  FString base64Str = FBase64::Encode(jsonStr);
  return base64Str;
}
#endif
