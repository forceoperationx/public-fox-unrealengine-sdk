[TOP](../../README.md)　>　**인스톨 계측의 상세**

---

# 인스톨 계측의 상세

`trackInstall`메소드를 이용하여 인스톨 계측이 가능합니다.<br>
기동시에 실행되는 스크립트에서 이하의 코드가 호출 되도록 구현하여 주십시오.<br>
특정의 URL에 리다이렉트 하실 경우 및 애플리케이션에서 동적으로 URL을 생성하실 경우에는 URL의 문자열을 설정하여 주십시오

```cs
#include "CYZFox.h"
using namespace fox;

...

  CYZUEFoxTrackOption option;
  // URL을 지정
  option.redirectURL = "http://yourhost.com/yourpage.html";
  CYZFox::trackInstall(option);
```

### Buid (광고주 단말 ID)의 지정

`FoxTrackOption`의 buid에 광고주 단말 ID를 설정가능합니다.<br>예를 들어 앱 기동시에 SDK에서 UUID를 생성하여 초기 기동의 성과와 연관지어 관리하실 경우등에 이용 가능합니다.

```cs
#include "CYZFox.h"
using namespace fox;

...

  CYZUEFoxTrackOption option;
  option.redirectURL = "http://yourhost.com/yourpage.html";
  // BUID를 지정
  option.buid = "USER_001"
  CYZFox::trackInstall(option);
```

<div id="check_track"></div>
### 인스톨 계측이 완료되었는지를 확인

초기 기동시의 CYZFox::trackInstall이 실행되었는지에 대한 정보를 bool에서 취득하는 것이 가능합니다.<br>
이하 메소드를 이용하여 인스톨 계측이 완료되어 ２번째 이후의 기동시에 특정의 처리를 행하는 것이 가능하게 됩니다.

```cs
#include "CYZFox.h"
using namespace fox;

...
  // 계측 완료에 대하여
  bool isComplete = CYZFox::isConversionCompleted();
```


<div id="receive_callback"></div>
### 콜백을 수령

`CYZUEFoxTrackOption`의`onInstallComplete`（이벤트 핸들러）를 이용하여 F.O.X SDK의 계측처리가 완료된 타이밍의 콜백을 수령 가능합니다.

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
  // 이벤트 핸들러의 지정
  option.onInstallComplete = FOX_CALLBACK_STATIC(FoxSample::onInstallComplete, this);
  option.onTrackComplete += HandleFoxTrackComplete;
  Fox.trackInstall(option);
}
...

// SDK의 기동 계측이 완료된 타이밍에 호출 됩니다.
void FoxSample::onInstallComplete()
{
  // 완료후에 실행되는 처리를 기술
}
```

> ※ 콜백을 수령하는 처리는 현재 C++만의 기능이므로 블루프린트에서는 대응되지 않습니다.

### optout의 설정

광고사에 따라 타겟팅 광고에 이용되지 않는 유저를 선택 가능합니다.<br>애플리케이션의 기동시에 프라이버시 약관 및 이용 규약을 표시하여 다이얼로그에서 유저가 optout를 선택한 경우 효과 측정의 결과의 통지와 함께 F.O.X가 광고사에 대하여 유저가 optout를 선택한 내용을 통지합니다.

optout에 대응하는 경우에는 이하와 같이 「`Fox.trackInstall`의 인수에 설정하여 주십시오

```cs
#include "CYZFox.h"
using namespace fox;

...

  // 유저가 optout를 선택한 경우 setOptout를 유효로 하여 주십시오
  CYZUEFoxTrackOption option;
  option.redirectURL = "https://www.yourhost.com";
  option.buid = "USER_001";
  if(user.optout) {
	   option.optout = true;
  }
  Fox.trackInstall(option);
```

> ※ optout는 기본 false로 되어 있습니다.

---
[TOP](../../README.md)
