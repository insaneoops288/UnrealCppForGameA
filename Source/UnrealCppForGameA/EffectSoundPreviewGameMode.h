// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EffectSoundPreviewGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCPPFORGAMEA_API AEffectSoundPreviewGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "UI")
	TSubclassOf<class UUserWidget> WBP_EffectSoundPreview;

	class UUserWidget* EffectSoundPreviewUserWidget;
	
};
