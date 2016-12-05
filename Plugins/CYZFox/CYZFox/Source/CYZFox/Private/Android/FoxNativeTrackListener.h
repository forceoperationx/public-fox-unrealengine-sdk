#if PLATFORM_ANDROID
#ifndef __FoxNativeTrackListener_H__
#define __FoxNativeTrackListener_H__

#include <functional>
#include "CYZUEFoxTypes.h"

namespace fox {

  class FoxNativeTrackListener
  {
  public:

      FoxNativeTrackListener(CYZFoxInstallCallbackFunc callbackFunc);

      void onInstallComplete();

  private:

      CYZFoxInstallCallbackFunc onInstallCompleteCallback;
  };

}

#endif
#endif
