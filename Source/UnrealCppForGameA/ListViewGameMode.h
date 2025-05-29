// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataTable.h"

#include "GameFramework/GameModeBase.h"
#include "ListViewGameMode.generated.h"

USTRUCT()
struct FListViewTableRow : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ListVliew")
	int32 ID;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ListVliew")
	FString FXName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ListVliew")
	FString FXImagePath;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ListVliew")
	FString FXPath;
};

/**
 * 
 */
UCLASS()
class UNREALCPPFORGAMEA_API AListViewGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<class UUserWidget> WBP_ListViewItemList;

	class UUserWidget* ListViewItemList;

	virtual void BeginPlay() override;

	UPROPERTY()
	class UParticleSystemComponent* CurrentFX;
	
};
