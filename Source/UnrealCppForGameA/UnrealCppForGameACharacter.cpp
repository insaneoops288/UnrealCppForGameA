// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealCppForGameACharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"

#include "Kismet/GameplayStatics.h"
#include "UnrealCppForGameAGameMode.h"
#include "GameFramework/PlayerController.h"

#include "DataSaveGame.h"

//////////////////////////////////////////////////////////////////////////
// AUnrealCppForGameACharacter

AUnrealCppForGameACharacter::AUnrealCppForGameACharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rate for input
	TurnRateGamepad = 50.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void AUnrealCppForGameACharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("ChangePlayer", IE_Pressed, this, &AUnrealCppForGameACharacter::OnChangePlayer);

	PlayerInputComponent->BindAction("Save", IE_Pressed, this, &AUnrealCppForGameACharacter::OnSave);
	PlayerInputComponent->BindAction("Load", IE_Pressed, this, &AUnrealCppForGameACharacter::OnLoad);

	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &AUnrealCppForGameACharacter::MoveForward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &AUnrealCppForGameACharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn Right / Left Mouse", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Turn Right / Left Gamepad", this, &AUnrealCppForGameACharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("Look Up / Down Mouse", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Look Up / Down Gamepad", this, &AUnrealCppForGameACharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AUnrealCppForGameACharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AUnrealCppForGameACharacter::TouchStopped);
}

void AUnrealCppForGameACharacter::OnChangePlayer()
{
	SetActorHiddenInGame(true);
	SetLifeSpan(0.01f);

	APlayerController* GetController =
		UGameplayStatics::GetPlayerController(GetWorld(), 0);

	GetController->UnPossess();

	AUnrealCppForGameAGameMode* GameMode =
		Cast<AUnrealCppForGameAGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	int32 RandomIndex = FMath::RandRange(0, GameMode->Players.Num() - 1);
	FVector SpawnLocation = this->GetActorLocation() + FVector(0.0f, 0.0f, 400.0f);
	FRotator SpawnRotation = this->GetActorRotation();
	FActorSpawnParameters SpawnParams;
	AUnrealCppForGameACharacter* Player =
		GetWorld()->
		SpawnActor<AUnrealCppForGameACharacter>(GameMode->Players[RandomIndex], SpawnLocation, SpawnRotation, SpawnParams);

	GetController->Possess(Player);
}

void AUnrealCppForGameACharacter::OnSave()
{
	UDataSaveGame* SaveGameObject = 
		Cast<UDataSaveGame>(UGameplayStatics::CreateSaveGameObject(UDataSaveGame::StaticClass()));

	if (SaveGameObject)
	{
		SaveGameObject->SaveSlotName = "SaveGameTest1";
		SaveGameObject->SaveSlotIndex = 1;

		SaveGameObject->SaveStruct.StructInteger = 15;
		SaveGameObject->SaveTArray.Add(1);
		SaveGameObject->SaveTArray.Add(3);
		SaveGameObject->SaveTArray.Add(6);
		SaveGameObject->SaveInt = 1024;
		SaveGameObject->SaveFloat = 3.14159265f;
		SaveGameObject->SaveString = TEXT("우리는 언리얼 C++을 공부하고 있습니다. !!");
		SaveGameObject->SaveName = TEXT("언리얼 C++은 너무 재미있습니다. !!");
		SaveGameObject->SaveVector = FVector(10.0f, 11.0f, 12.0f);
		SaveGameObject->SaveRotator = FRotator(10.0f, 11.0f, 12.0f);
		SaveGameObject->SaveTransform = FTransform(FVector(10.0f, 11.0f, 12.0f));
	}
	UGameplayStatics::SaveGameToSlot(SaveGameObject, SaveGameObject->SaveSlotName, SaveGameObject->SaveSlotIndex);
}

void AUnrealCppForGameACharacter::OnLoad()
{
	UDataSaveGame* LoadGameObject = 
		Cast<UDataSaveGame>(UGameplayStatics::CreateSaveGameObject(UDataSaveGame::StaticClass()));
	if (LoadGameObject)
	{
		LoadGameObject->SaveSlotName = "SaveGameTest1";
		LoadGameObject->SaveSlotIndex = 1;

		LoadGameObject = 
			Cast<UDataSaveGame>(UGameplayStatics::LoadGameFromSlot(LoadGameObject->SaveSlotName, LoadGameObject->SaveSlotIndex));

		UE_LOG(LogTemp, Warning, TEXT("SaveStruct : %d"), LoadGameObject->SaveStruct.StructInteger);
		UE_LOG(LogTemp, Warning, TEXT("SaveTArray : [%d, %d, %d]"),
			LoadGameObject->SaveTArray[0], LoadGameObject->SaveTArray[1], LoadGameObject->SaveTArray[2]);
		UE_LOG(LogTemp, Warning, TEXT("SaveInt : %d"), LoadGameObject->SaveInt);
		UE_LOG(LogTemp, Warning, TEXT("SaveFloat : %f"), LoadGameObject->SaveFloat);
		UE_LOG(LogTemp, Warning, TEXT("SaveString : %s"), *LoadGameObject->SaveString);
		UE_LOG(LogTemp, Warning, TEXT("SaveName : %s"), *LoadGameObject->SaveName.ToString());
		UE_LOG(LogTemp, Warning, TEXT("SaveVector : %s"), *LoadGameObject->SaveVector.ToString());
		UE_LOG(LogTemp, Warning, TEXT("SaveRotator : %s"), *LoadGameObject->SaveRotator.ToString());
		UE_LOG(LogTemp, Warning, TEXT("SaveTransform : %s"), *LoadGameObject->SaveTransform.ToString());
	}
}

void AUnrealCppForGameACharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	Jump();
}

void AUnrealCppForGameACharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	StopJumping();
}

void AUnrealCppForGameACharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * TurnRateGamepad * GetWorld()->GetDeltaSeconds());
}

void AUnrealCppForGameACharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * TurnRateGamepad * GetWorld()->GetDeltaSeconds());
}

void AUnrealCppForGameACharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AUnrealCppForGameACharacter::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}
