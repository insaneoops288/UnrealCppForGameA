// Fill out your copyright notice in the Description page of Project Settings.


#include "EffectSoundPreviewUserWidget.h"

#include "Components/EditableTextBox.h"

void UEffectSoundPreviewUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	EditableTextBoxPreivew = 
		Cast<UEditableTextBox>(GetWidgetFromName(TEXT("EditableTextBoxPreivew")));
}
