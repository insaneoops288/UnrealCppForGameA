// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ListViewItemList.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCPPFORGAMEA_API UListViewItemList : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UListView* ListViewItemList;
};
