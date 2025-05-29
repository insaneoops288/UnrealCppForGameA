// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WrapBoxUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCPPFORGAMEA_API UWrapBoxUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UWrapBox* WrapBox = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* ButtonAddItem = nullptr;

	UFUNCTION()
	void ButtonAddItemClicked();
	
};
