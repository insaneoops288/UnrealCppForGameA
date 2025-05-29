// Fill out your copyright notice in the Description page of Project Settings.


#include "PianoUserWidgetA.h"

#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "PianoGameMode.h"
#include "Kismet/GameplayStatics.h"


void UPianoUserWidgetA::NativeConstruct()
{
	Super::NativeConstruct();

	ButtonDo = Cast<UButton>(GetWidgetFromName(TEXT("ButtonDo")));
	ButtonRe = Cast<UButton>(GetWidgetFromName(TEXT("ButtonRe")));
	ButtonMi = Cast<UButton>(GetWidgetFromName(TEXT("ButtonMi")));
	ButtonFa = Cast<UButton>(GetWidgetFromName(TEXT("ButtonFa")));
	ButtonSol = Cast<UButton>(GetWidgetFromName(TEXT("ButtonSol")));
	ButtonRa = Cast<UButton>(GetWidgetFromName(TEXT("ButtonRa")));
	ButtonSi = Cast<UButton>(GetWidgetFromName(TEXT("ButtonSi")));
	ButtonDoHigh = Cast<UButton>(GetWidgetFromName(TEXT("ButtonDoHigh")));

	ImageBackground = Cast<UImage>(GetWidgetFromName(TEXT("ImageBackground")));
	TextInfo = Cast<UTextBlock>(GetWidgetFromName(TEXT("TextInfo")));

	if (ButtonDo) ButtonDo->OnClicked.AddDynamic(this, &UPianoUserWidgetA::ButtonDoClicked);
	if (ButtonRe) ButtonRe->OnClicked.AddDynamic(this, &UPianoUserWidgetA::ButtonReClicked);
	if (ButtonMi) ButtonMi->OnClicked.AddDynamic(this, &UPianoUserWidgetA::ButtonMiClicked);
	if (ButtonFa) ButtonFa->OnClicked.AddDynamic(this, &UPianoUserWidgetA::ButtonFaClicked);
	if (ButtonSol) ButtonSol->OnClicked.AddDynamic(this, &UPianoUserWidgetA::ButtonSolClicked);
	if (ButtonRa) ButtonRa->OnClicked.AddDynamic(this, &UPianoUserWidgetA::ButtonRaClicked);
	if (ButtonSi) ButtonSi->OnClicked.AddDynamic(this, &UPianoUserWidgetA::ButtonSiClicked);
	if (ButtonDoHigh) ButtonDoHigh->OnClicked.AddDynamic(this, &UPianoUserWidgetA::ButtonDoHighClicked);
}



void UPianoUserWidgetA::ButtonDoClicked()
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

void UPianoUserWidgetA::ButtonReClicked()
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

void UPianoUserWidgetA::ButtonMiClicked()
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

void UPianoUserWidgetA::ButtonFaClicked()
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

void UPianoUserWidgetA::ButtonSolClicked()
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

void UPianoUserWidgetA::ButtonRaClicked()
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

void UPianoUserWidgetA::ButtonSiClicked()
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

void UPianoUserWidgetA::ButtonDoHighClicked()
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

