// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "Components/Image.h"

#include "ListViewObject.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCPPFORGAMEA_API UListViewObject : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = "true"))
	FString ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = "true"))
	UTexture2D* ItemTexture;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = "true"))
	UParticleSystem* ItemFX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (AllowPrivateAccess = "true"))
	FString FXName;

	FString GetItemName() const
	{
		return ItemName;
	}

	void SetItemName(const FString& Name)
	{
		ItemName = Name;
	}

	class UTexture2D* GetItemImage() const
	{
		return ItemTexture;
	}

	void SetItemImage(const FString& Name)
	{
		FString Texture2DPath = Name;
		UTexture2D* Texture2DAsset = LoadObject<UTexture2D>(NULL, *Texture2DPath, NULL, LOAD_None, NULL);

		if (Texture2DAsset)
		{
			UE_LOG(LogTemp, Warning, TEXT("Texture2DAsset : %s"), *Texture2DAsset->GetName());
			ItemTexture = Texture2DAsset;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Texture2D을 찾을 수가 없습니다."));
		}
	}

	class FString GetFXPath() const
	{
		return FXName;
	}

	void SetFXPath(const FString Name)
	{
		FXName = Name;
	}
	
};
