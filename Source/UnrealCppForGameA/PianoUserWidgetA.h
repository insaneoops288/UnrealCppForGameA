// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PianoUserWidgetA.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCPPFORGAMEA_API UPianoUserWidgetA : public UUserWidget
{
	GENERATED_BODY()

public:
	void NativeConstruct() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UButton* ButtonDo = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UButton* ButtonRe = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UButton* ButtonMi = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UButton* ButtonFa = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UButton* ButtonSol = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UButton* ButtonRa = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UButton* ButtonSi = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UButton* ButtonDoHigh = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UImage* ImageBackground = nullptr;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
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
