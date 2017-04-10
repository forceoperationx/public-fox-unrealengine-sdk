[TOP](../../README.md)　>　**事件计测详细**

---

# 事件计测详细

通过使用trackEvent方法，可以计测各广告渠道的付费金额和注册人数等。为进行这样的计测，需在任意地点中添加执行LTV成果通信的代码。

请在成果产生后实行的处理中编辑添加相应代码。例如，会员注册及APP内付费后的付费计测是在注册・付费完成后的回调函数中添加相应的事件计测处理。

```cs
#include "CYZFox.h"
#include "CYZFoxEvent.h"
using namespace fox;

...

CYZFoxEvent e = new CYZFoxEvent(事件名, 成果地点ID);
CYZFox::trackEvent(e);
```

> 事件名(必须) : 可以指定任意事件名。

> 成果地点ID(必须) : 请输入管理员告知的值。

<div id="add_buid"></div>

### 指定Buid(广告主终端ID)

APP内部的成果中，可以包含广告主终端ID（会员ID等），可以以该基准做成果计测。LTV成果中希望赋予广告主终端ID时请按下面的方式去执行。

```cs
#include "CYZFox.h"
#include "CYZFoxEvent.h"
using namespace fox;

...

	CYZFoxEvent e = new CYZFoxEvent(事件名, 成果地点ID);
	e.buid = "广告主终端ID";
	CYZFox::trackEvent(e);
```

> 广告主终端ID(任意)：广告主管理的唯一标识符（会员ID等）。
可以设置64文字以内的半角英文和数字。

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

|参数|型|最大长度|概要|
|:------|:------:|:------:|:------|
|eventName|char|255|设置能够识别追踪事件的任意名称。事件名可自由设置。|
|orderId|char|255|指定单号。|
|sku|char|255|指定sku商品代码。|
|itemName|char|255|指定商品名。|
|price|double||指定商品单价。|
|quantity|int||指定数量。price * quantity为销售总额。|
|currency|cahr||指定货币代码。未指定时默认为"JPY"。|

> currency请设置为[ISO 4217](http://ja.wikipedia.org/wiki/ISO_4217)中定义的货币代码。

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

Android的场合，可以按照以下内容通过java来编码执行。<br>
为计测APP的启动及从后台复归，需在Activity中`onResume`方法中添加代码。

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
> ※ APP从后台恢复时，Activity中没有执行启动计测的话，将无法正确计测活跃用户数。

> ※ Java和C#两者中均未执行trackSession()时，会导致一个用户被记录2次启动信息，请务必在其中一处执行。



---
[Top](../../README.md)
