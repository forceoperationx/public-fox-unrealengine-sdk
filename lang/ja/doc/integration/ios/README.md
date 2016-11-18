[TOP](../../../README.md)　>　**iOS プロジェクトの詳細設定**

---

# iOS プロジェクトの詳細設定

## **Xcodeプロジェクトの設定**

### Xcodeプロジェクトのパブリッシュ

iOS用のプロジェクトを作成するために、次の手順でXcodeプロジェクトをパブリッシュし、Xcode上で必要な設定を行います。

1. メニューの「File」>「BUild Settings…」を選択する
2. Platformの「iOS」を選択し、「Switch Platform」を押下する
3. 「Player Settings」を押下し、Inspectorでご自身の環境に合わせて設定を行う
4. 	「Build」か「Build And Run」を押下し、Xcodeプロジェクトのパブリッシュを行う

### Xcodeプロジェクトの編集

パブリッシュされたXcodeプロジェクトを開き、編集します。

* **フレームワーク設定**

次のフレームワークをプロジェクトにリンクしてください。

<table>
<tr><th>フレームワーク名</th><th>Status</th></tr>
<tr><td>AdSupport.framework</td><td>Optional</td></tr>
<tr><td>Security.framework </td><td>Required </td></tr>
<tr><td>SystemConfig.framework </td><td>Required </td></tr>
</table>

* **App Transport Securityについて**

iOS9より提供されたNSAppTransportSecurity(以下、ATS)を有効にしている場合、Info.plistに以下の設定を行いF.O.X SDKが行う通信先のドメインをATSの例外としてください。

キー | タイプ | 概要
:---: | :---: | :---
NSExceptionDomains|Dictionary|ATSの例外を指定するディクショナリー
指定ドメイン文字列|Dictionary|以下２つのドメインをキーで作成してください。<br>・app-adforce.jp<br>・forceoperationx.com
NSExceptionAllowsInsecureHTTPLoads|Boolean|YES を指定してくださいATSの例外とします。
NSIncludesSubdomains|Boolean|YES を指定しATSの例外設定をサブドメインにも適用させます。

![ATS設定](./img_ats.png)

---
[戻る](../README.md)

[トップ](../../../README.md)
