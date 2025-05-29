// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chap34_TWeakPtr.generated.h"

class FPersonA
{
    FString Name = TEXT("");
    TSharedPtr<FPersonA> SharedPtr;

public:
    FPersonA(const FString& name) : Name(name)
    {
        UE_LOG(LogTemp, Warning, TEXT("%s 생성자가 호출되었습니다."), *Name);
    }
    ~FPersonA()
    {
        UE_LOG(LogTemp, Warning, TEXT("%s 소멸자가 호출되었습니다."), *Name);
    }
    bool SetSharedPtr(TSharedPtr<FPersonA>& SharedPtr1)
    {
        if (!SharedPtr1)
        {
            return false;
        }
        this->SharedPtr = SharedPtr1;

        UE_LOG(LogTemp, Warning, TEXT("SharedPtr->Name : %s"), *SharedPtr->Name);

        return true;
    }
};

class FPersonB
{
    FString Name;
    TSharedPtr<FPersonB> SharedPtr;
public:
    FPersonB(const FString& name) : Name(name)
    {
        UE_LOG(LogTemp, Warning, TEXT("%s 생성자가 호출되었습니다."), *Name);
    }
    ~FPersonB()
    {
        UE_LOG(LogTemp, Warning, TEXT("%s 소멸자가 호출되었습니다."), *Name);
    }
    bool SetSharedPtr(TSharedPtr<FPersonB>& SharedPtr1)
    {
        if (!SharedPtr1)
        {
            return false;
        }
        this->SharedPtr = SharedPtr1;

        UE_LOG(LogTemp, Warning, TEXT("SharedPtr->Name : %s"), *SharedPtr->Name);

        return true;
    }
};

class FPersonD
{
    FString Name;
    TSharedPtr<FPersonD> SharedPtr;

public:
    FPersonD(const FString& name) : Name(name)
    {
        UE_LOG(LogTemp, Warning, TEXT("%s 생성자가 호출되었습니다."), *Name);
    }
    ~FPersonD()
    {
        UE_LOG(LogTemp, Warning, TEXT("%s 소멸자가 호출되었습니다."), *Name);
    }
    bool SetSharedPtr(TSharedPtr<FPersonD>& SharedPtr1, TSharedPtr<FPersonD>& SharedPtr2)
    {
        if (!SharedPtr1 || !SharedPtr2)
        {
            return false;
        }
        SharedPtr1->SharedPtr = SharedPtr2;
        SharedPtr2->SharedPtr = SharedPtr1;

        UE_LOG(LogTemp, Warning, TEXT("SharedPtr1->SharedPtr->Name : %s"), *SharedPtr1->SharedPtr->Name);
        UE_LOG(LogTemp, Warning, TEXT("SharedPtr2->SharedPtr->Name : %s"), *SharedPtr2->SharedPtr->Name);

        return true;
    }
};

class FPersonE
{
    FString Name;
    TWeakPtr<FPersonE> WeakPtr;

public:
    FPersonE(const FString& name) : Name(name)
    {
        UE_LOG(LogTemp, Warning, TEXT("%s 생성자가 호출되었습니다."), *Name);
    }
    ~FPersonE()
    {
        UE_LOG(LogTemp, Warning, TEXT("%s 소멸자가 호출되었습니다."), *Name);
    }
    bool SetSharedPtr(TSharedPtr<FPersonE>& SharedPtr1, TSharedPtr<FPersonE>& SharedPtr2)
    {
        if (!SharedPtr1 || !SharedPtr2)
        {          
            return false;
        }
        SharedPtr1->WeakPtr = SharedPtr2;
        SharedPtr2->WeakPtr = SharedPtr1;

        UE_LOG(LogTemp, Warning, TEXT("SharedPtr1->Name : %s, SharedPtr2->Name : %s"), *SharedPtr1->Name, *SharedPtr2->Name);

        return true;
    }
};

