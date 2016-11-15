[TOP](../../../README.md)　>　[Unityプラグインの導入手順](../README.md)　>　**Android プロジェクトの詳細設定**

---

# Android プロジェクトの詳細設定

* [Gradle経由での導入](#install_by_gradle)
* [AndroidManifest.xmlのサンプルについて](#sample_manifest)
* [パーミッションの設定](#permission)
* [インストールリファラ計測の設定](#install_referrer)
* [リエンゲージメント計測の実装](#track_reengagement)
* [ProGuardを利用する場合](#proguard)
* [その他](#others)

<div id="install_by_gradle"></div>
## Gradle経由での導入

Android StudioプロジェクトでGradleを用いてSDKを導入する場合以下のDependenciesを設定します。

```groovy
repositories {
    maven {
        url "https://github.com/cyber-z/public-fox-android-sdk/raw/master/mavenRepo"
    }
}

dependencies {
    compile 'co.cyberz.fox:track-core:4.0.0'
    compile 'co.cyberz.fox.support:track-unity:1.0.0'
}
```


<div id="sample_manifest"></div>
## AndroidManifest.xmlのサンプルについて

Android 用の設定は Unity プロジェクト上で行うことができます。Unity プロジェクトに組み込まれた
AndroidManifest.xml を編集します。<br>プロジェクトに AndroidManifest.xml が存在しない場合は、 「Plugins/Android/AndroidManifest-sample.xml」を「AndroidManifest.xml」にリネームしてご利用ください。

<div id="permission"></div>
## パーミッションの設定

F.O.X SDKでは下記4つのパーミッションを利用します。
&lt;Manifest&gt;タグ内に次のパーミッションの設定を追加します。

```xml
<uses-permission android:name="android.permission.INTERNET" />
<uses-permission android:name="android.permission.READ_EXTERNAL_STORAGE" />
<uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" />
```

パーミッション|Protection Level|必須|概要
:---|:---:|:---:|:---
INTERNET|Normal|必須|F.O.X SDKが通信を行うために必要となります。
READ_EXTERNAL_STORAGE|Dangerous|任意|ストレージを利用した重複排除機能向上に必要となります。(※1)
WRITE_EXTERNAL_STORAGE|Dangerous|任意|ストレージを利用した重複排除機能向上に必要となります。(※1)

> ※1 Android MよりProtectionLevelが`dangerous`に指定されているパーミッションを必要とする機能を利用するには、ユーザーの許可が必要になります。詳細は[外部ストレージを利用した重複排除設定](./external_storage/README.md)をご確認ください。

<div id="install_referrer"></div>
## インストールリファラ計測の設定
インストールリファラーを用いたインストール計測を行うために下記の設定を&lt;application&gt;タグに追加します。

```xml
<receiver android:name="co.cyberz.fox.FoxInstallReceiver" android:exported="true">
	<intent-filter>
		<action android:name="com.android.vending.INSTALL_REFERRER" />
	</intent-filter>
</receiver>
```

既に"com.android.vending.INSTALL_REFERRER"に対するレシーバークラスが定義されている場合には、[二つ以上のINSTALL_REFERRERレシーバーを共存させる場合の設定](./install_referrer/README.md)をご参照ください。

<div id="track_reengagement"></div>
## リエンゲージメント計測の実装

カスタムURLスキーム経由の起動を計測するために必要な設定を<application>タグ内に追記します。
以下の`IntentReceiverActivity`はF.O.X SDKで提供しているActivityとなります。

カスタムURLスキームで本Activityが呼び出されることでリエンゲージメント計測を行います。
ここでのカスタムURLスキームは他のActivityに設定しているものとは異なる値を設定してください。

```xml
<activity android:name="co.cyberz.fox.support.unity.IntentReceiverActivity ">
	<intent-filter>
		<action android:name="android.intent.action.VIEW" />
		<category android:name="android.intent.category.DEFAULT" />
		<category android:name="android.intent.category.BROWSABLE" />
		<data android:scheme="カスタム URL スキーム" />
	</intent-filter>
</activity>
```

<div id="proguard"></div>
## ProGuardを利用する場合

ProGuard を利用してアプリケーションの難読化を行う際は F.O.X SDK のメソッドが対象とならないよう、以下の設定 を追加してください。

```
-keepattributes *Annotation*
-keep class co.cyberz.** { *; }
-keep class com.google.android.gms.ads.identifier.* { *; }
-dontwarn co.cyberz.**
# Gradle経由でSDKをインストールしている場合、下記jarファイルの指定は不要です。
-libraryjars libs/FOX_Android_SDK_<VERSION>.jar

```

また、Google Play Service SDK を導入されている場合は、以下のぺージに記載されている keep 指定が記述されているかご確認ください。

> [Google Play Services導入時のProguard対応 (Android Developers)](https://developer.android.com/google/play-services/setup.html#Proguard)

<div id="others"></div>
## その他

* [広告IDを利用するためのGoogle Play Services SDKの導入](./google_play_services/README.md)

* [AndroidManifest.xml 設定サンプル](./config_android_manifest/AndroidManifest.xml)

* [（オプション）外部ストレージを利用した重複排除設定](./external_storage/README.md)

* [（オプション）Android M オートバックアップ機能の利用](./auto_backup/README.md)


---
[戻る](../README.md)

[トップ](../../../README.md)
