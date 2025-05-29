// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealCppAnimInstance.h"

#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


void UUnrealCppAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	AActor* Actor = GetOwningActor();
	Character = Cast<ACharacter>(Actor);

	if (IsValid(Character))
	{
		MovementComponent = Character->GetCharacterMovement();
	}
}


void UUnrealCppAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (IsValid(Character))
	{
		if (IsValid(MovementComponent))
		{
			GroundSpeed = MovementComponent->Velocity.Size2D();
			bShouldMove = 
				(GroundSpeed > 3) && (MovementComponent->GetCurrentAcceleration() != FVector(0.0f, 0.0f, 0.0f));

			bIsFalling = MovementComponent->IsFalling();
		}
	}
}

