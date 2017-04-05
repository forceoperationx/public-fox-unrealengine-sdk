[TOP](../../README.md)　>　**イベント計測の詳細**

---

# イベント計測の詳細

trackEventメソッドを利用することで、広告流入別の課金金額や入会数などを計測することができます。計測のために、任意の地点にLTV成果通信を行うコードを追加します。

ソースの編集は、成果が上がった後に実行されるスクリプトに処理を記述します。例えば、会員登録やアプリ内課金後の課金計測では、登録・課金処理実行後のコールバック内にイベント計測処理を記述します。

```cs
#include "CYZFox.h"
#include "CYZFoxEvent.h"
using namespace fox;

...

CYZFoxEvent e = new CYZFoxEvent(イベント名, 成果地点ID);
CYZFox::trackEvent(e);
```

> イベント名(必須) : 任意のイベント名を指定することができます。

> 成果地点ID(必須) : 管理者より連絡します。その値を入力してください。

<div id="add_buid"></div>
### Buid (広告主端末ID)を指定する

アプリ内部の成果に、広告主端末ID（会員IDなど）を含める事ができ、これを基準とした成果計測が行えます。LTV成果に広告主端末IDを付与したい場合は以下のように記述してください。

```cs
#include "CYZFox.h"
#include "CYZFoxEvent.h"
using namespace fox;

...

	CYZFoxEvent e = new CYZFoxEvent(イベント名, 成果地点ID);
	e.buid = "広告主端末ID";
	CYZFox::trackEvent(e);
```

> 広告主端末ID(オプション)：広告主様が管理しているユニークな識別子（会員IDなど）です。
指定できる値は64文字以内の半角英数字です。

<div id="add_params"></div>
### 任意のパラメータを指定する

アプリ内計測時には、パラメータをオプションとして設定する事が可能です。

```cs
#include "CYZFox.h"
#include "CYZFoxEvent.h"
using namespace fox;

...

	CYZFoxEvent e = new CYZFoxEvent(イベント名, 成果地点ID);
	e.addParam("パラメータ名", "値");
	CYZFox::trackEvent(e);
```

<div id="purchase"></div>
### 課金イベント実装例

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

FoxEventに設定できるパラメータの仕様は下記の通りです。

|パラメータ|型|最大長|概要|
|:------|:------:|:------:|:------|
|eventName|char|255|トラッキングを行うイベントを識別できる任意の名前を設定します。イベント名は自由に設定可能です。|
|orderId|char|255|注文番号等を指定します。|
|sku|char|255|商品コード等を指定します。|
|itemName|char|255|商品名を指定します。|
|price|double||商品単価を指定します。|
|quantity|int||数量を指定します。price * quantityが売上金額として計上されます。|
|currency|cahr||通貨コードを指定します。未指定の場合は"JPY"が指定されます。|

> currencyには[ISO 4217](http://ja.wikipedia.org/wiki/ISO_4217)で定義された通貨コードを指定してください。

<div id="session"></div>
### セッションイベント

アプリケーションが起動、もしくはバックグラウンドから復帰する際にセッション計測を行うコードを追加します。不要の場合には、本項目の実装を省略できます。

```cs
#include "CYZFox.h"
#include "CYZFoxEvent.h"
using namespace fox;

...

	CYZFox::trackSession();
```

#### (Android) Javaによる実装

Androidの場合、以下のようにjavaによる実装も可能です。<br>
アプリケーションの起動及び、バックグラウンドからの復帰を計測するために、Activityの`onResume`メソッドにコードを追加します。

アプリケーション起動時の起動計測（MainActivityクラスへの実装例）
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
> ※ アプリケーションがバックグラウンドから復帰した際に、そのActivityに起動計測の実装がされていない場合など、正確なアクティブユーザー数が計測できなくなります。

> ※ JavaとC#の両方でtrackSession()が実行されていた場合、１ユーザーから２重にアプリ起動情報が送信されるため必ずどちらかで実装してください。




---
[トップ](../../README.md)
