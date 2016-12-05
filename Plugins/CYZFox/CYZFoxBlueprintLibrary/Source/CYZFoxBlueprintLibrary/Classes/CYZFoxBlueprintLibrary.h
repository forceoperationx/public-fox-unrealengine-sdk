// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CYZFoxBlueprintLibrary.generated.h"

USTRUCT(BlueprintType)
struct FCYZFoxConfig {

  GENERATED_USTRUCT_BODY();

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Config")
  int32 appId_ios = 0;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Config")
  FString iosSalt;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Config")
  FString appKey_ios;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Config")
  bool iosWebViewTrackingEnabled = 0;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Config")
  int32 androidAppId = 0;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Config")
  FString androidSalt;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Config")
  FString androidAppKey;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Config")
  FString foxServerURL;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Config")
  FString analyticsServerURL;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Config")
  bool debugMode = 0;
};

USTRUCT(BlueprintType)
struct FCYZFoxTrackOption {

  GENERATED_USTRUCT_BODY();

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Track")
  bool optout;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Track")
  FString redirectURL;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Track")
  FString buid;

};

USTRUCT(BlueprintType)
struct FCYZFoxEventParam
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Event")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Event")
	FString Value;
};

USTRUCT(BlueprintType)
struct FFoxEventAttr
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Event")
	FString eventName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Event")
	int32 ltvId = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Event")
	FString buid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Event")
	int32 eventValue = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Event")
	FString orderId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Event")
	FString sku;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Event")
	FString itemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Event")
	float price;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Event")
	int32 quantity = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Event")
	FString currency;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Event")
	TArray<FCYZFoxEventParam> extraInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CYZFox|Event")
	FString eventInfoJson;
};

UCLASS()
class UCYZFoxBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, Category="CYZFox|Track")
	static void Activate(const FCYZFoxConfig config);

	UFUNCTION(BlueprintCallable, Category="CYZFox|Track")
	static void TrackInstall();

	UFUNCTION(BlueprintCallable, Category="CYZFox|Track")
	static void TrackInstallWithOption(const FCYZFoxTrackOption option);

	UFUNCTION(BlueprintCallable, Category="CYZFox|Event")
	static void TrackSession();

	UFUNCTION(BlueprintCallable, Category="CYZFox|Event")
	static void TrackEvent(const FFoxEventAttr attr);

	UFUNCTION(BlueprintCallable, Category="CYZFox|Track")
	static bool IsConversionComplete();

	UFUNCTION(BlueprintCallable, Category="CYZFox|Event")
	static void TrackByBrowser(FString url);

  UFUNCTION(BlueprintCallable, Category="CYZFox|Event")
	static void SetUserInfo(const FString jsonObj);

  UFUNCTION(BlueprintCallable, Category="CYZFox|Event")
	static FString GetUserInfo();
};
