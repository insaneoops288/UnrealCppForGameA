// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealCppForGameAGameMode.h"
#include "UnrealCppForGameACharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealCppForGameAGameMode::AUnrealCppForGameAGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
