// Fill out your copyright notice in the Description page of Project Settings.


#include "PianoUserWidget.h"

#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "PianoGameMode.h"
#include "Kismet/GameplayStatics.h"

void UPianoUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ButtonDo)
		ButtonDo->OnClicked.AddDynamic(this, &UPianoUserWidget::ButtonDoClicked);

	if (ButtonRe)
		ButtonRe->OnClicked.AddDynamic(this, &UPianoUserWidget::ButtonReClicked);

	if (ButtonMi)
		ButtonMi->OnClicked.AddDynamic(this, &UPianoUserWidget::ButtonMiClicked);

	if (ButtonFa)
		ButtonFa->OnClicked.AddDynamic(this, &UPianoUserWidget::ButtonFaClicked);

	if (ButtonSol)
		ButtonSol->OnClicked.AddDynamic(this, &UPianoUserWidget::ButtonSolClicked);

	if (ButtonRa)
		ButtonRa->OnClicked.AddDynamic(this, &UPianoUserWidget::ButtonRaClicked);

	if (ButtonSi)
		ButtonSi->OnClicked.AddDynamic(this, &UPianoUserWidget::ButtonSiClicked);

	if (ButtonDoHigh)
		ButtonDoHigh->OnClicked.AddDynamic(this, &UPianoUserWidget::ButtonDoHighClicked);
}


void UPianoUserWidget::ButtonDoClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("ButtonDoClicked"));
	TextInfo->SetText(FText::FromString(TEXT("Do")));

	APianoGameMode* GameMode =
		Cast<APianoGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	if (GameMode)
	{
		ImageBackground->SetBrushFromTexture(GameMode->Backgrounds[(int32)EPianoButtonType::GunBanDo]);
	}
}

void UPianoUserWidget::ButtonReClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("ButtonReClicked"));
	TextInfo->SetText(FText::FromString(TEXT("Re")));

	APianoGameMode* GameMode =
		Cast<APianoGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	if (GameMode)
	{
		ImageBackground->SetBrushFromTexture(GameMode->Backgrounds[(int32)EPianoButtonType::GunBanRe]);
	}
}

void UPianoUserWidget::ButtonMiClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("ButtonMiClicked"));
	TextInfo->SetText(FText::FromString(TEXT("Mi")));

	APianoGameMode* GameMode =
		Cast<APianoGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	if (GameMode)
	{
		ImageBackground->SetBrushFromTexture(GameMode->Backgrounds[(int32)EPianoButtonType::GunBanMi]);
	}
}

void UPianoUserWidget::ButtonFaClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("ButtonFaClicked"));
	TextInfo->SetText(FText::FromString(TEXT("Fa")));

	APianoGameMode* GameMode =
		Cast<APianoGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	if (GameMode)
	{
		ImageBackground->SetBrushFromTexture(GameMode->Backgrounds[(int32)EPianoButtonType::GunBanFa]);
	}
}

void UPianoUserWidget::ButtonSolClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("ButtonSolClicked"));
	TextInfo->SetText(FText::FromString(TEXT("Sol")));

	APianoGameMode* GameMode =
		Cast<APianoGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	if (GameMode)
	{
		ImageBackground->SetBrushFromTexture(GameMode->Backgrounds[(int32)EPianoButtonType::GunBanSol]);
	}
}

void UPianoUserWidget::ButtonRaClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("ButtonRaClicked"));
	TextInfo->SetText(FText::FromString(TEXT("Ra")));

	APianoGameMode* GameMode =
		Cast<APianoGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	if (GameMode)
	{
		ImageBackground->SetBrushFromTexture(GameMode->Backgrounds[(int32)EPianoButtonType::GunBanRa]);
	}
}

void UPianoUserWidget::ButtonSiClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("ButtonSiClicked"));
	TextInfo->SetText(FText::FromString(TEXT("Si")));

	APianoGameMode* GameMode =
		Cast<APianoGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	if (GameMode)
	{
		ImageBackground->SetBrushFromTexture(GameMode->Backgrounds[(int32)EPianoButtonType::GunBanSi]);
	}
}

void UPianoUserWidget::ButtonDoHighClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("ButtonDoHighClicked"));
	TextInfo->SetText(FText::FromString(TEXT("Do")));

	APianoGameMode* GameMode =
		Cast<APianoGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	if (GameMode)
	{
		ImageBackground->SetBrushFromTexture(GameMode->Backgrounds[(int32)EPianoButtonType::GunBanDoHigh]);
	}
}

