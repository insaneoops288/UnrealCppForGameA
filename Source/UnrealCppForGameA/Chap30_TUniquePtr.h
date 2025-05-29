// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chap30_TUniquePtr.generated.h"

class FAnimal
{
public:
    FAnimal()
    {
        UE_LOG(LogTemp, Warning, TEXT("정적 할당 생성자!!"));
    }
    ~FAnimal()
    {
        UE_LOG(LogTemp, Warning, TEXT("정적 할당 소멸자"));
    }
};

class FLion
{
public:
    FLion()
    {
        UE_LOG(LogTemp, Warning, TEXT("new 연산자를 이용한 동적 할당 생성자")); 
    }

    ~FLion()
    {
        UE_LOG(LogTemp, Warning, TEXT("new 연산자를 이용한 동적 할당 소멸자"));
    }
};

class FTiger
{
public:
    FTiger()
    {
        UE_LOG(LogTemp, Warning, TEXT("스마트 포인터를 이용한 동적 할당 생성자"));
    }

    ~FTiger()
    {
        UE_LOG(LogTemp, Warning, TEXT("스마트 포인터를 이용한 동적 할당 소멸자"));
    }
};

class FCat
{
private:
    int32* Food;
    FString Name;
public:
    FCat()
    {
        Food = new int32[10000];
        UE_LOG(LogTemp, Warning, TEXT("Cat 생성자. !!"));
    }

    ~FCat()
    {
        UE_LOG(LogTemp, Warning, TEXT("Cat 소멸자. !!"));
    }

    void SetName(FString name)
    {
        Name = name;
    }

    FString GetName()
    {
        return Name;
    }
};




UCLASS()
class UNREALCPPFORGAMEA_API AChap30_TUniquePtr : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChap30_TUniquePtr();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