class FPersonF
{
    FString Name;
    TWeakPtr<FPersonF> WeakPtr;

public:
    FPersonF(const FString& name) : Name(name)
    {
        UE_LOG(LogTemp, Warning, TEXT("%s 생성자가 호출되었습니다."), *Name);
    }
    ~FPersonF()
    {
        UE_LOG(LogTemp, Warning, TEXT("%s 소멸자가 호출되었습니다."), *Name);
    }
    bool SetWeakPtr(TSharedPtr<FPersonF>& SharedPtr1, TSharedPtr<FPersonF>& SharedPtr2)
    {
        if (!SharedPtr1 || !SharedPtr2)
        {
            return false;
        }
        SharedPtr1->WeakPtr = SharedPtr2;
        SharedPtr2->WeakPtr = SharedPtr1;

        UE_LOG(LogTemp, Warning, TEXT("SharedPtr1->Name : %s, SharedPtr2->Name : %s"), *SharedPtr1->Name, *SharedPtr2->Name);

        return true;
    }

    TSharedPtr<FPersonF> GetSharedPtr()
    {
        return WeakPtr.Pin();
    }

    FString& GetName()
    {
        return Name;
    }
};

class FPersonG
{
private:
    FString Name;
    TWeakPtr<FPersonG> WeakPtr;

public:
    FPersonG(const FString& name) : Name(name)
    {
        UE_LOG(LogTemp, Warning, TEXT("%s 생성자가 호출되었습니다."), *Name);
    }
    ~FPersonG()
    {
        UE_LOG(LogTemp, Warning, TEXT("%s 소멸자가 호출되었습니다."), *Name);
    }

    void SetWeakPtr(TWeakPtr<FPersonG> WeakPtr1)
    {
        WeakPtr = WeakPtr1;
    }

    TSharedPtr<FPersonG> GetSharedPtr()
    {
        return WeakPtr.Pin();
    }
};

class FPersonH
{
private:
    FString Name;
    TSharedPtr<FPersonH> SharedPtr;
public:
    FPersonH(FString name) : Name{ name }
    {
        UE_LOG(LogTemp, Warning, TEXT("%s 생성자가 호출되었습니다."), *Name);
    }
    ~FPersonH()
    {
        UE_LOG(LogTemp, Warning, TEXT("%s 소멸자가 호출되었습니다."), *Name);
    }
    void SetSharedPtr(TSharedPtr<FPersonH> SharedPtr1)
    {
        SharedPtr = SharedPtr1;
    }
};

class FPersonI
{
private:
    FString Name;
    TSharedPtr<FPersonI> SharedPtr;
public:
    FPersonI(FString name) : Name(name)
    {
        UE_LOG(LogTemp, Warning, TEXT("%s 생성자가 호출되었습니다."), *Name);
    }
    ~FPersonI()
    {
        UE_LOG(LogTemp, Warning, TEXT("%s 소멸자가 호출되었습니다."), *Name);
    }
    void SetSharedPtr(TSharedPtr<FPersonI> SharedPtr1)
    {
        SharedPtr = SharedPtr1;
    }
};

class FPersonN
{
private:
    FString Name;
    TWeakPtr<FPersonN> WeakPtr;
    TSharedPtr<FPersonN> SharedPtr;
public:
    FPersonN(FString name) : Name(name)
    {
        UE_LOG(LogTemp, Warning, TEXT("%s 생성자가 호출되었습니다."), *Name);
        UE_LOG(LogTemp, Warning, TEXT("%s 생성자가 호출되었습니다."), *this->Name);
    }
    ~FPersonN()
    {
        UE_LOG(LogTemp, Warning, TEXT("%s 소멸자가 호출되었습니다."), *Name);
        UE_LOG(LogTemp, Warning, TEXT("%s 소멸자가 호출되었습니다."), *this->Name);
    }
    void SetWeakPtr(TWeakPtr<FPersonN> WeakPtr1)
    {
        WeakPtr = WeakPtr1;
    }
    void SetSharedPtr()
    {
        SharedPtr = WeakPtr.Pin();
        if (SharedPtr)
        {
            UE_LOG(LogTemp, Warning, TEXT("this->Name : %s, SharedPtr->Name : %s"), *this->Name, *SharedPtr->Name);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("SharedPtr은 empty입니다. "));
        }
    }
};

