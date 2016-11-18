[TOP](../../../../README.md)　>　[Android プロジェクトの詳細設定](../README.md)　>　**外部ストレージを利用した重複排除設定**

---

# 外部ストレージを利用した重複検知精度を向上させる設定

アプリケーションの初回起動時にSDKが生成した識別IDをローカルストレージまたはSDカードに保存することで、アプリケーション再インストール時に重複判定を行うことができます。

本設定は必須ではありませんが、アプリケーションの再インストールにおける重複検知の精度が大きく向上するため、実装を推奨しております。
また、本設定はオプションのため、必要な場合は以下に従って`CYZFox/Source/CYZFox/CYZFox_APL.xml`に追記してください。

### パーミッションの設定

外部ストレージへのファイル読み書きに必要なパーミッションの設定をAndroidManifest.xmlの<manifest>タグ内に追加します。<br>
重複検知精度の向上は以下パ＝ミッションを追加するだけで、有効となります。また、既にアプリ側で利用されている場合には本設定は不要となります。

```xml
<uses-permission android:name="android.permission.READ_EXTERNAL_STORAGE" /><uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" />
```

上記パーミッションが設定されている場合、次のパスに識別IDファイルが保存されます。

```
Environment.getExternalStorageDirectory().getPath()で取得できるパス/アプリのパッケージ名/__FOX_XUNIQ__
```

まだアプリに設定されておらず、本機能を利用する場合は`CYZFox/Source/CYZFox/CYZFox_APL.xml`に記述されている
以下のコメントアウトを外し有効にしてください。

```xml
<addElements tag="manifest">
	<!-- <uses-permission android:name="android.permission.READ_EXTERNAL_STORAGE" />
	<uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" /> -->
</addElements>
```

### （任意）保存ディレクトリ及びファイル名の変更

保存されるファイルのディレクトリ名は、標準ではパッケージ名で作成されますが、&lt;addElements tag="application"&gt;タグ内に以下設定を追加することで、任意のディレクトリ名及びファイル名に変更することができます。

```xml
<meta-data
	android:name="APPADFORCE_ID_DIR"
	android:value="任意のディレクトリ名" />
<meta-data
	android:name="APPADFORCE_ID_FILE"
	android:value="任意のファイル名" />
```

> 任意のディレクトリ名やファイル名を指定した場合でも、Environment.getExternalStorageDirectory().getPath()の返り値のパス配下に作成します。Environment.getExternalStorageDirectory().getPath()の返り値は端末やOSバージョンによって異なります。<br>

> `APPADFORCE_ID_DIR`(任意のディレクトリ名)を指定せず、任意のファイル名のみを指定した場合、アプリのパッケージ名のディレクトリが作成され、その配下に任意のファイル名で保存されます。<br>

> ※ `APPADFORCE_ID_FILE`(任意のファイル名)を指定せず、任意のディレクトリ名のみを指定した場合、任意の名前でディレクトリが作成され、その配下に"__FOX_XUNIQ__"で保存されます。<br>
通常は設定の必要はありません。


### 設定例

AndroidManifest.xmlの設定例を次に記載します。

```xml
<androidManifestUpdates>
    <addElements tag="manifest">
      <uses-permission android:name="android.permission.READ_EXTERNAL_STORAGE" />
      <uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" />
    </addElements>
		<addElements tag="application">			...			<meta-data
				android:name="APPADFORCE_ID_DIR"
				android:value="fox_id_dir" />
			<meta-data
				android:name="APPADFORCE_ID_FILE"
				android:value="fox_id_file" />
			...
		</addElements>
</androidManifestUpdates>
```

上記の例の場合に、保存されるファイルのパスは次になります。

```
Environment.getExternalStorageDirectory().getPath()で取得できるパス/fox_id_dir/fox_id_file
```

### 外部ストレージの利用停止

Force Operation X SDKによる外部ストレージへのアクセスを停止したい場合には、&lt;addElements tag="application"&gt;タグ内にAPPADFORCE_USE_EXTERNAL_STORAGEの設定を追加してください。
```xml
<meta-data
	android:name="APPADFORCE_USE_EXTERNAL_STORAGE"
	android:value="0" />
```

本設定を行うことで外部ストレージに対する記録が停止します。


### Android M(6.0)における注意点

protectionLevelがdangerousに指定されているパーミッションを必要とする機能を利用するには、ユーザーの許可が必要となります。
ユーザーの許可がない場合、ストレージ領域へのデータ保存が行えなくなるため重複排除設定が利用出来なくなります。
前述の`READ_EXTERNAL_STORAGE`と`WRITE_EXTERNAL_STORAGE`においてもdangerousとなっており、ユーザーに許可を貰うための実装を行う必要があります。

> [実装の参考 (Android Developers)](https://developer.android.com/training/permissions/requesting.html#perm-request)

---
[戻る](../README.md)

[トップ](../../../../README.md)
