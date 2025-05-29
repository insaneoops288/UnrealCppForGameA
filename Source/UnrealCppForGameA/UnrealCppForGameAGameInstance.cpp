// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealCppForGameAGameInstance.h"


UUnrealCppForGameAGameInstance::UUnrealCppForGameAGameInstance()
{
	static ConstructorHelpers::FObjectFinder<UDataTable>
		BaseGameInfo(TEXT("DataTable'/Game/Tables/BaseGameInfoCSV.BaseGameInfoCSV'"));

	if (BaseGameInfo.Succeeded())
	{
		BaseGameInfoTable = BaseGameInfo.Object;
		UE_LOG(LogTemp, Warning, TEXT("BaseGameInfoTable : %s"), *BaseGameInfoTable->GetName());
		UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

		if (BaseGameInfoTable != nullptr)
		{
			TArray<FName> RowNames;
			RowNames = BaseGameInfoTable->GetRowNames();

			for (auto& name : RowNames)
			{
				UE_LOG(LogTemp, Warning, TEXT("Key : %s"), *name.ToString());
			}
			UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

			for (auto& name : RowNames)
			{
				FBaseGameInfoTableRow* row =
					BaseGameInfoTable->FindRow<FBaseGameInfoTableRow>(name, FString(""));

				if (row)
				{
					UE_LOG(LogTemp, Warning, TEXT("%s, %d, %f"), *name.ToString(), row->IntValue, row->FloatValue);
				}
			}
			UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));
			
			FName SearchKey = FName("PlayerBaseHealth");
			FBaseGameInfoTableRow* Info =
				BaseGameInfoTable->FindRow<FBaseGameInfoTableRow>(SearchKey, FString(""));

			if (Info)
			{
				UE_LOG(LogTemp, Warning, TEXT("IntValue : %d, FloatValue : %f"), Info->IntValue, Info->FloatValue);
				UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

				int32 IntValue = BaseGameInfoTable->FindRow<FBaseGameInfoTableRow>(SearchKey, FString(""))->IntValue;
				UE_LOG(LogTemp, Warning, TEXT("IntValue : %d"), IntValue);
				float FloatValue = BaseGameInfoTable->FindRow<FBaseGameInfoTableRow>(SearchKey, FString(""))->FloatValue;
				UE_LOG(LogTemp, Warning, TEXT("FloatValue : %f"), FloatValue);
				UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));
			}

			Info = GetBaseGameInfoTable(FName("CreatureBaseHealth"));
			UE_LOG(LogTemp, Warning, TEXT("IntValue : %d, FloatValue : %f"), Info->IntValue, Info->FloatValue);
			UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

			FString CreatureBaseHealthkey = GetEnumDisplayNameToString(EBaseGameInfoState::CreatureBaseHealth);
			FString BossBaseHealthKey = GetEnumDisplayNameToString(EBaseGameInfoState::BossBaseHealth);

			UE_LOG(LogTemp, Warning, TEXT("Creaturekey : %s"), *CreatureBaseHealthkey);
			UE_LOG(LogTemp, Warning, TEXT("BossKey : %s"), *BossBaseHealthKey);
			UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

			Info = GetBaseGameInfoTable(FName(*CreatureBaseHealthkey));
			UE_LOG(LogTemp, Warning, TEXT("IntValue : %d, FloatValue : %f"), Info->IntValue, Info->FloatValue);
			UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

			Info = GetBaseGameInfoTable(FName(*BossBaseHealthKey));
			UE_LOG(LogTemp, Warning, TEXT("IntValue : %d, FloatValue : %f"), Info->IntValue, Info->FloatValue);
			UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));
		}
	}
}

FBaseGameInfoTableRow* UUnrealCppForGameAGameInstance::GetBaseGameInfoTable(FName Name)
{
	return BaseGameInfoTable->FindRow<FBaseGameInfoTableRow>(FName(Name), FString(""));
}

FString UUnrealCppForGameAGameInstance::GetEnumDisplayNameToString(EBaseGameInfoState EnumValue) const
{
	const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EBaseGameInfoState"), true);

	if (EnumPtr == nullptr)
	{
		return FString(TEXT("열거형을 찾지 못했습니다. "));
	}
	return EnumPtr->GetDisplayNameTextByIndex(static_cast<int32>(EnumValue)).ToString();
}


