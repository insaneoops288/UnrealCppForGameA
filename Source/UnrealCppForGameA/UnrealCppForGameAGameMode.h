// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UnrealCppForGameAGameMode.generated.h"

UCLASS(minimalapi)
class AUnrealCppForGameAGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AUnrealCppForGameAGameMode();

	UPROPERTY(EditDefaultsOnly, Category = "Players")
	TArray<TSubclassOf<class AUnrealCppForGameACharacter>> Players;
};



