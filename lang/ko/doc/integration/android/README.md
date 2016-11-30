[TOP](../../../README.md)　>　**Android 프로젝트의 상세 설정**

---

# Android 프로젝트의 상세 설정

* [permission의 설정](#permission)
* [인스톨 리퍼러 계측의 설정](#install_referrer)
* [리엔게이지멘트 계측의 구현](#track_reengagement)
* [기타](#others)

<div id="permission"></div>
## permission의 설정

F.O.X SDK에서는 다음의 설정을 이용합니다.

```xml
<uses-permission android:name="android.permission.INTERNET" />
<uses-permission android:name="android.permission.READ_EXTERNAL_STORAGE" />
<uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" />
```

permission|Protection Level|필수|개요
:---|:---:|:---:|:---
INTERNET|Normal|필수|F.O.X SDK의 통신을 실행하기 위하여 필요합니다.
READ_EXTERNAL_STORAGE|Dangerous|임의|스토레지를 이용한 중복 검치 정확도를 향상하기 위하여 필요합니다.(※1)
WRITE_EXTERNAL_STORAGE|Dangerous|임의|스토레지를 이용한 중복 검치 정확도를 향상히기 위하여 필요합니다.(※1)

> ※1 Android M에서 부터 ProtectionLevel이 `dangerous`로 지정되어 있기 때문에 permission을 필요로하는 기능을 이용하기 위해서는 유저의 허가가 필요하게 되었습니다. 상세는[외부 스토레지를 이용한 중복 배제 설정](./external_storage/README.md)을 지정하여 주십시오.

<div id="install_referrer"></div>
## 인스톨 리퍼러 계측의 설정

인스톨 리퍼러 계측을 실행하기 위한 설정은 `CYZFox/Source/CYZFox/CYZFox_APL.xml`에서<br>
이하의 설정이 AndroidManifest.xml에 추가 되도록 기술되어 있습니다.

```xml
<receiver android:name="co.cyberz.fox.FoxInstallReceiver" android:exported="true">
	<intent-filter>
		<action android:name="com.android.vending.INSTALL_REFERRER" />
	</intent-filter>
</receiver>
```

이미 "com.android.vending.INSTALL_REFERRER"에 대한 레시버 클래스가 정의 되어있는 경우에는 아래의 복수 receiver를 공존시키기 위한 설정（`CYZFox_APL.xml`에서 Comment out 되어 있습니다.）를 유효로 하여 주십시오<br>
호출 하고픈 receiver클래스의 패키지를 지정합니다.

```xml
<!-- F.O.X SDK에서 호출 하고픈 그외의 레시버 클래스 정보를 meta-data로써 기술 합니다. -->
<meta-data
		android:name="APPADFORCE_FORWARD_RECEIVER"
		android:value="com.example.InstallReceiver1|com.example.InstallReceiver2|com.example.InstallReceiver3" />
```

> ※ `APPADFORCE_FORWARD_RECEIVER`를 지정하는 클래스는 패키지 첨부로써 지정하여 주십시오. 또한, `|`(pipe)로 구분하여 복수의 클래스를 지정 가능합니다.

> ※ Proguard를 이용하는 경우, `APPADFORCE_FORWARD_RECEIVER`에 지정한 클래스는 -keep지정으로 클래스명이 변경되지 않도록 하여 주십시오<br>
Proguard의 대상이 될 경우 F.O.X SDK가 클래스를 찾을수 없게되어 정상적인 동작이 되지 않게 되므로 주의하여 주십시오.


<div id="track_reengagement"></div>
## 리엔게이지멘트 계측의 구현

F.O.X SDK는 커스텀 URL스키마로 앱을 기동하여 이하의 Activity를 콜하여 리엔게이지멘트 계측을 실행합니다.<br>
리엔게이지멘트를 실시할 경우 `CYZFox/Source/CYZFox/CYZFox_APL.xml`에 기술된 이하의 설정의<br>
`android:scheme`와`android:host`를 설정합니다.<br>
커스텀 URL스키마(scheme://host)를 폐사 관리자에 연락하여 주십시오.

```xml
<activity android:name="co.cyberz.fox.support.ue.IntentReceiverActivity">
  <intent-filter>
      <action android:name="android.intent.action.VIEW" />
      <category android:name="android.intent.category.DEFAULT" />
      <category android:name="android.intent.category.BROWSABLE" />
      <data android:scheme="스키마를 지정하여 주십시오" android:host="필요한 경우 호스ㅡ를 설정합니다." />
  </intent-filter>
</activity>
```


<div id="others"></div>
## 기타

* [（option）외부 스토레지를 이용한 중복 배제 설정](./external_storage/README.md)


---

[Top](../../../README.md)
