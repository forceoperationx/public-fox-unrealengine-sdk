[TOP](../../../README.md)　>　**Android 项目详细设置**

---

# Android 项目详细设置

* [权限设置](#permission)
* [安装referrer计测](#install_referrer)
* [流失唤回广告计测执行](#track_reengagement)
* [其他](#others)

<div id="permission"></div>
## 权限设置

F.O.X SDK可以使用以下三种权限。

```xml
<uses-permission android:name="android.permission.INTERNET" />
<uses-permission android:name="android.permission.READ_EXTERNAL_STORAGE" />
<uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" />
```

权限|Protection Level|必须|概要
:---|:---:|:---:|:---
INTERNET|Normal|必须|F.O.X SDK是进行通信的必要条件。
READ_EXTERNAL_STORAGE|Dangerous|任意|必须使用储存来优化排除重复功能。(※1)
WRITE_EXTERNAL_STORAGE|Dangerous|任意|必须使用储存来优化排除重复功能。(※1)

> ※1 从Android M版本开始ProtectionLevel被指定为`dangerous`并需要权限的功能时，需要用户许可。具体请参考[利用外部储存优化排除重复设置](./external_storage/README.md)

<div id="install_referrer"></div>
## 安装referrer计测设置
安装referrer计测设置详见`CYZFox/Source/CYZFox/CYZFox_APL.xml`<br>
将以下设置添加至AndroidManifest.xml。

```xml
<receiver android:name="co.cyberz.fox.FoxInstallReceiver" android:exported="true">
	<intent-filter>
		<action android:name="com.android.vending.INSTALL_REFERRER" />
	</intent-filter>
</receiver>
```

"com.android.vending.INSTALL_REFERRER"对应的receiver类已被定义时，请将下面使多个INSTALL_REFERRER RECEIVER共存的设置（`CYZFox_APL.xml`中已注释）设为有效。

指定想要呼出的receiver类package。

```xml
<!-- 用F.O.X SDK呼出其他receiver类时信息记录为meta-data -->
<meta-data
		android:name="APPADFORCE_FORWARD_RECEIVER"
		android:value="com.example.InstallReceiver1|com.example.InstallReceiver2|com.example.InstallReceiver3" />
```

> ※ `APPADFORCE_FORWARD_RECEIVER`中指定的类请附上package。可以用`|`(竖线)隔开多个类。

> ※ 使用Proguard时，`APPADFORCE_FORWARD_RECEIVER`中的类指定为-keep且不要更改类名称。<br>
请注意，如果成为Proguard的对象，F.O.X SDK将无法正常搜索类。


<div id="track_reengagement"></div>
## 流失唤回广告计测执行

F.O.X SDK使用自定义URL SCHEME启动APP，呼出以下Activity来进行流失唤回广告计测。<br>
实施流失唤回广告计测时`CYZFox/Source/CYZFox/CYZFox_APL.xml`中记述的以下设置<br>
设置`android:scheme`和`android:host`。<br>
自定义URL SCHEME(scheme://host)请告知本公司管理员。

```xml
<activity android:name="co.cyberz.fox.support.ue.IntentReceiverActivity">
  <intent-filter>
      <action android:name="android.intent.action.VIEW" />
      <category android:name="android.intent.category.DEFAULT" />
      <category android:name="android.intent.category.BROWSABLE" />
      <data android:scheme="请设置SCHEME" android:host="必要时请设置host" />
  </intent-filter>
</activity>
```


<div id="others"></div>
## 其他

* [任意）使用外部储存进行重复排查设置](./external_storage/README.md)


---

[首页](../../../README.md)