class FPersonO
{
    FString Name;
    TWeakPtr<FPersonO> WeakPtr;
    TSharedPtr<FPersonO> sharedPtr;
public:
    FPersonO(const FString& name) : Name(name)
    {
        UE_LOG(LogTemp, Warning, TEXT("%s 생성자가 호출되었습니다."), *Name);
    }
    ~FPersonO()
    {
        UE_LOG(LogTemp, Warning, TEXT("%s 소멸자가 호출되었습니다."), *Name);
    }
    void SetWeakPtr(TWeakPtr<FPersonO> WeakPtr1)
    {
        WeakPtr = WeakPtr1;
    }
    void SetSharedPtr()
    {
        TSharedPtr<FPersonO> SharedPtr = WeakPtr.Pin();
        if (sharedPtr)
        {
            UE_LOG(LogTemp, Warning, TEXT("SharedPtr->GetName() : %s"), *SharedPtr->GetName());
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("SharedPtr은 empty입니다. "));
        }
    }
    FString GetName()
    {
        return Name;
    }
};

class FPersonR
{
    FString Name;
    TWeakPtr<FPersonR> WeakPtr;
    TSharedPtr<FPersonR> SharedPtr;

public:
    FPersonR(const FString& name) : Name(name)
    {
        UE_LOG(LogTemp, Warning, TEXT("%s 생성자가 호출되었습니다."), *Name);
    }
    ~FPersonR()
    {
        UE_LOG(LogTemp, Warning, TEXT("%s 소멸자가 호출되었습니다."), *Name);
    }
    void SetWeakPtrA()
    {
        TSharedPtr<FPersonR> SharePtr1 = MakeShared<FPersonR>(TEXT("수달"));
        TWeakPtr<FPersonR> WeakPtr1 = SharePtr1;
    }
    void SetWeakPtrB()
    {
        TSharedPtr<FPersonR> SharePtr1 = MakeShared<FPersonR>(TEXT("고슴도치"));
        WeakPtr = SharePtr1;
    }
    void SetWeakPtrC()
    {
        TSharedPtr<FPersonR> SharedPtr1 = MakeShared<FPersonR>(TEXT("당나귀"));
        TWeakPtr<FPersonR> WeakPtr1 = SharedPtr1;

        if (!WeakPtr1.IsValid())
        {

        }
    }
    void SetWeakPtrD()
    {
        TSharedPtr<FPersonR> SharedPtr1 = MakeShared<FPersonR>(TEXT("양"));
        TWeakPtr<FPersonR> WeakPtr1 = SharedPtr1;
        WeakPtr1.Reset();

        if (!WeakPtr1.IsValid())
        {

        }
    }

    void SetSharedPtrA()
    {
        TSharedPtr<FPersonR> SharedPtr1 = WeakPtr.Pin();
        if (SharedPtr1)
        {
            UE_LOG(LogTemp, Warning, TEXT("SharedPtr->GetName() : %s"), *SharedPtr->GetName());
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("SharedPtr은 empty입니다. "));
        }
    }

    void SetSharedPtrB()
    {
        SharedPtr = WeakPtr.Pin();
        if (SharedPtr)
        {
            UE_LOG(LogTemp, Warning, TEXT("SharedPtr->GetName() : %s"), *SharedPtr->GetName());
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("SharedPtr은 empty입니다. "));
        }
    }

    FString GetName()
    {
        return Name;
    }
};



UCLASS()
class UNREALCPPFORGAMEA_API AChap34_TWeakPtr : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChap34_TWeakPtr();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
