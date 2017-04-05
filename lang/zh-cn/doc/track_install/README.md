[TOP](../../README.md)　>　**安装计测详情**

---

# 安装计测详情

使用`trackInstall`方法可以进行安装计测。<br>
启动时执行的脚本中执行呼出以下代码。<br>
想要跳转特定的URL或APP中动态生成URL时，请设置URL字符串。

```cs
#include "CYZFox.h"
using namespace fox;

...

  CYZUEFoxTrackOption option;
  // 指定URL
  option.redirectURL = "http://yourhost.com/yourpage.html";
  CYZFox::trackInstall(option);
```

### 指定编译 (广告主终端ID)

`FoxTrackOption`的编译中可以递交广告主终端ID。<br>例如，APP启动时SDK生成UUID，可以在关联管理首次启动成果时使用。

```cs
#include "CYZFox.h"
using namespace fox;

...

  CYZUEFoxTrackOption option;
  option.redirectURL = "http://yourhost.com/yourpage.html";
  // 指定编译
  option.buid = "USER_001"
  CYZFox::trackInstall(option);
```

<div id="check_track"></div>
### 确认是否已完成安装计测

首次启动时Fox.trackInstall是否运行的信息，可以通过来bool获取。<br>
使用以下方法，可以在计测完成后第二次以上的启动时进行特定处理。

```cs
#include "CYZFox.h"
using namespace fox;

...
  // 是否计测完成
  bool isComplete = CYZFox::isConversionCompleted();
```


<div id="receive_callback"></div>
### 接收回调

使用`FoxTrackOption`的`onTrackComplete`（事件处理），F.O.X SDK的计测处理完成时可以接受回调。

```cs
#include "FoxSample.h"
#include "CYZFox.h"
using namespace fox;

...
void FoxSample::TrackCv()
{
  CYZUEFoxTrackOption option;
  option.redirectURL = "http://yourhost.com/yourpage.html";
  option.buid = "USER_001"
  // 指定事件处理
  option.onInstallComplete = FOX_CALLBACK_STATIC(FoxSample::onInstallComplete, this);
  option.onTrackComplete += HandleFoxTrackComplete;
  Fox.trackInstall(option);
}
...

// SDK的启动计测完成时呼出
void FoxSample::onInstallComplete()
{
  // 记述完成后执行处理
}
```

> ※ 接受回调处理仅为C++的功能，不适用于蓝图。

### optout设置

广告公司可以让用户选择是否使用targeting广告。<br>用户在APP启动时弹出的隐私权政策和使用条例对话框中选择Optout的情况时，告知效果测定结果的同时，F.O.X也会通知广告公司用户选择了Optout。

适用Optout的场合，请在以下「`Fox.trackInstall`的引数中进行设置。

```cs
#include "CYZFox.h"
using namespace fox;

...

  // 用户选择optout时，setOptout 为有效
  CYZUEFoxTrackOption option;
  option.redirectURL = "https://www.yourhost.com";
  option.buid = "USER_001";
  if(user.optout) {
	   option.optout = true;
  }
  Fox.trackInstall(option);
```

> ※ optout默认为false。

---
[TOP](../../README.md)
