// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/DataTable.h"
#include "UnrealCppForGameAGameInstance.generated.h"


USTRUCT()
struct FBaseGameInfoTableRow : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseGameInfo")
	int32 IntValue;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BaseGameInfo")
	float FloatValue;
};

UENUM(BlueprintType)
enum class EBaseGameInfoState : uint8
{
	PlayerBaseHealth UMETA(DisplayName = "PlayerBaseHealth"),
	CreatureBaseHealth UMETA(DisplayName = "CreatureBaseHealth"),
	BossBaseHealth UMETA(DisplayName = "BossBaseHealth"),
	SearchRadius UMETA(DisplayName = "SearchRadius"),
	AttackRadius UMETA(DisplayName = "AttackRadius"),
};

/**
 * 
 */
UCLASS()
class UNREALCPPFORGAMEA_API UUnrealCppForGameAGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UUnrealCppForGameAGameInstance();

	UPROPERTY(EditDefaultsOnly, Category = "Table", meta = (AllowPrivateAccess = true))
	class UDataTable* BaseGameInfoTable;

	FBaseGameInfoTableRow* GetBaseGameInfoTable(FName Name);

	FString GetEnumDisplayNameToString(EBaseGameInfoState EnumValue) const;
};
