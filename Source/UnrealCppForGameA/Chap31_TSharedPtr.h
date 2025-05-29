// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chap31_TSharedPtr.generated.h"

class FDog
{
public:
	FDog()
	{
		UE_LOG(LogTemp, Warning, TEXT("강아지 생성자. !!"));
	}

	~FDog()
	{
		UE_LOG(LogTemp, Warning, TEXT("강아지 소멸자!!"));
	}
};

class FAnt
{
public:
	FAnt()
	{
		UE_LOG(LogTemp, Warning, TEXT("개미 생성자. !!"));
	}

	~FAnt()
	{
		UE_LOG(LogTemp, Warning, TEXT("개미 소멸자!!"));
	}
};

class FBee
{
public:
	FBee()
	{
		UE_LOG(LogTemp, Warning, TEXT("벌 생성자. !!"));
	}

	~FBee()
	{
		UE_LOG(LogTemp, Warning, TEXT("벌 소멸자. !!"));
	}
};

class FHornet
{
private:
	TSharedPtr<FHornet> Hornet1;
public:
	FHornet()
	{
		UE_LOG(LogTemp, Warning, TEXT(" 말벌 생성자. !!"));
	}

	~FHornet()
	{
		UE_LOG(LogTemp, Warning, TEXT("말벌 소멸자. !!"));
	}

	void Show(TSharedPtr<FHornet> hornet)
	{
		Hornet1 = hornet;
	}
};




UCLASS()
class UNREALCPPFORGAMEA_API AChap31_TSharedPtr : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChap31_TSharedPtr();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
