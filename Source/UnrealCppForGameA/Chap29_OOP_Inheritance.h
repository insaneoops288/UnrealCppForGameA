// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chap29_OOP_Inheritance.generated.h"

class FParent1
{
private:
    int32 IntValue1;
    int32 IntValue2;
    int32 IntValue3;
public: 
    FParent1() {}

    FParent1(int32 Value1, int32 Value2)
    {
        IntValue1 = Value1;
        IntValue2 = Value2;
    }

    FParent1(int32 Value1, int32 Value2, int32 Value3) : IntValue1(Value1), IntValue2(Value2), IntValue3(Value3) {}

    int32 Add()
    {
        return IntValue1 + IntValue2;
    }
protected:
};

class FChild1 : public FParent1
{
public:
    FChild1(int32 Value1, int32 Value2) : FParent1(Value1, Value2) {}
};

class FParent2
{
public:
    FParent2()
    {
        UE_LOG(LogTemp, Warning, TEXT("Parent2 생성자. !!"));
    }

    ~FParent2()
    {
        UE_LOG(LogTemp, Warning, TEXT("Parent2 소멸자. !!"));
    }
};

class FChild2 : public FParent2
{
public:
    FChild2()
    {
        UE_LOG(LogTemp, Warning, TEXT("Child2 생성자. !!"));
    }

    ~FChild2()
    {
        UE_LOG(LogTemp, Warning, TEXT("Child2 소멸자. !!"));
    }
};

class FParent3
{
private:
    int32 IntValue1 = 10;
protected:
    int32 IntValue2 = 10;
public:
    int32 IntValue3 = 10;

    FParent3()
    {
        IntValue1 = 0;
        IntValue2 = 0;
        IntValue3 = 0;
    }

    void SetValue(int32 Value)
    {
        if (Value > 100)
        {
            Value = 100;
        }

        IntValue3 = Value;
    }

    int32 GetValueA() const
    {
        // IntValue1 = 50; // (X)
        return IntValue1;
    }

    int32 GetValueB()
    {
        IntValue1 = 50;
        return IntValue1;
    }
};

class FChild3 : public FParent3
{
public:
    void SetInfo()
    {
        IntValue2 = 10;
        IntValue3 = 10;
    }
};

class FParent4
{
    FString Name;
    int32 Age;

    int32 GetAge() const
    {
        FString FriendName = "Smith";
        return Age;
    }
};

class FChild4 : public FParent4
{
    int32 ID;
public:
    void Print()
    {
         // GetAge(); // (X)
          // UE_LOG(LogTemp, Warning, TEXT("Name : %s"), *Name);
          // UE_LOG(LogTemp, Warning, TEXT("Age : %d"), Age);
        UE_LOG(LogTemp, Warning, TEXT("Id : %d"), ID);
    }
};

class FParent5
{
protected:
    FString Name;
    int32 Age;
public:
    int32 GetAge() const
    {
        return Age;
    }

    FParent5() {}

    FParent5(FString name, int32 age) : Name(name), Age(age) {}
};

class FChild5 : public FParent5
{
    int32 ID;
public:
    FChild5()
    {
        Name = "";
        Age = 0;
        ID = 0;
    }

    FChild5(FString name, int32 age, int32 id) : FParent5(name, age), ID(id) {}

    void Print()
    {
        UE_LOG(LogTemp, Warning, TEXT("Name : %s"), *Name);
        UE_LOG(LogTemp, Warning, TEXT("Age : %d"), Age);
        UE_LOG(LogTemp, Warning, TEXT("Id : %d"), ID);
    }
};


UCLASS()
class UNREALCPPFORGAMEA_API AChap29_OOP_Inheritance : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChap29_OOP_Inheritance();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
