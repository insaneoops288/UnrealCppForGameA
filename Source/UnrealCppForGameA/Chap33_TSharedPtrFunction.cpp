// Fill out your copyright notice in the Description page of Project Settings.


#include "Chap33_TSharedPtrFunction.h"

// Sets default values
AChap33_TSharedPtrFunction::AChap33_TSharedPtrFunction()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChap33_TSharedPtrFunction::BeginPlay()
{
	Super::BeginPlay();

	TSharedPtr<int32> SharedPtr1(new int32(10));

	TSharedPtr<int32> SharedPtr4(new int32(10));
	UE_LOG(LogTemp, Warning, TEXT("SharedPtr4 참조 카운트 : %d"), SharedPtr4.GetSharedReferenceCount());

	TSharedPtr<int32> SharedPtr5;
	SharedPtr5 = SharedPtr4;

	UE_LOG(LogTemp, Warning, TEXT("SharedPtr4 참조 카운트 : %d, SharedPtr5 참조 카운트 : %d"),
		SharedPtr4.GetSharedReferenceCount(), SharedPtr5.GetSharedReferenceCount());

	SharedPtr4 = nullptr;
	UE_LOG(LogTemp, Warning, TEXT("SharedPtr4 참조 카운트 : %d, SharedPtr5 참조 카운트 : %d"),
		SharedPtr4.GetSharedReferenceCount(), SharedPtr5.GetSharedReferenceCount());

	SharedPtr5.Reset();

	UE_LOG(LogTemp, Warning, TEXT("SharedPtr4 참조 카운트 : %d, SharedPtr5 참조 카운트 : %d"),
		SharedPtr4.GetSharedReferenceCount(), SharedPtr5.GetSharedReferenceCount());

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	TSharedPtr<int32> SharedPtr6(new int32());

	UE_LOG(LogTemp, Warning, TEXT("SharedPtr6 참조 카운트 : %d"), SharedPtr6.GetSharedReferenceCount());
	{
		TSharedPtr<int32> SharedPtr7 = SharedPtr6;
		UE_LOG(LogTemp, Warning, TEXT("SharedPtr6 참조 카운트 : %d, SharedPtr7 참조 카운트 : %d"),
			SharedPtr6.GetSharedReferenceCount(), SharedPtr7.GetSharedReferenceCount());
	}

	UE_LOG(LogTemp, Warning, TEXT("SharedPtr6 참조 카운트 : %d"), SharedPtr6.GetSharedReferenceCount());

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	TSharedPtr<int32> SharedPtr8(new int32(10));

	UE_LOG(LogTemp, Warning, TEXT("SharedPtr8 참조 카운트 : %d"), SharedPtr8.GetSharedReferenceCount());

	CountSharedPtrValue(SharedPtr8);

	UE_LOG(LogTemp, Warning, TEXT("SharedPtr8 참조 카운트 : %d"), SharedPtr8.GetSharedReferenceCount());

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	TSharedPtr<int32> SharedPtr9(new int32());

	UE_LOG(LogTemp, Warning, TEXT("SharedPtr9 참조 카운트 : %d"), SharedPtr9.GetSharedReferenceCount());

	CountSharedPtrReference(SharedPtr9);

	UE_LOG(LogTemp, Warning, TEXT("SharedPtr9 참조 카운트 : %d"), SharedPtr9.GetSharedReferenceCount());

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	TSharedPtr<int32> SharedPtr10(new int32());

	UE_LOG(LogTemp, Warning, TEXT("SharedPtr10 참조 카운트 : %d"), SharedPtr10.GetSharedReferenceCount());

	TSharedPtr<int32> SharedPtr11;

	UE_LOG(LogTemp, Warning, TEXT("이전 SharedPtr10 참조 카운트 : %d, SharedPtr11 참조 카운트 : %d"),
		SharedPtr10.GetSharedReferenceCount(), SharedPtr11.GetSharedReferenceCount());
	SharedPtr11 = MoveTemp(SharedPtr10);

	UE_LOG(LogTemp, Warning, TEXT("이후 SharedPtr10 참조 카운트 : %d, SharedPtr11 참조 카운트 : %d"),
		SharedPtr10.GetSharedReferenceCount(), SharedPtr11.GetSharedReferenceCount());

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));
	TSharedPtr<int32> SharedPtr12(new int32());

	UE_LOG(LogTemp, Warning, TEXT("SharedPtr12 참조 카운트 : %d"), SharedPtr12.GetSharedReferenceCount());

	TSharedPtr<int32> SharedPtr13 = SharedPtr12;

	UE_LOG(LogTemp, Warning, TEXT("SharedPtr12 참조 카운트 : %d, SharedPtr13 참조 카운트 : %d"),
		SharedPtr12.GetSharedReferenceCount(), SharedPtr13.GetSharedReferenceCount());

	SharedPtr12.Reset();

	UE_LOG(LogTemp, Warning, TEXT("SharedPtr12 참조 카운트 : %d, SharedPtr13 참조 카운트 : %d"),
		SharedPtr12.GetSharedReferenceCount(), SharedPtr13.GetSharedReferenceCount());

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	TSharedPtr<int32> SharedPtr15(new int32());

	UE_LOG(LogTemp, Warning, TEXT("SharedPtr15 참조 카운트 : %d"), SharedPtr15.GetSharedReferenceCount());

	TSharedPtr<int32> SharedPtr16 = SharedPtr15;

	UE_LOG(LogTemp, Warning, TEXT("SharedPtr15 참조 카운트 : %d, SharedPtr16 참조 카운트 : %d"),
		SharedPtr15.GetSharedReferenceCount(), SharedPtr16.GetSharedReferenceCount());

	SharedPtr15 = nullptr;

	UE_LOG(LogTemp, Warning, TEXT("SharedPtr15 참조 카운트 : %d, SharedPtr16 참조 카운트 : %d"),
		SharedPtr15.GetSharedReferenceCount(), SharedPtr16.GetSharedReferenceCount());

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));




	
}

// Called every frame
void AChap33_TSharedPtrFunction::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChap33_TSharedPtrFunction::CountSharedPtrValue(TSharedPtr<int32> SharedPtr)
{
	UE_LOG(LogTemp, Warning, TEXT("SharedPtr 참조 카운트 : %d"), SharedPtr.GetSharedReferenceCount());
}

void AChap33_TSharedPtrFunction::CountSharedPtrReference(TSharedPtr<int32>& SharedPtr)
{
	UE_LOG(LogTemp, Warning, TEXT("SharedPtr 참조 카운트 : %d"), SharedPtr.GetSharedReferenceCount());
}



