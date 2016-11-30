[TOP](../../README.md)　>　**이벤트 계측의 상세**

---

# 이벤트 계측의 상세

trackEvent메소드를 이용하여 광고 유입별의 과금금액 및 회원등록등을 계측 가능합니다. 계측을 위한 임의의 지점에 LTV성과 통신을 행하는 코드를 추가합니다.

소스 편집은 성과를 올린후에 실행되는 스크립트에 처리를 기술합니다. 예를 들어 회원 등록 및 앱내 과금후의 과금 계측에서는 등록 ・과금 처리 실행후의 콜백내에 이벤트 계측 처리를 기술합니다.

```cs
#include "CYZFox.h"
#include "CYZFoxEvent.h"
using namespace fox;

...

CYZFoxEvent e = new CYZFoxEvent(이벤트명, 성과지점ID);
CYZFox::trackEvent(e);
```

> 이벤트명(필수) : 임의의 이벤트명을 지정 가능합니다.

> 성과지점ID(필수) : 관리자로부터 연락합니다. 연락받은 값을 입력하여 주십시오. 또는 관리콘솔 상의 성과지점 설정 화면 상에서 직접 확인 가능합니다.

<div id="add_buid"></div>
### Buid (광고주 단말ID)를 지정

앱 내부의 성과에 광고주 단말ID（회원 ID등）을 포함 가능하여 이와 같은 ID를 기준으로하여 성과 계측이 가능합니다.LTV성과에 광고주 단말 ID를 부여하실 경우 이하와 같이 기술하여 주십시오.

```cs
#include "CYZFox.h"
#include "CYZFoxEvent.h"
using namespace fox;

...

	CYZFoxEvent e = new CYZFoxEvent(이벤트명, 성과지점ID);
	e.buid = "광고주 단말ID";
	CYZFox::trackEvent(e);
```

> 광고주 단말ID(option)：광고주가 관리하고 있는 유니크 식별자（会員ID등）입니다.
지정가능한 값은 64문자이내의 영숫자 입니다.

<div id="add_params"></div>
### 임의의 매개변수를 지정합니다.

앱내 계측시에는 매개변수를 옵션으로써 지정 가능합니다.

```cs
#include "CYZFox.h"
#include "CYZFoxEvent.h"
using namespace fox;

...

	CYZFoxEvent e = new CYZFoxEvent(이벤트명, 성과지점ID);
	e.addParam("매개변수명", "값");
	CYZFox::trackEvent(e);
```

<div id="purchase"></div>
### 과금 이벤트 구현예

```cs
#include "CYZFox.h"
#include "CYZFoxEvent.h"
using namespace fox;
...

	int ltvId = 성과지점ID;
	double price = 1.2;
	String currency = "USD";
	FoxEvent purchase = FoxEvent.makePurchase("_purchase", ltvId, price, currency);
	purchase.buid = "USER_001"
	purchase.orderId = "ABCDEFG12345";
	purchase.itemName = "Coin";
	purchase.sku = "A-001"
	purchase.quantity = 1;
	Fox.trackEvent(purchase);
```

FoxEvent에 설정가능한 매개변수의 사양은 아래와 같습니다.

|매개변수|형|최대길이|개요|
|:------|:------:|:------:|:------|
|eventName|char|255|트랙킹하실 이벤트를 식별 가능한 임의의 명칭을 설정합니다. 이벤트명은 자유로이 설정 가능합니다.|
|orderId|char|255|주문번호등을 지정합니다.|
|sku|char|255|상품코드등을 지정합니다.|
|itemName|char|255|상품명을 지정합니다.|
|price|double||상품단가를 지정합니다.|
|quantity|int||수량을 지정합니다.price * quantity가 매출 금액으로써 집계됩니다.|
|currency|cahr||통화코드를 지정합니다. 미지정의 경우에는 "JPY"가 지정됩니다.|

> currency에는[ISO 4217](http://ko.wikipedia.org/wiki/ISO_4217)에서 정의된 통화 코드를 지정하여 주십시오.

<div id="session"></div>
### 세션 이벤트

애플리케이션이 기동 또는 백그라운드로 부터의 복귀할 시에 세션 계측을 실행할 코드를 추가합니다. 불필요한 경우에는 본 항목의 구현을 생략 가능합니다.

```cs
#include "CYZFox.h"
#include "CYZFoxEvent.h"
using namespace fox;

...

	CYZFox::trackSession();
```

#### (Android) Java를 이용한 구현

Android의 경우 이하와 같이 java에 의한 구현이 가능합니다.<br>
애플리케이션의 기동 및 백그라운드로 부터의 복귀를 계측하기 위하여 Activity의 `onResume`메소드에 코드를 추가합니다.

애플리케이션 기동시의 기동 계측（MainActivity클래스에 구현예）
```java
import co.cyberz.fox.Fox;

public class MainActivity extends Activity {

		@Override
		protected void onResume() {
            super.onResume();
            Fox.trackSession();
		}
}
```
> ※ 애플리케이션이 백그라운드로부터 복귀할시 Activity에 기동 계측의 구현이 되어있지 않았을 시에는 정확한 액티브 유저수의 계측이 되지 않습니다.

> ※ Java와 C#의 양측에서 trackSession()이 실행된 경우１유저로부터 ２중의 앱 기동 정보가 송신 되므로 반드시 어느 한쪽에만 구현하여 주십시오.




---
[トップ](../../README.md)
