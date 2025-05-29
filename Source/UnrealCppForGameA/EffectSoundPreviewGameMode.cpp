// Fill out your copyright notice in the Description page of Project Settings.


#include "EffectSoundPreviewGameMode.h"

#include "Blueprint/UserWidget.h"

void AEffectSoundPreviewGameMode::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	GetWorld()->GetFirstPlayerController()->bEnableClickEvents = true;
	GetWorld()->GetFirstPlayerController()->bEnableMouseOverEvents = true;

	if (WBP_EffectSoundPreview)
	{
		EffectSoundPreviewUserWidget = 
			CreateWidget<UUserWidget>(GetWorld(), WBP_EffectSoundPreview);

		if (EffectSoundPreviewUserWidget)
		{
			EffectSoundPreviewUserWidget->AddToViewport();
		}
	}
}

