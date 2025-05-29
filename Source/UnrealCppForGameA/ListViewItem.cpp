// Fill out your copyright notice in the Description page of Project Settings.


#include "ListViewItem.h"

#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "ListViewObject.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "ListViewGameMode.h"


void UListViewItem::NativeConstruct()
{
	Super::NativeConstruct();

	TextName = Cast<UTextBlock>(GetWidgetFromName(TEXT("TextName")));

	if (!TextName)
	{
		UE_LOG(LogTemp, Error, TEXT("TextName를 찾을 수 없습니다. !!"));
	}

	if (ButtonPlay)
	{
		ButtonPlay->OnClicked.AddDynamic(this, &UListViewItem::ButtonPlayClicked);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ButtonPlay 버튼이 적용되어 있지 없습니다. !!"));
	}
}


void UListViewItem::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	UListViewObject* ListViewObject = Cast<UListViewObject>(ListItemObject);
	FXName = ListViewObject->GetFXPath();

	if (TextName != nullptr)
	{
		TextName->SetText(FText::FromString(ListViewObject->GetItemName()));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("TextName를 찾을 수 없습니다. !!"));
	}

	if (ListViewObject->GetItemImage())
	{
		UE_LOG(LogTemp, Warning, TEXT("ItemImage : %s"), *ListViewObject->GetItemImage()->GetName());
		ImageItem->SetBrushFromTexture(ListViewObject->GetItemImage());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ItemImage를 찾을 수 없습니다. !!"));
	}
}

void UListViewItem::NativeOnItemSelectionChanged(bool bIsSelected)
{
}

void UListViewItem::ButtonPlayClicked()
{
	AListViewGameMode* GameMode = Cast<AListViewGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
	{
		if (GameMode->CurrentFX)
		{
			GameMode->CurrentFX->Deactivate();
			GameMode->CurrentFX->ResetParticles(true);
		}

		FString FXPath = FXName;
		UE_LOG(LogTemp, Warning, TEXT("FXPath : %s"), *FXPath);

		UParticleSystem* FXAsset = LoadObject<UParticleSystem>(NULL, *FXPath, NULL, LOAD_None, NULL);

		if (FXAsset)
		{
			GameMode->CurrentFX =
				UGameplayStatics::SpawnEmitterAtLocation(this, FXAsset, FVector(0.0f, 80.0f, 0.0f), FRotator(0.0f, 0.0f, 0.0f));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("FXAsset 이펙트를 찾을 수가 없습니다. "));
		}
	}
}
