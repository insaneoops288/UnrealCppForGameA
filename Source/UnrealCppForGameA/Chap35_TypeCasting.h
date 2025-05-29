// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chap35_TypeCasting.generated.h"

class FAnimal1
{
private:
    int ToothCount;
public:
    FAnimal1(int32 toothCount) : ToothCount(toothCount)
    {
        UE_LOG(LogTemp, Warning, TEXT("FAnimal1 생성자"));
    }
    ~FAnimal1()
    {
        UE_LOG(LogTemp, Warning, TEXT("FAnimal1 소멸자"));
    }
    void ShowInfo()
    {
        UE_LOG(LogTemp, Warning, TEXT("ToothCount : %d"), ToothCount);
    }
};

class FLion1 : public FAnimal1
{
private:
    int32 FamilyCount;
public:
    FLion1(int32 toothCount, int familyCount) : FAnimal1(toothCount), FamilyCount(familyCount)
    {
        UE_LOG(LogTemp, Warning, TEXT("FLion1 생성자"));
    }
    ~FLion1()
    {
        UE_LOG(LogTemp, Warning, TEXT("FLion1 소멸자"));
    }
    void ShowInfo()
    {
        FAnimal1::ShowInfo();
        UE_LOG(LogTemp, Warning, TEXT("FamilyCount : %d"), FamilyCount);
    }
};

class FAnimalA1
{
private:
    int ToothCount;
public:
    FAnimalA1(int32 toothCount) : ToothCount(toothCount)
    {
        UE_LOG(LogTemp, Warning, TEXT("FAnimalA1 생성자"));
    }
    ~FAnimalA1()
    {
        UE_LOG(LogTemp, Warning, TEXT("FAnimalA1 소멸자"));
    }
    virtual void ShowInfo()
    {
        UE_LOG(LogTemp, Warning, TEXT("ToothCount : %d"), ToothCount);
    }
};

class FTiger1 : public FAnimalA1
{
private:
    int32 FamilyCount;
public:
    FTiger1(int toothCount, int familyCount) : FAnimalA1(toothCount), FamilyCount(familyCount)
    {
        UE_LOG(LogTemp, Warning, TEXT("FTiger1 생성자"));
    }

    ~FTiger1()
    {
        UE_LOG(LogTemp, Warning, TEXT("FTiger1 소멸자"));
    }

    void ShowInfo()
    {
        FAnimalA1::ShowInfo();
        UE_LOG(LogTemp, Warning, TEXT("FamilyCount : %d"), FamilyCount);
    }
};

class FAnimalB1
{
private:
    int32 IntValue = 150;
public:
    FAnimalB1()
    {
        UE_LOG(LogTemp, Warning, TEXT("FAnimalB1 생성자"));
    }
    ~FAnimalB1()
    {
        UE_LOG(LogTemp, Warning, TEXT("FAnimalB1 소멸자"));
    }
    void SetInfo()
    {
        UE_LOG(LogTemp, Warning, TEXT("부모 클래스 입니다 : %d"), IntValue);
    }
};

class FCat1 : public FAnimalB1
{
private:
    int32 IntValue = 300;
public:
    FCat1()
    {
        UE_LOG(LogTemp, Warning, TEXT("FCat1 생성자"));
    }
    ~FCat1()
    {
        UE_LOG(LogTemp, Warning, TEXT("FCat1 소멸자"));
    }
    void SetInfo()
    {
        UE_LOG(LogTemp, Warning, TEXT("자식 클래스 입니다 : %d"), IntValue);
    }
};

class FDog1
{
public:
    FDog1()
    {
        UE_LOG(LogTemp, Warning, TEXT("FDog1 생성자"));
    }
    ~FDog1()
    {
        UE_LOG(LogTemp, Warning, TEXT("FDog1 소멸자"));
    }
};

class FBird1
{
public:
    FBird1()
    {
        UE_LOG(LogTemp, Warning, TEXT("FBird1 생성자"));
    }
    ~FBird1()
    {
        UE_LOG(LogTemp, Warning, TEXT("FBird1 소멸자"));
    }
};

class FAnimalC1
{
public:
    FAnimalC1()
    {
        UE_LOG(LogTemp, Warning, TEXT("FAnimalC1 생성자"));
    }
    virtual~FAnimalC1()
    {
        UE_LOG(LogTemp, Warning, TEXT("FAnimalC1 생성자"));
    }
    virtual void Eat()
    {
        UE_LOG(LogTemp, Warning, TEXT("FAnimalC1::Eat()"));
    }
};

class FCow1 : public FAnimalC1
{
public:
    FCow1()
    {
        UE_LOG(LogTemp, Warning, TEXT("FCow1 생성자"));
    }
    ~FCow1()
    {
        UE_LOG(LogTemp, Warning, TEXT("FCow1 소멸자"));
    }
    void Eat()
    {
        UE_LOG(LogTemp, Warning, TEXT("FCow1::Eat()"));
    }
};

class FFox1 : public FAnimalC1
{
public:
    FFox1()
    {
        UE_LOG(LogTemp, Warning, TEXT("FFox1 생성자"));
    }
    ~FFox1()
    {
        UE_LOG(LogTemp, Warning, TEXT("FFox1 생성자"));
    }
    void Eat()
    {
        UE_LOG(LogTemp, Warning, TEXT("FFox1::Eat()"));
    }
};



UCLASS()
class UNREALCPPFORGAMEA_API AChap35_TypeCasting : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChap35_TypeCasting();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
