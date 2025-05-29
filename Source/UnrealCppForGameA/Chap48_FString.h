// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chap48_FString.generated.h"

UENUM(BlueprintType)
enum class EItemStatus : uint8
{
	DailyItem UMETA(DisplayName = "DailyItem"),
	WeeklyItem UMETA(DisplayName = "WeeklyItem"),
	VIPItem UMETA(DisplayName = "VIPItem"),
	GameMoney UMETA(DisplayName = "GameMoney"),
	Cash UMETA(DisplayName = "Cash"),
};

UCLASS()
class UNREALCPPFORGAMEA_API AChap48_FString : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChap48_FString();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
