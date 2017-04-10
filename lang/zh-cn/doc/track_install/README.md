[TOP](../../README.md)　>　**Install计测详细**

---

# Install计测详细

使用`trackInstall`方法可以进行Install计测。<br>
请在APP启动执行的处理中执行以下代码。<br>
想要跳转至特定URL或APP中动态生成URL时，请设置URL字符串。

```cs
#include "CYZFox.h"
using namespace fox;

...

  CYZUEFoxTrackOption option;
  // 指定URL
  option.redirectURL = "http://yourhost.com/yourpage.html";
  CYZFox::trackInstall(option);
```

### 指定Buid (广告主终端ID)

`FoxTrackOption`的buid中可以传递广告主终端ID。
例如，APP启动时SDK生成UUID，可以在关联首次启动APP的成果做管理时使用。

```cs
#include "CYZFox.h"
using namespace fox;

...

  CYZUEFoxTrackOption option;
  option.redirectURL = "http://yourhost.com/yourpage.html";
  // 指定BUID
  option.buid = "USER_001"
  CYZFox::trackInstall(option);
```

<div id="check_track"></div>
### 确认是否已完成Install计测

首次启动时Fox.trackInstall是否运行的信息，可以通过来bool型返回值来获取。<br>
使用以下方法，可以在计测完成后第二次以上的启动时进行特定处理。

```cs
#include "CYZFox.h"
using namespace fox;

...
  // 是否计测完成
  bool isComplete = CYZFox::isConversionCompleted();
```


<div id="receive_callback"></div>

### 接收回调函数

使用`FoxTrackOption`的`onTrackComplete`（事件处理），可以在F.O.X SDK的计测处理完成时接受回调函数。

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

// SDK的启动计测完成时调用
void FoxSample::onInstallComplete()
{
  // 记述完成后执行处理
}
```

> ※ 接受回调函数处理仅为C++的功能，不适用于蓝图。

### optout设置

有些广告公司可以让用户选择是否使用定向投放（targeting）广告。<br>
用户在APP启动时弹出的隐私权政策和使用条例对话框中选择Optout的情况时，告知效果测定结果的同时，F.O.X也会通知广告公司用户选择了Optout。

适用Optout的场合，请在以下`Fox.trackInstall`的参数中进行设置。

```cs
#include "CYZFox.h"
using namespace fox;

...

  // 用户选择optout时，设置setOptout为有效
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
