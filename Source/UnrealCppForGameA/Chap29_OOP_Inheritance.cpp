// Fill out your copyright notice in the Description page of Project Settings.


#include "Chap29_OOP_Inheritance.h"

// Sets default values
AChap29_OOP_Inheritance::AChap29_OOP_Inheritance()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChap29_OOP_Inheritance::BeginPlay()
{
	Super::BeginPlay();

	FChild1 Child1(1, 2);
	Child1.Add();

	UE_LOG(LogTemp, Warning, TEXT("Child1.Add() : %d"), Child1.Add());

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	FChild1* Child1A = new FChild1(1, 2);
	Child1A->Add();

	UE_LOG(LogTemp, Warning, TEXT("Child1A->Add() : %d"), Child1A->Add());

	delete Child1A;

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	FChild2 Child2;

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	FChild2* Child2A = new FChild2();

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	delete Child2A;

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	FParent3 Parent3;

	 // Parent3.IntValue3 = 1000000000000000000; 

	Parent3.IntValue3 = 2048;
	UE_LOG(LogTemp, Warning, TEXT("Parent3.IntValue3 : %d"), Parent3.IntValue3);

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	Parent3.SetValue(Parent3.IntValue3);
	UE_LOG(LogTemp, Warning, TEXT("Parent3.IntValue3 : %d"), Parent3.IntValue3);

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));


	FChild3 Child3;

	// Child3.IntValue2 = 10; 
	Child3.IntValue3 = 10;

	Parent3.SetValue(Child3.IntValue3);
	UE_LOG(LogTemp, Warning, TEXT("Parent3.IntValue3 : %d"), Parent3.IntValue3);

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	FChild5 Child5;
	Child5.Print();

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	FChild5 Child6(TEXT("철수"), 22, 99);
	Child6.Print();

	UE_LOG(LogTemp, Warning, TEXT("Child6.GetAge() : %d"), Child6.GetAge());

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));



}

// Called every frame
void AChap29_OOP_Inheritance::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




