// Fill out your copyright notice in the Description page of Project Settings.


#include "ListViewGameMode.h"

#include "Blueprint/UserWidget.h"

void AListViewGameMode::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
	GetWorld()->GetFirstPlayerController()->bEnableClickEvents = true;
	GetWorld()->GetFirstPlayerController()->bEnableMouseOverEvents = true;
 
	if (WBP_ListViewItemList)
	{
		ListViewItemList = CreateWidget<UUserWidget>(GetWorld(), WBP_ListViewItemList);

		if (ListViewItemList)
		{
			ListViewItemList->AddToViewport();
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("ListViewItemList를 생성할 수 없습니다. !!"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("WBP_ListViewItemList가 디테일 패널에 적용되어 있지 않습니다. !!"));
	}
}
