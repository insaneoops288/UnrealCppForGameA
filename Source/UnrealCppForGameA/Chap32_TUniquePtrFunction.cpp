// Fill out your copyright notice in the Description page of Project Settings.


#include "Chap32_TUniquePtrFunction.h"

// Sets default values
AChap32_TUniquePtrFunction::AChap32_TUniquePtrFunction()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChap32_TUniquePtrFunction::BeginPlay()
{
	Super::BeginPlay();

	TUniquePtr<int32> UniquePtr1(new int32(3));
	UE_LOG(LogTemp, Warning, TEXT("UniquePtr1 : %d, UniquePtr1 address : %#x"), *UniquePtr1, UniquePtr1.Get());

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	TUniquePtr<int32> UniquePtr2 = TUniquePtr<int32>(new int32(10));
	UE_LOG(LogTemp, Warning, TEXT("UniquePtr2 : %d, UniquePtr2 address : %#x"), *UniquePtr2, UniquePtr2.Get());

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));


	TUniquePtr<int32> UniquePtr3 = TUniquePtr<int32>(new int32(3));
	// TUniquePtr<int32> UniquePtr4 = UniquePtr3; // (X)

	TUniquePtr<int32> UniquePtr5 = TUniquePtr<int32>(new int32(3));
	UE_LOG(LogTemp, Warning, TEXT("이전 UniquePtr5 address : %#x"), UniquePtr5.Get());

	TUniquePtr<int32> UniquePtr6 = MoveTemp(UniquePtr5);

	UE_LOG(LogTemp, Warning, TEXT("이후 UniquePtr5 address : %#x"), UniquePtr5.Get());
	UE_LOG(LogTemp, Warning, TEXT("이후 UniquePtr6 address : %#x"), UniquePtr6.Get());

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	// UE_LOG(LogTemp, Warning, TEXT("UniquePtr5 : %d, UniquePtr5 address : %#x"), *UniquePtr5, UniquePtr5.Get()); //(X)

	TUniquePtr<int> UniquePtr7 = MakeUnique<int32>(10);
	UE_LOG(LogTemp, Warning, TEXT("UniquePtr7 : %d, UniquePtr7 address : %#x"), *UniquePtr7, UniquePtr7.Get());

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	UniquePtr7.Reset(new int32(20));
	UE_LOG(LogTemp, Warning, TEXT("UniquePtr7 : %d, UniquePtr7 address : %#x"), *UniquePtr7, UniquePtr7.Get());

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));


	UniquePtr7.Reset(new int32(30));
	UE_LOG(LogTemp, Warning, TEXT("UniquePtr7 : %d, UniquePtr7 address : %#x"), *UniquePtr7, UniquePtr7.Get());

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	TUniquePtr<int32> UniquePtr8;

	int32* IntPtr8 = UniquePtr8.Release();

	// UE_LOG(LogTemp, Warning, TEXT("UniquePtr8 : %d, UniquePtr8 address : %#x"), *UniquePtr8, UniquePtr8.Get());
	// UE_LOG(LogTemp, Warning, TEXT("IntPtr8 : %d, IntPtr8 address : %#x"), *IntPtr8, IntPtr8);

	UniquePtr8.Reset(new int32(30));
	UE_LOG(LogTemp, Warning, TEXT("이전 UniquePtr8 address : %#x"), UniquePtr8.Get());

	IntPtr8 = UniquePtr8.Release();
	// UE_LOG(LogTemp, Warning, TEXT("UniquePtr8 : %d, UniquePtr8 address : %#x"), *UniquePtr8, UniquePtr8.Get());
	UE_LOG(LogTemp, Warning, TEXT("이후 UniquePtr8 address : %#x"), UniquePtr8.Get());
	UE_LOG(LogTemp, Warning, TEXT("이후 IntPtr8 : %d, IntPtr8 address : %#x"), *IntPtr8, IntPtr8);

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	TUniquePtr<int32> UniquePtr9 = MakeUnique<int32>(10);
	UE_LOG(LogTemp, Warning, TEXT("UniquePtr9 : %d, UniquePtr9 address : %#x"), *UniquePtr9, UniquePtr9.Get());

	// TUniquePtr<int32> UniquePtr10 = UniquePtr9; // (X)

	// TUniquePtr<int32> UniquePtr11(UniquePtr10); // (X)

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	TUniquePtr<int32> UniquePtr12 = MakeUnique<int32>(10);
	UE_LOG(LogTemp, Warning, TEXT("이전 UniquePtr12 address : %#x"), UniquePtr12.Get());

	TUniquePtr<int32> UniquePtr13 = MoveTemp(UniquePtr12);

	UE_LOG(LogTemp, Warning, TEXT("이후 UniquePtr12 address : %#x"), UniquePtr12.Get());
	UE_LOG(LogTemp, Warning, TEXT("이후 UniquePtr13 address : %#x"), UniquePtr13.Get());

	// UE_LOG(LogTemp, Warning, TEXT("UniquePtr12 : %d, UniquePtr12 address : %#x"), *UniquePtr12, UniquePtr12.Get()); // (X)

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	TUniquePtr<int32> UniquePtr14(new int32(10));
	UE_LOG(LogTemp, Warning, TEXT("UniquePtr14 : %d, UniquePtr14 address : %#x"), *UniquePtr14, UniquePtr14.Get());

	TUniquePtr<int32> UniquePtr15 = MakeUnique<int32>(10);
	UE_LOG(LogTemp, Warning, TEXT("UniquePtr15 : %d, UniquePtr15 address : %#x"), *UniquePtr15, UniquePtr15.Get());

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	TUniquePtr<int32> UniquePtr16 = MakeUnique<int>(10);
	UE_LOG(LogTemp, Warning, TEXT("이전 UniquePtr16 : %d, UniquePtr16 address : %#x"), *UniquePtr16, UniquePtr16.Get());

	int32* IntPtr16 = UniquePtr16.Get();
	UE_LOG(LogTemp, Warning, TEXT("이후 UniquePtr16 : %d, UniquePtr16 address : %#x"), *UniquePtr16, UniquePtr16.Get());
	UE_LOG(LogTemp, Warning, TEXT("이후 IntPtr16 : %d, IntPtr16 address : %#x"), *IntPtr16, IntPtr16);

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	TUniquePtr<int32> UniquePtr17 = MakeUnique<int32>(10);
	UE_LOG(LogTemp, Warning, TEXT("이전 UniquePtr17 address : %#x"), UniquePtr17.Get());

	int32* IntPtr17 = UniquePtr17.Release();

	// UE_LOG(LogTemp, Warning, TEXT("UniquePtr17 : %d, UniquePtr17 address : %#x"), *UniquePtr17, UniquePtr17.Get()); // (X)
	UE_LOG(LogTemp, Warning, TEXT("이후 UniquePtr17 address : %#x"), UniquePtr17.Get());
	UE_LOG(LogTemp, Warning, TEXT("이후 IntPtr17 address : %#x"), IntPtr17);

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	TUniquePtr<int32> UniquePtr18 = MakeUnique<int32>(10);
	UE_LOG(LogTemp, Warning, TEXT("UniquePtr18 : %d, UniquePtr18 address : %#x"), *UniquePtr18, UniquePtr18.Get());

	UniquePtr18.Reset(new int32(20));
	UE_LOG(LogTemp, Warning, TEXT("UniquePtr18 : %d, UniquePtr18 address : %#x"), *UniquePtr18, UniquePtr18.Get());

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));





}

// Called every frame
void AChap32_TUniquePtrFunction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

