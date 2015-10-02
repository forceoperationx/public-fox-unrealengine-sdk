## SDK設定の詳細

XcodeにてSDKの動作に必要な設定をplistに追加します。「AppAdForce.plist」という名称のプロパティリストファイルをプロジェクトの任意の場所に作成し、次のキーと値を入力してください。

任意の場所で右クリック→「New File...」を選択

![SDK設定01](https://github.com/cyber-z/public_fox_ios_sdk/raw/master/doc/config_plist/ja/img01.png)

「Property List」を選択。

![SDK設定02](https://github.com/cyber-z/public_fox_ios_sdk/raw/master/doc/config_plist/ja/img02.png)

「AppAdForce.plist」という名称に変更し、Createボタンをクリック。

![SDK設定03](https://github.com/cyber-z/public_fox_ios_sdk/raw/master/doc/config_plist/ja/img03.png)

作成したプロパティリストファイルを選択。右クリックでメニューを開き、「Add Row」を選択

![SDK設定04](https://github.com/cyber-z/public_fox_ios_sdk/raw/master/doc/config_plist/ja/img04.png)

各キーとバリューを設定。

![SDK設定05](https://github.com/cyber-z/public_fox_ios_sdk/raw/master/doc/config_plist/ja/img05.png)

設定するキーとバリューは以下の通りです。

|Key|Type|Value|
|:------:|:------:|:------|
|APP_ID|String|Force Operation X管理者より連絡しますので、その値を入力してください。|
|SERVER_URL|String|Force Operation X管理者より連絡しますので、その値を入力してください。|
|APP_SALT|String|Force Operation X管理者より連絡しますので、その値を入力してください。|
|APP_OPTIONS|String|何も入力せず、空文字の状態にしてください。|
|CONVERSION_MODE|String|1 固定|
|ANALYTICS_APP_KEY|String|Force Operation X管理者より連絡しますので、その値を入力してください。<br />アクセス解析を利用しない場合は設定の必要はありません。|
