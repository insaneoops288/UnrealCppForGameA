// Fill out your copyright notice in the Description page of Project Settings.


#include "Chap48_FString.h"

#include "Internationalization/Text.h"
#include "Kismet/GameplayStatics.h"
#include "UnrealCppForGameACharacter.h"
#include <iostream>
#include <string>

// Sets default values
AChap48_FString::AChap48_FString()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChap48_FString::BeginPlay()
{
	Super::BeginPlay();

	FString StringValue1 = FString(TEXT("This is FString. !!"));
	FName NameValue1 = FName(TEXT("This is FName. !!"));
#define LOCTEXT_NAMESPACE "JobType"
	FText TextValue1 = NSLOCTEXT("JobType", "MyJob", "Fighter");

	FString StringValue2 = NameValue1.ToString();
	UE_LOG(LogTemp, Warning, TEXT("StringValue2 : %s"), *StringValue2);

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	FText TextValue2 = FText::FromName(NameValue1);
	UE_LOG(LogTemp, Warning, TEXT("TextValue2 : %s"), *TextValue2.ToString());

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	FName NameValue2 = FName(*StringValue1);
	UE_LOG(LogTemp, Warning, TEXT("NameValue2 : %s"), *NameValue2.ToString());

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	FText TextValue3 = FText::FromString(StringValue1);
	UE_LOG(LogTemp, Warning, TEXT("TextValue3 : %s"), *TextValue3.ToString());

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	FString StringValue3 = TextValue1.ToString();
	UE_LOG(LogTemp, Warning, TEXT("StringValue3 : %s"), *StringValue3);

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	FString StringValue4 = TextValue1.ToString();
	FName NameValue4 = FName(*StringValue4);
	UE_LOG(LogTemp, Warning, TEXT("NameValue4 : %s"), *NameValue4.ToString());

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	float FloatValue5 = 3.14159265f;
	FString StringValue5 = FString::SanitizeFloat(FloatValue5);
	UE_LOG(LogTemp, Warning, TEXT("StringValue5 : %s"), *StringValue5);

	FString StringValue6 = FString::Printf(TEXT("%f"), FloatValue5);
	UE_LOG(LogTemp, Warning, TEXT("StringValue6 : %s"), *StringValue6);

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	int32 IntValue7 = 12345;
	FString StringValue7 = FString::FromInt(IntValue7);
	UE_LOG(LogTemp, Warning, TEXT("StringValue7 : %s"), *StringValue7);

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	bool BoolValue8 = true;
	FString StringValue8 = BoolValue8 ? TEXT("true") : TEXT("false");
	UE_LOG(LogTemp, Warning, TEXT("StringValue8 : %s"), *StringValue8);

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	FVector VectorValue9 = FVector(1.0f, 2.0f, 3.0f);
	FString StringValue9 = VectorValue9.ToString();
	UE_LOG(LogTemp, Warning, TEXT("StringValue9 : %s"), *StringValue9);

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	FVector2D Vector2DValue10 = FVector2D(1.0f, 2.0f);
	FString StringValue10 = Vector2DValue10.ToString();
	UE_LOG(LogTemp, Warning, TEXT("StringValue10 : %s"), *StringValue10);

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	FRotator RotatorValue11 = FRotator(1.0f, 2.0f, 3.0f);
	FString StringValue11 = RotatorValue11.ToString();
	UE_LOG(LogTemp, Warning, TEXT("StringValue11 : %s"), *StringValue11);

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	FLinearColor LinearColorValue12 = FLinearColor(1.f, 1.f, 1.f, 1.f);
	FString StringValue12 = LinearColorValue12.ToString();
	UE_LOG(LogTemp, Warning, TEXT("StringValue12 : %s"), *StringValue12);

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	UObject* ObjectValue13 = nullptr;
	FString StringValue13 = (ObjectValue13 != nullptr) ? ObjectValue13->GetName() : FString(TEXT("None"));
	UE_LOG(LogTemp, Warning, TEXT("StringValue13 : %s"), *StringValue13);

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	AUnrealCppForGameACharacter* Player = Cast<AUnrealCppForGameACharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	StringValue13 = (Player != nullptr) ? Player->GetName() : FString(TEXT("None"));
	UE_LOG(LogTemp, Warning, TEXT("StringValue13 : %s"), *StringValue13);

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	FString StringValue14 = TEXT("3.14159265");
	float FloatValue14 = FCString::Atof(*StringValue14);
	UE_LOG(LogTemp, Warning, TEXT("FloatValue14 : %f"), FloatValue14);

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	FString StringValue15 = TEXT("1024");
	int32 IntValue15 = FCString::Atoi(*StringValue15);
	UE_LOG(LogTemp, Warning, TEXT("IntValue15 : %d"), IntValue15);

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	std::string StringValue16 = "We study Unreal C++";
	FString StringValue17(StringValue16.c_str());
	UE_LOG(LogTemp, Warning, TEXT("StringValue17 : %s"), *StringValue17);

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	FString StringValue18 = TEXT("We study Unreal. !!");
	std::string StringValue19(TCHAR_TO_UTF8(*StringValue18));
	UE_LOG(LogTemp, Warning, TEXT("StringValue19 : %s"), *FString(StringValue19.c_str()));

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	EItemStatus ItemStatus19 = EItemStatus::DailyItem;
	UEnum* EnumValue19 = FindObject<UEnum>(ANY_PACKAGE, TEXT("EItemStatus"), true);
	FName NameValue19 = EnumValue19->GetNameByValue(static_cast<int64>(ItemStatus19));
	UE_LOG(LogTemp, Warning, TEXT("NameValue19 : %s"), *NameValue19.ToString());

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	EItemStatus ItemStatus20 = EItemStatus::WeeklyItem;
	UEnum* EnumValue20 = FindObject<UEnum>(ANY_PACKAGE, TEXT("EItemStatus"), true);
	FString StringValue20 = EnumValue20->GetNameStringByValue(static_cast<int64>(ItemStatus20));
	UE_LOG(LogTemp, Warning, TEXT("StringValue20 : %s"), *StringValue20);

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));
	
}

// Called every frame
void AChap48_FString::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

