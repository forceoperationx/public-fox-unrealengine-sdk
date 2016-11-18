[TOP](../../../README.md)　>　**Android プロジェクトの詳細設定**

---

# Android プロジェクトの詳細設定

* [パーミッションの設定](#permission)
* [インストールリファラ計測の設定](#install_referrer)
* [リエンゲージメント計測の実装](#track_reengagement)
* [その他](#others)

<div id="permission"></div>
## パーミッションの設定

F.O.X SDKでは下記のパーミッションを利用します。

```xml
<uses-permission android:name="android.permission.INTERNET" />
<uses-permission android:name="android.permission.READ_EXTERNAL_STORAGE" />
<uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" />
```

パーミッション|Protection Level|必須|概要
:---|:---:|:---:|:---
INTERNET|Normal|必須|F.O.X SDKが通信を行うために必要となります。
READ_EXTERNAL_STORAGE|Dangerous|任意|ストレージを利用した重複検知精度を向上させる場合に必要となります。(※1)
WRITE_EXTERNAL_STORAGE|Dangerous|任意|ストレージを利用した重複検知精度を向上させる場合に必要となります。(※1)

> ※1 Android MよりProtectionLevelが`dangerous`に指定されているパーミッションを必要とする機能を利用するには、ユーザーの許可が必要になります。詳細は[外部ストレージを利用した重複排除設定](./external_storage/README.md)をご確認ください。

<div id="install_referrer"></div>
## インストールリファラ計測の設定

インストールリファラ計測を行うための設定は`CYZFox/Source/CYZFox/CYZFox_APL.xml`にて<br>
以下の設定がAndroidManifest.xmlに追加されるよう記述されています。

```xml
<receiver android:name="co.cyberz.fox.FoxInstallReceiver" android:exported="true">
	<intent-filter>
		<action android:name="com.android.vending.INSTALL_REFERRER" />
	</intent-filter>
</receiver>
```

既に"com.android.vending.INSTALL_REFERRER"に対するレシーバークラスが定義されている場合には、下記の複数receiverを共存させるための設定（`CYZFox_APL.xml`にでコメントアウトされている）を有効にしてください。<br>
呼び出したいreceiverクラスのパッケージを指定します。

```xml
<!-- F.O.X SDKから呼び出したい他のレシーバークラス情報をmeta-dataとして記述します -->
<meta-data
		android:name="APPADFORCE_FORWARD_RECEIVER"
		android:value="com.example.InstallReceiver1|com.example.InstallReceiver2|com.example.InstallReceiver3" />
```

> ※ `APPADFORCE_FORWARD_RECEIVER`に指定するクラスはパッケージ付きで指定してください。また、`|`(パイプ)で区切ることで複数のクラスを指定することが可能です。

> ※ Proguardを利用する場合、`APPADFORCE_FORWARD_RECEIVER`に指定するクラスは-keep指定でクラス名が変更されないようにしてください。<br>
Proguardの対象となりますとF.O.X SDKがクラスを探せなくなり正常に動作しませんのでご注意ください。


<div id="track_reengagement"></div>
## リエンゲージメント計測の実装

F.O.X SDKはカスタムURLスキームでアプリを起動し、以下のActivityをコールすることでリエンゲージメント計測を行います。<br>
リエンゲージメントを実施する場合には`CYZFox/Source/CYZFox/CYZFox_APL.xml`に記述されている以下の設定の<br>
`android:scheme`と`android:host`を設定します。<br>
カスタムURLスキーム(scheme://host)を弊社管理者までご連絡ください。

```xml
<activity android:name="co.cyberz.fox.support.ue.IntentReceiverActivity">
  <intent-filter>
      <action android:name="android.intent.action.VIEW" />
      <category android:name="android.intent.category.DEFAULT" />
      <category android:name="android.intent.category.BROWSABLE" />
      <data android:scheme="スキームを設定してください" android:host="必要であればホストを設定します" />
  </intent-filter>
</activity>
```


<div id="others"></div>
## その他

* [（オプション）外部ストレージを利用した重複排除設定](./external_storage/README.md)


---

[トップ](../../../README.md)
