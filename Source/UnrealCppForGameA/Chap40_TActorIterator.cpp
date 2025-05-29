// Fill out your copyright notice in the Description page of Project Settings.


#include "Chap40_TActorIterator.h"

#include "EngineUtils.h"
#include "Engine/StaticMeshActor.h"
#include "Item.h"
#include "RandomPosition.h"


// Sets default values
AChap40_TActorIterator::AChap40_TActorIterator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChap40_TActorIterator::BeginPlay()
{
	Super::BeginPlay();

	for (FObjectIterator lt1; lt1; ++lt1)
	{
		// UE_LOG(LogTemp, Warning, TEXT("lt1 : % s"), *lt1->GetName());
	}

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	for (TObjectIterator<UObject> lt2; lt2; ++lt2)
	{
		// UE_LOG(LogTemp, Warning, TEXT("lt2 : %s"), *lt2->GetName());
	}

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	for (TObjectIterator<USkeletalMeshComponent> It3; It3; ++It3)
	{
		UE_LOG(LogTemp, Warning, TEXT("It3 : %s"), *It3->GetName());
	}

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	for (const auto& It4 : TObjectRange<USkeletalMeshComponent>())
	{
		UE_LOG(LogTemp, Warning, TEXT("It4 : %s"), *It4->GetName());
	}

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	for (FActorIterator It5(GetWorld()); It5; ++It5)
	{
		UE_LOG(LogTemp, Warning, TEXT("It5 : %s"), *It5->GetName());
	}

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	for (const auto& It6 : FActorRange(GetWorld()))
	{
		UE_LOG(LogTemp, Warning, TEXT("It6 : %s"), *It6->GetName());
	}

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	for (TActorIterator<AStaticMeshActor> It7(GetWorld()); It7; ++It7)
	{
		UE_LOG(LogTemp, Warning, TEXT("It7 : %s"), *It7->GetName());
	}

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	for (const auto& It8 : TActorRange<AStaticMeshActor>(GetWorld()))
	{
		UE_LOG(LogTemp, Warning, TEXT("It8 : %s"), *It8->GetName());
	}

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	for (TActorIterator<AItem> It9(GetWorld()); It9; ++It9)
	{
		UE_LOG(LogTemp, Warning, TEXT("It9 : %s"), *It9->GetName());
	}

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	for (const auto& It10 : TActorRange<ARandomPosition>(GetWorld()))
	{
		UE_LOG(LogTemp, Warning, TEXT("It10 : %s"), *It10->GetName());
	}

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

}

// Called every frame
void AChap40_TActorIterator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

