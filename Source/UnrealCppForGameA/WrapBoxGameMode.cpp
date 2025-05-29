// Fill out your copyright notice in the Description page of Project Settings.


#include "WrapBoxGameMode.h"

#include "Blueprint/UserWidget.h"

void AWrapBoxGameMode::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	GetWorld()->GetFirstPlayerController()->bEnableClickEvents = true;
	GetWorld()->GetFirstPlayerController()->bEnableMouseOverEvents = true;

	if (WBP_WrapBox)
	{
		WrapBoxWidget = CreateWidget<UUserWidget>(GetWorld(), WBP_WrapBox);

		if (WrapBoxWidget)
		{
			WrapBoxWidget->AddToViewport();
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("WrapBoxWidget을 생성 할 수 없습니다. !!"));
		}
	}
}

