// Fill out your copyright notice in the Description page of Project Settings.


#include "Chap36_AddOnScreen.h"

#include "Kismet/GameplayStatics.h"
#include "UnrealCppForGameACharacter.h"

// Sets default values
AChap36_AddOnScreen::AChap36_AddOnScreen()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChap36_AddOnScreen::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green,
			TEXT("우리는 언리얼을 공부하고 있습니다. !!"), true, FVector2D(1.25f, 1.25f));
	}

	FString StringValue1 = TEXT("언리얼은 너무 재미 있습니다. !!");
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("StringValue1 : %s"), *StringValue1));
	}

	int32 IntValue1 = 1024;
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("IntValue1 : %d"), IntValue1));
	}

	float FloatValue1 = 3.14159265f;
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("FloatValue1 : %f"), FloatValue1));
	}

	bool BoolValue1 = true;

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("BoolValue1 : %d"), BoolValue1));
	}

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("BoolValue1 : %s"), BoolValue1 ? TEXT("true") : TEXT("false")));
	}

	FVector VectorValue1 = FVector(1.0f, 2.0f, 3.0f);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("VectorValue1 X : %f, Y : %f, Z : %f"), VectorValue1.X, VectorValue1.Y, VectorValue1.Z));
	}

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("VectorValue1 : %s"), *VectorValue1.ToString()));
	}

	FVector2D Vector2DValue1 = FVector2D(1.0f, 2.0f);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("Vector2DValue1 X %f, Y %f"), Vector2DValue1.X, Vector2DValue1.Y));
	}

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("Vector2DValue1 : %s"), *Vector2DValue1.ToString()));
	}

	FRotator RotatorValue1 = FRotator(1.0f, 2.0f, 3.0f);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("RotatorValue1 Pitch : %f, Yaw : %f, Roll : %f"),
			RotatorValue1.Pitch, RotatorValue1.Yaw, RotatorValue1.Roll));
	}

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("RotatorValue1 : %s"), *RotatorValue1.ToString()));
	}

	FLinearColor LinearColorValue1 = FLinearColor(1.f, 1.f, 1.f, 1.f);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("LinearColorValue1 R : %f, G : %f, B : %f, A : %f"),
			LinearColorValue1.R, LinearColorValue1.G, LinearColorValue1.B, LinearColorValue1.A));
	}

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("LinearColorValue1 : %s"), *LinearColorValue1.ToString()));
	}

	UObject* ObjectValue1 = nullptr;
	FString StringValue2 = ObjectValue1 != nullptr ? ObjectValue1->GetName() : TEXT("None");
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("StringValue2 : %s"), *StringValue2));
	}

	ObjectValue1 = Cast<AUnrealCppForGameACharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	FString StringValue3 = ObjectValue1 != nullptr ? ObjectValue1->GetName() : TEXT("None");
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("StringValue3 : %s"), *StringValue3));
	}

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Green, FString::Printf(TEXT("IntValue1 : %d, FloatValue1 : %f, BoolValue1 : %d, StringValue1 : %s"),
			IntValue1, FloatValue1, BoolValue1, *StringValue1));
	}

}

// Called every frame
void AChap36_AddOnScreen::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

