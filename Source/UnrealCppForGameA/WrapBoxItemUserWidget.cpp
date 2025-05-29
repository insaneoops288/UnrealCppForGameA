// Fill out your copyright notice in the Description page of Project Settings.


#include "WrapBoxItemUserWidget.h"

#include "Components/WrapBox.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "WrapBoxGameMode.h"
#include "Kismet/GameplayStatics.h"

void UWrapBoxItemUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ButtonRemove)
	{
		ButtonRemove->OnClicked.AddDynamic(this, &UWrapBoxItemUserWidget::ButtonRemoveClicked);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ButtonRemove 버튼이 적용되어 있지 없습니다. !!"));
	}
}

void UWrapBoxItemUserWidget::ButtonRemoveClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("ButtonRemoveClicked()"));
	AWrapBoxGameMode* GameMode = Cast<AWrapBoxGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
	{
		int32 RemoveIndex = GameMode->WrapBoxItems.IndexOfByKey(this);
		UE_LOG(LogTemp, Warning, TEXT("RemoveIndex : %d"), RemoveIndex);
		GameMode->WrapBoxItems.Remove(this);
		UE_LOG(LogTemp, Warning, TEXT("WrapBoxItems.Num() : %d"), GameMode->WrapBoxItems.Num());
		ConditionalBeginDestroy();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("게임모드를 찾을 수가 없습니다. !!"));
	}
}

void UWrapBoxItemUserWidget::SetItemName(const FString& Name)
{
	TextItemName->SetText(FText::FromString(Name));
}

void UWrapBoxItemUserWidget::SetItemImage(const FString& Name)
{
	FString Texture2DPath = Name;
	UTexture2D* Texture2DAsset = LoadObject<UTexture2D>(NULL, *Texture2DPath, NULL, LOAD_None, NULL);
	if (Texture2DAsset)
	{
		UE_LOG(LogTemp, Warning, TEXT("Texture2DAsset : %s"), *Texture2DAsset->GetName());
		ImageBackground->SetBrushFromTexture(Texture2DAsset);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Texture2DAsset을 찾을 수가 없습니다. !!"));
	}
}