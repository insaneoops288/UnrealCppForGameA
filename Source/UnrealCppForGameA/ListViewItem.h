// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Blueprint/IUserObjectListEntry.h"

#include "ListViewItem.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCPPFORGAMEA_API UListViewItem : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UFUNCTION()
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	UFUNCTION()
	virtual void NativeOnItemSelectionChanged(bool bIsSelected) override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* TextIndex;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* TextName;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UImage* ImageItem;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* ButtonPlay;
	FString FXName;
	UFUNCTION()
	void ButtonPlayClicked();	
};
