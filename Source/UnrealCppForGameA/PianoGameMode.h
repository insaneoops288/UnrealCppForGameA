// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PianoGameMode.generated.h"

enum EPianoButtonType
{
	GunBanDo,
	GunBanRe,
	GunBanMi,
	GunBanFa,
	GunBanSol,
	GunBanRa,
	GunBanSi,
	GunBanDoHigh,
};



/**
 * 
 */
UCLASS()
class UNREALCPPFORGAMEA_API APianoGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Piano")
	TArray<class UTexture2D*> Backgrounds;

	UPROPERTY(EditDefaultsOnly, Category = "Piano")
	TSubclassOf<class UUserWidget> WB_PianoWidget;

	UPROPERTY(EditDefaultsOnly, Category = "Piano")
	class UUserWidget* PianoWidget;
	
};
