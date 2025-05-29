// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PianoUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCPPFORGAMEA_API UPianoUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void NativeConstruct() override;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* ButtonDo = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* ButtonRe = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* ButtonMi = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* ButtonFa = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* ButtonSol = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* ButtonRa = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* ButtonSi = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UButton* ButtonDoHigh = nullptr;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UImage* ImageBackground = nullptr;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* TextInfo = nullptr;

	UFUNCTION()
	void ButtonDoClicked();
	UFUNCTION()
	void ButtonReClicked();
	UFUNCTION()
	void ButtonMiClicked();
	UFUNCTION()
	void ButtonFaClicked();
	UFUNCTION()
	void ButtonSolClicked();
	UFUNCTION()
	void ButtonRaClicked();
	UFUNCTION()
	void ButtonSiClicked();
	UFUNCTION()
	void ButtonDoHighClicked();
	
};
