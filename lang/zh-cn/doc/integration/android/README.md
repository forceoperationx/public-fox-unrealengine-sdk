[TOP](../../../README.md)　>　**Android 项目详细设置**

---

# Android 项目详细设置

* [权限设置](#permission)
* [Install Referrer计测](#install_referrer)
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
INTERNET|Normal|必须|此项是F.O.X SDK进行通信的必须条件。
READ_EXTERNAL_STORAGE|Dangerous|任意|在使用外部储存来优化排除重复功能时为必须条件。(※1)
WRITE_EXTERNAL_STORAGE|Dangerous|任意|在使用外部储存来优化排除重复功能时为必须条件。(※1)

> ※1 从Android M开始，使用ProtectionLevel被指定为dangerous权限的功能时，需要用户许可。具体请参考[使用外部储存来优化排除重复功能](./external_storage/README.md)。

<div id="install_referrer"></div>

## Install Referrer计测设置
为了进行Install Referrer计测请在`CYZFox/Source/CYZFox/CYZFox_APL.xml`当中做设置<br>
将以下设置添加至AndroidManifest.xml。

```xml
<receiver android:name="co.cyberz.fox.FoxInstallReceiver" android:exported="true">
	<intent-filter>
		<action android:name="com.android.vending.INSTALL_REFERRER" />
	</intent-filter>
</receiver>
```

已经定义了"com.android.vending.INSTALL_REFERRER"的receiver类的话，请将下面注释掉的使多个INSTALL_REFERRER RECEIVER共存的设置（`CYZFox_APL.xml`中已注释的部分）的代码恢复成有效状态。

指定想要调用的receiver类的包(package)。

```xml
<!-- 用F.O.X SDK调用其他receiver类时的信息用meta-data来记述 -->
<meta-data
		android:name="APPADFORCE_FORWARD_RECEIVER"
		android:value="com.example.InstallReceiver1|com.example.InstallReceiver2|com.example.InstallReceiver3" />
```

> ※ `APPADFORCE_FORWARD_RECEIVER`中指定的类请附上包名(package)。可以用`|`(竖线)隔开来指定多个类。

> ※ 使用Proguard时，`APPADFORCE_FORWARD_RECEIVER`中的类请用-keep来指定，且不要更改类名称。<br>
请注意，如果成为Proguard的对象，F.O.X SDK将无法正常搜索类，将变得无法正常动作。


<div id="track_reengagement"></div>
## 流失唤回广告计测执行

F.O.X SDK使用自定义URL SCHEME启动APP，调用以下Activity来进行流失唤回广告计测。<br>
实施流失唤回广告计测时，按照下面的记述来设置<br>
`android:scheme`和`android:host`到`CYZFox/Source/CYZFox/CYZFox_APL.xml`中<br>
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

* [任意）使用外部储存进行优化重复排查](./external_storage/README.md)


---

[Top](../../../README.md)
