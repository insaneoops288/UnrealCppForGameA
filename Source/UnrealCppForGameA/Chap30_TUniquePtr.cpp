// Fill out your copyright notice in the Description page of Project Settings.


#include "Chap30_TUniquePtr.h"

// Sets default values
AChap30_TUniquePtr::AChap30_TUniquePtr()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChap30_TUniquePtr::BeginPlay()
{
	Super::BeginPlay();

	FAnimal Animal1;

	UE_LOG(LogTemp, Warning, TEXT("<--------------------------------->"));

	FLion* Lion1 = new FLion();

	UE_LOG(LogTemp, Warning, TEXT("<--------------------------------->"));

	delete Lion1;

	UE_LOG(LogTemp, Warning, TEXT("<--------------------------------->"));

	TUniquePtr<FTiger> UniquePtr0 = MakeUnique<FTiger>();

	UE_LOG(LogTemp, Warning, TEXT("<--------------------------------->"));

	FCat* Cat1 = new FCat();

	UE_LOG(LogTemp, Warning, TEXT("<--------------------------------->"));

	delete Cat1;

	UE_LOG(LogTemp, Warning, TEXT("<--------------------------------->"));

	FCat* Cat2 = new FCat();

	UE_LOG(LogTemp, Warning, TEXT("<--------------------------------->"));

	FCat* Cat3 = Cat2;

	UE_LOG(LogTemp, Warning, TEXT("<--------------------------------->"));

	delete Cat2;

	UE_LOG(LogTemp, Warning, TEXT("<--------------------------------->"));

	TUniquePtr<FCat> UniquePtr1(new FCat());

	UE_LOG(LogTemp, Warning, TEXT("<--------------------------------->"));

	TUniquePtr<FCat> UniquePtr2(new FCat());

	// TUniquePtr<FCat> UniquePtr3 = UniquePtr2; // (X)

	UE_LOG(LogTemp, Warning, TEXT("<--------------------------------->"));

	UE_LOG(LogTemp, Warning, TEXT("이전 UniquePtr2 : %#x"), UniquePtr2.Get());

	TUniquePtr<FCat> UniquePtr3 = MoveTemp(UniquePtr2);

	UE_LOG(LogTemp, Warning, TEXT("이후 UniquePtr2 : %#x"), UniquePtr2.Get());
	UE_LOG(LogTemp, Warning, TEXT("이후 UniquePtr3 : %#x"), UniquePtr3.Get());

	UE_LOG(LogTemp, Warning, TEXT("<--------------------------------->"));

	TUniquePtr<FCat> UniquePtr4 = MakeUnique<FCat>();

	UE_LOG(LogTemp, Warning, TEXT("<--------------------------------->"));

	TArray<TUniquePtr<FCat>> Array5;
	TUniquePtr<FCat> UniquePtr5(new FCat());

	// Array5.Add(UniquePtr5); // (X)

	Array5.Add(MoveTemp(UniquePtr5));

	for (int32 i = 0; i < Array5.Num(); i++)
	{
		UE_LOG(LogTemp, Warning, TEXT("Array5[%d] : %#x"), i, Array5[i].Get());
	}

	UE_LOG(LogTemp, Warning, TEXT("<--------------------------------->"));

	TArray<TUniquePtr<FCat>> Array6;
	Array6.Add(TUniquePtr<FCat>(new FCat()));

	Array6.Emplace(new FCat());

	for (auto& Cat : Array6)
	{
		Cat->SetName(TEXT("고양이"));
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Cat->GetName());
	}

	UE_LOG(LogTemp, Warning, TEXT("<--------------------------------->"));


}

// Called every frame
void AChap30_TUniquePtr::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

