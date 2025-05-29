// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Components/TextBlock.h"
#include "Components/Image.h"

#include "WrapBoxItemUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCPPFORGAMEA_API UWrapBoxItemUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UImage* ImageBackground;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* TextItemName;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* ButtonRemove;

	UFUNCTION()
	void ButtonRemoveClicked();

	void SetItemName(const FString& Name);

	void SetItemImage(const FString& Name);
	
};
