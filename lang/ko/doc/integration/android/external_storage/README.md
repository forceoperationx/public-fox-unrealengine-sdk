[TOP](../../../../README.md)　>　[Android 프로젝트의 상세 설정](../README.md)　>　**외부 스토레지를 이용한 중복 검치 설정**

---

# 외부 스토레지를 이용한 중복 검치 정확도를 향상하기 위한 설정

애플리케이션의 초기 기동시에 SDK 생성된 식별ID를 로컬 스토레지 또는 SD카드에 보존하여 애플리케이션 재인스톨시에 중복 판정이 가능하게 됩니다.

본 설정은 필수가 아니지만 애플리케이션의 재인스톨에 있어 중복 검치의 정확도가 대폭 향상되므로 구현을 추천하고 있습니다.
또한 본 설정은 option이므로 필요한 경우에는 아래를 참고로 `CYZFox/Source/CYZFox/CYZFox_APL.xml`에 기술하여 주십시오.

### permission의 설정

외부 스토레지에 파일 읽기/쓰기에 필요한 permission의 설정을 AndroidManifest.xml의 <manifest>태그 내에 추가합니다.<br>
중복 검치 정확도의 향상은 이하 permission을 추가하는 것만으로 유효화 됩니다. 또한 이미 앱에서 이용하고 있는 경우에는 이 설정을 불필요합니다.

```xml
<uses-permission android:name="android.permission.READ_EXTERNAL_STORAGE" />
<uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" />
```

상기 permission이 설정되어 있는 경우 다음의 패스에 식별 ID파일이 보존됩니다.

```
Environment.getExternalStorageDirectory().getPath()에서 취득 가능한 패스/애플리케이션 패키지명/__FOX_XUNIQ__
```

아직 앱에 설정되어 있지 않은 경우 이 기능을 이용하실 경우에는 `CYZFox/Source/CYZFox/CYZFox_APL.xml`에 기술되어 있는
이하의 Comment out를 해제하여 유효화 하여 주십시오.

```xml
<addElements tag="manifest">
	<!-- <uses-permission android:name="android.permission.READ_EXTERNAL_STORAGE" />
	<uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" /> -->
</addElements>
```

### （임의）보존 디렉토리 및 파일명의 변경

보존된 파일의 디렉토리명은 표준으로써 패키지명으로 작성됩니다만, &lt;addElements tag="application"&gt;태그내의 이하 설정을 추가하여 임의의 디렉토리명 또는 파일명으로 변경 가능합니다.

```xml
<meta-data
	android:name="APPADFORCE_ID_DIR"
	android:value="임의의 디렉토리명" />
<meta-data
	android:name="APPADFORCE_ID_FILE"
	android:value="임의의 파일명" />
```

> 임의의 디렉토리명 및 파일명을 지정하신 경우에도 Environment.getExternalStorageDirectory().getPath()의 리턴값의 패스의 장소에 작성됩니다. Environment.getExternalStorageDirectory().getPath()의 리턴값은 단말 및 OS버젼에 따라 다릅니다.<br>

> `APPADFORCE_ID_DIR`(임의의 디렉토리명)을 미지정의 상태에서 임의의 파일명만을 지정한 경우 앱의 패키지명의 디렉토리가 작성되어 임의의 파일명으로 보존됩니다.<br>

> ※ `APPADFORCE_ID_FILE`(임의의 파일명)을 미지정 상태에서 임의의 디렉토리명만을 지정한 경우, 임의의 명칭으로 디렉토리가 작성되어 "__FOX_XUNIQ__"로써 보존됩니다.<br>
보통은 설정의 필요가 없습니다.


### 설정예

AndroidManifest.xml의 설정예를 아래에 기재합니다.

```xml
<androidManifestUpdates>
    <addElements tag="manifest">
      <uses-permission android:name="android.permission.READ_EXTERNAL_STORAGE" />
      <uses-permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" />
    </addElements>
		<addElements tag="application">
			...
			<meta-data
				android:name="APPADFORCE_ID_DIR"
				android:value="fox_id_dir" />
			<meta-data
				android:name="APPADFORCE_ID_FILE"
				android:value="fox_id_file" />
			...
		</addElements>
</androidManifestUpdates>
```

상기 예의 경우 보존된 파일의 패스는 다음과 같습니다.

```
Environment.getExternalStorageDirectory().getPath()에서 취득 되는 패스/fox_id_dir/fox_id_file
```

### 외부 스토레지의 이용 정지

Force Operation X SDK에 의한 외부 스토레지에 대한 액세스를 정지하실 경우에는 &lt;addElements tag="application"&gt;태그내에 APPADFORCE_USE_EXTERNAL_STORAGE의 설정을 추가하여 주십시오
```xml
<meta-data
	android:name="APPADFORCE_USE_EXTERNAL_STORAGE"
	android:value="0" />
```

본 설정을 실행하여 외부 스토레지에 대한 기록이 정지됩니다.


### Android M(6.0)における注意点
protectionLevel이 dangerous에 지정되어있는 권한을 필요로하는 기능을 이용하려면 사용자의 허가가 필요합니다.
사용자의 권한이 없을 경우 저장 공간에 데이터 저장이 되지 않기 때문에 중복 제거 설정을 사용할 수 없습니다.
앞에서 설명한READ_EXTERNAL_STORAGE과 WRITE_EXTERNAL_STORAGE에서도 dangerous로 되어 있어, 사용자에게 허가를 받기 위해 구현해야합니다.

> [구현의 참고 (Android Developers)](https://developer.android.com/training/permissions/requesting.html#perm-request)

---
[back](../README.md)

[Top](../../../../README.md)
