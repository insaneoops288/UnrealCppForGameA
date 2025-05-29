// Fill out your copyright notice in the Description page of Project Settings.


#include "Chap31_TSharedPtr.h"

// Sets default values
AChap31_TSharedPtr::AChap31_TSharedPtr()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChap31_TSharedPtr::BeginPlay()
{
	Super::BeginPlay();

	TSharedPtr<FDog> SharedPtr1(new FDog());

	TSharedPtr<FDog> SharedPtr2(SharedPtr1);

	TSharedPtr<FDog> SharedPtr3 = SharedPtr1;

	UE_LOG(LogTemp, Warning, TEXT("SharedPtr1 : %#x"), SharedPtr1.Get());
	UE_LOG(LogTemp, Warning, TEXT("SharedPtr1 %d"), SharedPtr1.GetSharedReferenceCount());

	UE_LOG(LogTemp, Warning, TEXT("SharedPtr2 : %#x"), SharedPtr2.Get());
	UE_LOG(LogTemp, Warning, TEXT("SharedPtr2 %d"), SharedPtr2.GetSharedReferenceCount());

	UE_LOG(LogTemp, Warning, TEXT("SharedPtr3 : %#x"), SharedPtr3.Get());
	UE_LOG(LogTemp, Warning, TEXT("SharedPtr3 %d"), SharedPtr3.GetSharedReferenceCount());

	UE_LOG(LogTemp, Warning, TEXT("<--------------------------------->"));

	TArray<TSharedPtr<FAnt>> Array1;

	Array1.Add(TSharedPtr<FAnt>(new FAnt()));
	Array1.Add(TSharedPtr<FAnt>(new FAnt()));
	Array1.Add(TSharedPtr<FAnt>(new FAnt()));

	UE_LOG(LogTemp, Warning, TEXT("%#x"), &Array1[0]);
	UE_LOG(LogTemp, Warning, TEXT("Array1[0] Reference Count : %d"), Array1[0].GetSharedReferenceCount());

	UE_LOG(LogTemp, Warning, TEXT("%#x"), &Array1[1]);
	UE_LOG(LogTemp, Warning, TEXT("Array1[0] Reference Count : %d"), Array1[0].GetSharedReferenceCount());

	UE_LOG(LogTemp, Warning, TEXT("%#x"), &Array1[2]);
	UE_LOG(LogTemp, Warning, TEXT("Array1[0] Reference Count : %d"), Array1[0].GetSharedReferenceCount());

	UE_LOG(LogTemp, Warning, TEXT("<--------------------------------->"));

	TArray<TSharedPtr<FBee>> Array2;

	Array2.Add(TSharedPtr<FBee>(new FBee()));
	UE_LOG(LogTemp, Warning, TEXT("Array2[0] Reference Count : %d"), Array2[0].GetSharedReferenceCount());
	Array2.Add(TSharedPtr<FBee>(Array2[0]));
	UE_LOG(LogTemp, Warning, TEXT("Array2[0] Reference Count : %d"), Array2[0].GetSharedReferenceCount());
	Array2.Add(TSharedPtr<FBee>(Array2[1]));
	UE_LOG(LogTemp, Warning, TEXT("Array2[0] Reference Count : %d"), Array2[0].GetSharedReferenceCount());

	UE_LOG(LogTemp, Warning, TEXT("<--------------------------------->"));

	UE_LOG(LogTemp, Warning, TEXT("Array2[0] Reference Count : %d"), Array2[0].GetSharedReferenceCount());
	Array2.RemoveAt(0);
	UE_LOG(LogTemp, Warning, TEXT("Array2[0] Reference Count : %d"), Array2[0].GetSharedReferenceCount());
	Array2.RemoveAt(0);
	UE_LOG(LogTemp, Warning, TEXT("Array2[0] Reference Count : %d"), Array2[0].GetSharedReferenceCount());

	Array2.RemoveAt(0);
	// UE_LOG(LogTemp, Warning, TEXT("Array2[0] Reference Count : %d"), Array2[0].GetSharedReferenceCount());

	UE_LOG(LogTemp, Warning, TEXT("<--------------------------------->"));

	TSharedPtr<FBee> SharedPtr4(new FBee());
	UE_LOG(LogTemp, Warning, TEXT("SharedPtr4 Count : %d"), SharedPtr4.GetSharedReferenceCount());

	TSharedPtr<FBee> SharedPtr5(SharedPtr4);

	UE_LOG(LogTemp, Warning, TEXT("SharedPtr4 Count : %d, SharedPtr5 Count : %d"), SharedPtr4.GetSharedReferenceCount(), SharedPtr5.GetSharedReferenceCount());

	UE_LOG(LogTemp, Warning, TEXT("<--------------------------------->"));

	FBee* Bee1 = new FBee();

	TSharedPtr<FBee> SharedPtr6 = MakeShareable(Bee1);
	UE_LOG(LogTemp, Warning, TEXT("SharedPtr6 Count : %d"), SharedPtr6.GetSharedReferenceCount());

	TSharedPtr<FBee> SharedPtr7 = MakeShared<FBee>();
	UE_LOG(LogTemp, Warning, TEXT("SharedPtr7 Count : %d"), SharedPtr7.GetSharedReferenceCount());

	UE_LOG(LogTemp, Warning, TEXT("<--------------------------------->"));

	TSharedPtr<FHornet> SharedPtr8(new FHornet());
	TSharedPtr<FHornet> SharedPtr9(new FHornet());

	SharedPtr8->Show(SharedPtr9);
	SharedPtr9->Show(SharedPtr8);

	UE_LOG(LogTemp, Warning, TEXT("<--------------------------------->"));




}

// Called every frame
void AChap31_TSharedPtr::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

