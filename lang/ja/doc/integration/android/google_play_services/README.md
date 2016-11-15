[TOP](../../../../README.md)　>　[Unityプラグインの導入手順](../../README.md)　>　[Android プロジェクトの詳細設定](../README.md)　>　**Google Play Servicesの導入**

---

# Google Play Servicesの導入

Google Play Servicesをプロジェクトに取り込みます。<br>

アプリケーションのモジュールディレクトリにあるbuild.gradleを開き、下記のように、最新のGoogle Play servicesへのdependenciesの設定を追記します。

```
dependencies {
	compile 'com.google.android.gms:play-services:9.4.0'
}
```
> ※ GooglePlayServicesの導入詳細は[`Setting Up Google Play Services | Android Developers`](https://developer.android.com/google/play-services/setup.html)をご確認ください。


> ※ ADTのEclipseサポート終了に伴いEclipseでの導入は廃止しました。<br>開発されている環境がEclipseの場合、[Google Play Services Jar Resolver Library for Unity](https://github.com/googlesamples/unity-jar-resolver)を用いてGooglePlayServicesを導入してください。

## メソッド数の上限が64Kの仕様について

Androidアプリでは、保持できるメソッド数に64K(65536)の上限があり、超えるとビルドエラーが発生します。<br>
そのため多くのメソッドを有しているGooglePlayServicesを、広告IDの取得のためだけに導入されている場合は<br>
広告IDの取得を目的に切り出された以下のライブラリをお使いください。<br>
F.O.X SDKではGooglePlayServicesを広告IDの取得を目的に利用しています。

```
dependencies {
	compile 'com.google.android.gms:play-services-ads:9.4.0'
}
```

> ※ メソッド数の上限が64Kの仕様についての詳細<br>
[Configure Apps with Over 64K Methods | Android Developers](https://developer.android.com/studio/build/multidex.html)

> ※ Google Play servicesの最新のバージョンはAndroidのデベロッパーサイトにて確認するようにしてください。<br>
[Google Play Services | Android Developers](https://developer.android.com/google/play-services/index.html)


## Google Playデベロッパープログラムへの準拠

Force Operation X Android SDKはGoogle Playデベロッパープログラムポリシーに準拠しています。本SDKはポリシーに準拠するために、永続的なデバイス ID（IMEI、MACアドレス及びAndroidID）が取得される場合には広告IDが取得されません。2014年8月1日から、Google Playストアにアップロードされたすべての更新や新着アプリには、広告目的で使用する端末IDには広告ID を利用する必要があります。本ポリシーに準拠するために、以下の手順を行ってください。

---
[トップ](../../README.md)
