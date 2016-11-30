[TOP](../../../README.md)　>　**iOS プロジェクトの詳細設定**

---

# iOS プロジェクトの詳細設定

## **1.カスタマイズ URL Scheme設定**
下記のいずれの設定を行ってください。

### UE4Editorで設定する場合
UE4Editorツールから `Settings > Project Settings > iOS > Extra Plist Data`に下記の設定を追加してください。
```xml
<key>CFBundleURLTypes</key><array><dict><key>CFBundleTypeRole</key><string>Editor</string><key>CFBundleURLSchemes</key><array><string>my.game</string></array></dict></array>
```
![Menu](./ios_menu.png)
![ExtraPlistData](./ios_extra.png)

### iniファイルを直接編集する場合
1. `[project folder]/Config/DefaultEngine.ini`ファイルに開く。
2. `[/Script/IOSRuntimeSettings.IOSRuntimeSettings]`の設定場所を探し、なければ追加します。
3. 下記の設定を追加する。
```ini
AdditionalPlistData=<key>CFBundleURLTypes</key><array><dict><key>CFBundleTypeRole</key><string>Editor</string><key>CFBundleURLSchemes</key><array><string>my.game</string></array></dict></array>
```

> ここの`my.game`は一例だけです、実際は各自のURL Schemeに変更してください。

## **2. ビルド設定**
`CYZFox` プラグインはObjective-C Category クラス拡張機能を利用しているので、下記の様にビルド設定に`-ObjC`フラグを追加してください。

### UE4Editorで設定する場合
UE4Editorツールから `Settings > Project Settings > iOS > Additional Linker Flags`に`-ObjC`を追加してください。

![LinkerFlag](./ios_linker.png)

### iniファイルを直接編集する場合
1. `[project folder]/Config/DefaultEngine.ini`ファイルに開く。
2. `[/Script/IOSRuntimeSettings.IOSRuntimeSettings]`の設定場所を探し、なければ追加します。
3. 下記の設定を追加する。
```ini
AdditionalLinkerFlags=-ObjC
```
---

[トップ](../../../README.md)
