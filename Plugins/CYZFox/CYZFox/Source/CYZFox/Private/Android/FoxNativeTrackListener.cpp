#include "CYZFoxPrivatePCH.h"
#if PLATFORM_ANDROID
#include "FoxNativeTrackListener.h"

using namespace fox;

  FoxNativeTrackListener::FoxNativeTrackListener(CYZFoxInstallCallbackFunc callbackFunc)
  {
    this->onInstallCompleteCallback = callbackFunc;
  }

  void FoxNativeTrackListener::onInstallComplete()
  {
    if (this->onInstallCompleteCallback) this->onInstallCompleteCallback();
  }

#endif
