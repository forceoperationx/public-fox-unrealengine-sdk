[TOP](../../README.md)　>　**事件计测详情**

---

# 事件计测详情

通过使用trackEvent方法，可以计测各广告渠道的付费金额和注册人数等。为进行计测，需在任意地点中添加执行LTV成果信息的代码。

source编辑会在成果产生后实行的脚本中记录处理。例如，会员注册及APP内付费后的付费计测中，注册・付费实行后，在回调中记录事件计测处理。

```cs
#include "CYZFox.h"
#include "CYZFoxEvent.h"
using namespace fox;

...

CYZFoxEvent e = new CYZFoxEvent(事件名, 成果地点ID);
CYZFox::trackEvent(e);
```

> 事件名(必须) : 可以指定任意事件名。

> 成果地点ID(必须) : 由管理员通知。请输入该值。

<div id="add_buid"></div>
### 指定编译(广告主终端ID)

APP内部的成果中，可以包含广告主终端ID（会员ID等），进行该基准上的成果计测。LTV成果中希望授予广告主终端ID时请进行以下描述。

```cs
#include "CYZFox.h"
#include "CYZFoxEvent.h"
using namespace fox;

...

	CYZFoxEvent e = new CYZFoxEvent(事件名, 成果地点ID);
	e.buid = "广告主终端ID";
	CYZFox::trackEvent(e);
```

> 广告主终端ID(任意)：广告主管理的独特标识符（会员ID等）。
可以设置64字符以内半角英数字。

<div id="add_params"></div>
### 指定任意参数

APP内计测时可以进行参数设置。

```cs
#include "CYZFox.h"
#include "CYZFoxEvent.h"
using namespace fox;

...

	CYZFoxEvent e = new CYZFoxEvent(事件名, 成果地点ID);
	e.addParam("参数名", "值");
	CYZFox::trackEvent(e);
```

<div id="purchase"></div>
### 付费事件执行案例

```cs
#include "CYZFox.h"
#include "CYZFoxEvent.h"
using namespace fox;
...

	int ltvId = 成果地点ID;
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

FoxEvent中可以指定的参数如下。

|参数|型|最大長|概要|
|:------|:------:|:------:|:------|
|eventName|char|255|设置能够识别追踪事件的任意名称。事件名可自由设置。|
|orderId|char|255|指定单号。|
|sku|char|255|指定商品代码。|
|itemName|char|255|指定商品名。|
|price|double||指定商品单价。|
|quantity|int||指定数量。price * quantity为收入金额。|
|currency|cahr||指定货币代码。未指定时默认为"JPY"。|

> currency请设置为[ISO 4217](http://ja.wikipedia.org/wiki/ISO_4217)认证的货币代码。

<div id="session"></div>
### session事件

APP启动时或从后台恢复时，添加session计测代码。不需要该项结果时，请忽略本项。

```cs
#include "CYZFox.h"
#include "CYZFoxEvent.h"
using namespace fox;

...

	CYZFox::trackSession();
```

#### 使用(Android) Java执行

Android的场合，可以按照以下内容通过java执行。<br>
为计测APP启动及后台恢复的数据，需在Activity中`onResume`方法中添加代码。

APP启动时的启动计测（MainActivity类的执行案例）
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
> ※ APP从后台恢复时，Activity中没有执行启动计测的话，将无法进行正确的活跃用户计测。

> ※ Java和C#两者中均未执行trackSession()时，可能会导致一个用户被记录两次启动信息，请务必在其中之一执行。




---
[首页](../../README.md)
