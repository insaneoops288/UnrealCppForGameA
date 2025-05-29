// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "DataSaveGame.generated.h"

USTRUCT(BlueprintType)
struct FSaveGameStruct
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
		int32 StructInteger;
};

/**
 * 
 */
UCLASS()
class UNREALCPPFORGAMEA_API UDataSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
	FString SaveSlotName;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
	int32 SaveSlotIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
	FSaveGameStruct SaveStruct;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
	TArray<int32> SaveTArray;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
	int32 SaveInt;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
	float SaveFloat;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
	FString SaveString;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
	FName SaveName;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
	FVector SaveVector;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
	FRotator SaveRotator;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "SaveData")
	FTransform SaveTransform;
	
};
