// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chap33_TSharedPtrFunction.generated.h"

UCLASS()
class UNREALCPPFORGAMEA_API AChap33_TSharedPtrFunction : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChap33_TSharedPtrFunction();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void CountSharedPtrValue(TSharedPtr<int32> SharedPtr);

	void CountSharedPtrReference(TSharedPtr<int32>& SharedPtr);

};
