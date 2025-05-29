// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "Engine/DataTable.h"

#include "WrapBoxGameMode.generated.h"

USTRUCT()
struct FItemTable : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseGameInfo")
	int32 ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseGameInfo")
	FString Image;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseGameInfo")
	FString ItemName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseGameInfo")
	int32 Saleprice;
};

/**
 * 
 */
UCLASS()
class UNREALCPPFORGAMEA_API AWrapBoxGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "WrapBox")
	TSubclassOf<class UUserWidget> WBP_WrapBox;

	UPROPERTY()
	class UUserWidget* WrapBoxWidget;

	UPROPERTY(EditDefaultsOnly, Category = "WrapBox")
	TSubclassOf<class UUserWidget> WBP_WrapBoxItem;

	UPROPERTY()
	TArray<class UUserWidget*> WrapBoxItems;

	UPROPERTY()
	class UWrapBox* WrapBox;
	
};
