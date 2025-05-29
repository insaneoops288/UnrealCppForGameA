// Fill out your copyright notice in the Description page of Project Settings.


#include "PianoGameMode.h"

#include "Blueprint/UserWidget.h"

void APianoGameMode::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	GetWorld()->GetFirstPlayerController()->bEnableClickEvents = true;
	GetWorld()->GetFirstPlayerController()->bEnableMouseOverEvents = true;

	if (WB_PianoWidget)
	{
		PianoWidget = CreateWidget<UUserWidget>(GetWorld(), WB_PianoWidget);

		if (PianoWidget)
		{
			PianoWidget->AddToViewport();
		}
	}
}

