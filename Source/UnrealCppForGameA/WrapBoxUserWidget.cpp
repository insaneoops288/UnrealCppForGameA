// Fill out your copyright notice in the Description page of Project Settings.


#include "WrapBoxUserWidget.h"

#include "Components/Button.h"
#include "WrapBoxGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "WrapBoxItemUserWidget.h"
#include "Components/WrapBox.h"

void UWrapBoxUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (ButtonAddItem)
	{
		ButtonAddItem->OnClicked.AddDynamic(this, &UWrapBoxUserWidget::ButtonAddItemClicked);
	}
}

void UWrapBoxUserWidget::ButtonAddItemClicked()
{
	AWrapBoxGameMode* GameMode = Cast<AWrapBoxGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (GameMode)
	{
		GameMode->WrapBox = Cast<UWrapBox>(GameMode->WrapBoxWidget->GetWidgetFromName(TEXT("WrapBox")));
		if (GameMode->WrapBox)
		{
			// DataTable'/Game/StudyWrapBox/Tables/ItemCSV.ItemCSV'
			FString DataTablePath = TEXT("DataTable'/Game/StudyWrapBox/Tables/ItemCSV.ItemCSV'");
			UDataTable* DataTableAsset = LoadObject<UDataTable>(NULL, *DataTablePath, NULL, LOAD_None, NULL);
			if (DataTableAsset)
			{
				UE_LOG(LogTemp, Warning, TEXT("DataTableAsset : %s"), *DataTableAsset->GetName());

				TArray<FName> RowNames;
				RowNames = DataTableAsset->GetRowNames();
				UE_LOG(LogTemp, Warning, TEXT("RowNames.Num() : %d"), RowNames.Num());
				int32 RandomKeyIndex = FMath::RandRange(0, RowNames.Num() - 1);

				FItemTable* row = DataTableAsset->FindRow<FItemTable>(RowNames[RandomKeyIndex], FString(""));

				if (row)
				{
					UWrapBoxItemUserWidget* Item = CreateWidget<UWrapBoxItemUserWidget>(GetWorld(), GameMode->WBP_WrapBoxItem);
					Item->SetItemImage(row->Image);
					Item->SetItemName(row->ItemName);
					GameMode->WrapBox->AddChildToWrapBox(Item);
					GameMode->WrapBoxItems.Add(Item);

					UE_LOG(LogTemp, Warning, TEXT("WrapBoxItems.Num() : %d"), GameMode->WrapBoxItems.Num());
				}
				else
				{
					UE_LOG(LogTemp, Error, TEXT("row를 찾을 수가 없습니다. !!"));
				}
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("DataTableAsset을 찾을 수가 없습니다. !!"));
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("WrapBox UI를 찾을 수가 없습니다. !!"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("게임모드를 찾을 수가 없습니다. !!"));
	}
}

