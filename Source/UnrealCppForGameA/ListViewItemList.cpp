// Fill out your copyright notice in the Description page of Project Settings.


#include "ListViewItemList.h"

#include "Components/ListView.h"
#include "ListViewItem.h"
#include "ListViewObject.h"
#include "ListViewGameMode.h"
#include "Engine/DataTable.h" 
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"


void UListViewItemList::NativeConstruct()
{
	Super::NativeConstruct();

	ListViewItemList = Cast<UListView>(GetWidgetFromName(TEXT("ListViewItemList")));

	if (ListViewItemList)
	{               
		TArray<UListViewObject*> ListViewObjects;

		// DataTable'/Game/StudyListView/Tables/EffectPreViewCSV.EffectPreViewCSV'
		FString DataTablePath = TEXT("DataTable'/Game/StudyListView/Tables/EffectPreViewCSV.EffectPreViewCSV'");
		UDataTable* DataTableAsset = LoadObject<UDataTable>(NULL, *DataTablePath, NULL, LOAD_None, NULL);

		if (DataTableAsset)
		{
			UE_LOG(LogTemp, Warning, TEXT("DataTableAsset : %s"), *DataTableAsset->GetName());

			TArray<FName> RowNames;
			RowNames = DataTableAsset->GetRowNames();

			UE_LOG(LogTemp, Warning, TEXT("RowNames.Num() : %d"), RowNames.Num());

			for (auto& name : RowNames)
			{
				FListViewTableRow* row = DataTableAsset->FindRow<FListViewTableRow>(name, FString(""));

				if (row)
				{
					UListViewObject* ListViewObject = NewObject<UListViewObject>(this, UListViewObject::StaticClass());
					ListViewObject->SetItemName(*row->FXName);
					ListViewObject->SetItemImage(*row->FXImagePath);
					ListViewObject->SetFXPath(*row->FXPath);
					ListViewObjects.AddUnique(ListViewObject);
				}
				{
					UE_LOG(LogTemp, Error, TEXT("row를 찾을 수가 없습니다. !!"));
				}
			}

			ListViewItemList->SetListItems(ListViewObjects);
			int32 Count = ListViewItemList->GetListItems().Num();

			UE_LOG(LogTemp, Warning, TEXT("Count : %d"), Count);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("DataTableAsset을 찾을 수 없습니다. !!"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ListViewItemList을 찾을 수 없습니다. !!"));
	}
}

