[TOP](../../README.md)　>　**インストール計測の詳細**

---

# インストール計測の詳細

`trackInstall`メソッドを利用することで、インストール計測を行うことができます。<br>
起動時に実行されるスクリプトから以下のコードが呼ばれるよう実装を行ってください。<br>
特定のURLヘ遷移させたい場合や、アプリケーションで動的にURLを生成したい場合には、URLの文字列を設定してください。

```cs
#include "CYZFox.h"
using namespace fox;

...

  CYZUEFoxTrackOption option;
  // URLを指定
  option.redirectURL = "http://yourhost.com/yourpage.html";
  CYZFox::trackInstall(option);
```

### Buid (広告主端末ID)を指定する

`FoxTrackOption`のbuidに広告主端末IDを渡すことができます。<br>例えば、アプリ起動時にSDKがUUIDを生成し、初回起動の成果と紐付けて管理したい場合等に、利用できます。

```cs
#include "CYZFox.h"
using namespace fox;

...

  CYZUEFoxTrackOption option;
  option.redirectURL = "http://yourhost.com/yourpage.html";
  // BUIDを指定
  option.buid = "USER_001"
  CYZFox::trackInstall(option);
```

<div id="check_track"></div>
### インストール計測が完了したかをチェックする

初回起動時のCYZFox::trackInstallが行われたかの情報をboolで取得することができます。<br>
以下メソッドを用いることでインストール計測が完了し、２回目以降の起動時に特定の処理を行うことが出来るようになります。

```cs
#include "CYZFox.h"
using namespace fox;

...
  // 計測済みかどうか
  bool isComplete = CYZFox::isConversionCompleted();
```


<div id="receive_callback"></div>
### コールバックを受け取る

`CYZUEFoxTrackOption`の`onInstallComplete`（イベントハンドラ）を用いることで、F.O.X SDKの計測処理が完了したタイミングのコールバックを受け取ることが可能です。

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
  // イベントハンドラを指定
  option.onInstallComplete = FOX_CALLBACK_STATIC(FoxSample::onInstallComplete, this);
  option.onTrackComplete += HandleFoxTrackComplete;
  Fox.trackInstall(option);
}
...

// SDKの起動計測が完了したタイミングに呼ばれます
void FoxSample::onInstallComplete()
{
  // 完了後に実行する処理を記述
}
```

> ※ コールバックを受け取る処理は現在、C++のみの機能となっておりブループリントには対応しておりません。

### オプトアウトの設定

広告会社によってターゲティング広告に利用されないことをユーザーに選択させることが可能です。<br>アプリケーションの起動時において、プライバシーポリシーや利用規約を表示するダイアログでユーザーがオプトアウトを選択した場合、効果測定の結果の通知と共に、F.O.Xが広告会社に対してそのユーザーがオプトアウトを選択したことを通知します。

オプトアウトに対応する場合は、以下の通り「`Fox.trackInstall`の引数に設定を行ってください。

```cs
#include "CYZFox.h"
using namespace fox;

...

  // ユーザーがオプトアウトを選択した場合に setOptout を有効にする
  CYZUEFoxTrackOption option;
  option.redirectURL = "https://www.yourhost.com";
  option.buid = "USER_001";
  if(user.optout) {
	   option.optout = true;
  }
  Fox.trackInstall(option);
```

> ※ オプトアウトはデフォルトfalseとなっています。

---
[TOP](../../README.md)
