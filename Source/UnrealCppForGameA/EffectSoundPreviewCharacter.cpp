// Fill out your copyright notice in the Description page of Project Settings.


#include "EffectSoundPreviewCharacter.h"

#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"
#include "Niagara/Public/NiagaraComponent.h"
#include "Niagara/Public/NiagaraFunctionLibrary.h"
#include "Niagara/Classes/NiagaraSystem.h"
#include "Sound/SoundCue.h"
#include "Kismet/GameplayStatics.h"
#include "EffectSoundPreviewGameMode.h"
#include "Blueprint/UserWidget.h"
#include "Components/EditableTextBox.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"

// Sets default values
AEffectSoundPreviewCharacter::AEffectSoundPreviewCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEffectSoundPreviewCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEffectSoundPreviewCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEffectSoundPreviewCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction
	("TestSpawnFX", IE_Pressed, this, &AEffectSoundPreviewCharacter::TestSpawnFX);
	PlayerInputComponent->BindAction
	("TestSpawnFXReverse", IE_Pressed, this, &AEffectSoundPreviewCharacter::TestSpawnFXReverse);
	PlayerInputComponent->BindAction
	("TestSpawnFXNiagara", IE_Pressed, this, &AEffectSoundPreviewCharacter::TestSpawnFXNiagara);
	PlayerInputComponent->BindAction
	("TestSpawnFXNiagaraReverse", IE_Pressed, this, &AEffectSoundPreviewCharacter::TestSpawnFXNiagaraReverse);
	PlayerInputComponent->BindAction
	("TestSpawnSound", IE_Pressed, this, &AEffectSoundPreviewCharacter::TestSpawnSound);
	PlayerInputComponent->BindAction
	("TestSpawnSoundReverse", IE_Pressed, this, &AEffectSoundPreviewCharacter::TestSpawnSoundReverse);
}

void AEffectSoundPreviewCharacter::TestSpawnFX()
{
	if (CommonFXsIndex >= CommonFXs.Num() || CommonFXsIndex < 0)
		CommonFXsIndex = 0;

	UParticleSystem* FX = CommonFXs[CommonFXsIndex];
	FString Message = 
		FString::Printf(TEXT("%d / %d : %s"), CommonFXsIndex, CommonFXs.Num() - 1, *FX->GetName());
	AEffectSoundPreviewGameMode* GameMode =
		Cast<AEffectSoundPreviewGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	UEditableTextBox* Preivew =
		Cast<UEditableTextBox>(GameMode->EffectSoundPreviewUserWidget->GetWidgetFromName(TEXT("EditableTextBoxPreivew")));
	Preivew->SetText(FText::FromString(Message));

	if (CurrentFX)
	{
		CurrentFX->Deactivate();
		CurrentFX->ResetParticles(true);
	}
	if (CurrentFXNiagara)
	{
		CurrentFXNiagara->DeactivateImmediate();
		CurrentFXNiagara->ResetSystem();
		CurrentFXNiagara->Activate(false);
	}
	CurrentFX = UGameplayStatics::SpawnEmitterAtLocation
	(this, FX, GetActorLocation() + FVector(600.0f, 0.0f, 0.0f), FRotator::ZeroRotator);
	CommonFXsIndex++;
}

void AEffectSoundPreviewCharacter::TestSpawnFXReverse()
{
	CommonFXsIndex--;
	if (CommonFXsIndex < 0)
		CommonFXsIndex = CommonFXs.Num() - 1;

	UParticleSystem* FX = CommonFXs[CommonFXsIndex];
	FString Message = 
		FString::Printf(TEXT("%d / %d : %s"), CommonFXsIndex, CommonFXs.Num() - 1, *FX->GetName());
	AEffectSoundPreviewGameMode* GameMode =
		Cast<AEffectSoundPreviewGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	UEditableTextBox* Preivew =
		Cast<UEditableTextBox>(GameMode->EffectSoundPreviewUserWidget->GetWidgetFromName(TEXT("EditableTextBoxPreivew")));
	Preivew->SetText(FText::FromString(Message));

	if (CurrentFX)
	{
		CurrentFX->Deactivate();
		CurrentFX->ResetParticles(true);
	}
	if (CurrentFXNiagara)
	{
		CurrentFXNiagara->DeactivateImmediate();
		CurrentFXNiagara->ResetSystem();
		CurrentFXNiagara->Activate(false);
	}
	CurrentFX = UGameplayStatics::SpawnEmitterAtLocation
	(this, FX, GetActorLocation() + FVector(600.0f, 0.0f, 0.0f), FRotator::ZeroRotator);
}

void AEffectSoundPreviewCharacter::TestSpawnFXNiagara()
{
	if (CommonFXsIndexNiagara >= CommonFXsNiagara.Num() || CommonFXsIndexNiagara < 0)
		CommonFXsIndexNiagara = 0;

	UNiagaraSystem* FX = CommonFXsNiagara[CommonFXsIndexNiagara];
	FString Message = 
		FString::Printf(TEXT("%d / %d : %s"), CommonFXsIndexNiagara, CommonFXsNiagara.Num() - 1, *FX->GetName());
	AEffectSoundPreviewGameMode* GameMode =
		Cast<AEffectSoundPreviewGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	UEditableTextBox* Preivew =
		Cast<UEditableTextBox>(GameMode->EffectSoundPreviewUserWidget->GetWidgetFromName(TEXT("EditableTextBoxPreivew")));
	Preivew->SetText(FText::FromString(Message));

	if (CurrentFX)
	{
		CurrentFX->Deactivate();
		CurrentFX->ResetParticles(true);
	}
	if (CurrentFXNiagara)
	{
		CurrentFXNiagara->DeactivateImmediate();
		CurrentFXNiagara->ResetSystem();
		CurrentFXNiagara->Activate(false);
	}
	CurrentFXNiagara = UNiagaraFunctionLibrary::SpawnSystemAtLocation
	(GetWorld(), FX, GetActorLocation() + FVector(600.0f, 0.0f, 0.0f), FRotator::ZeroRotator);
	
	CommonFXsIndexNiagara++;
}

void AEffectSoundPreviewCharacter::TestSpawnFXNiagaraReverse()
{
	CommonFXsIndexNiagara--;
	if (CommonFXsIndexNiagara < 0)
		CommonFXsIndexNiagara = CommonFXsNiagara.Num() - 1;

	UNiagaraSystem* FX = CommonFXsNiagara[CommonFXsIndexNiagara];
	FString Message = 
		FString::Printf(TEXT("%d / %d : %s"), CommonFXsIndexNiagara, CommonFXsNiagara.Num() - 1, *FX->GetName());
	AEffectSoundPreviewGameMode* GameMode =
		Cast<AEffectSoundPreviewGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	UEditableTextBox* Preivew =
		Cast<UEditableTextBox>(GameMode->EffectSoundPreviewUserWidget->GetWidgetFromName(TEXT("EditableTextBoxPreivew")));
	Preivew->SetText(FText::FromString(Message));

	if (CurrentFX)
	{
		CurrentFX->Deactivate();
		CurrentFX->ResetParticles(true);
	}
	if (CurrentFXNiagara)
	{
		CurrentFXNiagara->DeactivateImmediate();
		CurrentFXNiagara->ResetSystem();
		CurrentFXNiagara->Activate(false);
	}
	CurrentFXNiagara = UNiagaraFunctionLibrary::SpawnSystemAtLocation
	(GetWorld(), FX, GetActorLocation() + FVector(600.0f, 0.0f, 0.0f), FRotator::ZeroRotator);
}

void AEffectSoundPreviewCharacter::TestSpawnSound()
{
	if (CommonSoundsIndex >= CommonSounds.Num() || CommonSoundsIndex < 0)
		CommonSoundsIndex = 0;

	USoundCue* Sound = CommonSounds[CommonSoundsIndex];
	FString Message = 
		FString::Printf(TEXT("%d / %d : %s"), CommonSoundsIndex, CommonSounds.Num() - 1, *Sound->GetName());
	AEffectSoundPreviewGameMode* GameMode =
		Cast<AEffectSoundPreviewGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	UEditableTextBox* Preivew =
		Cast<UEditableTextBox>(GameMode->EffectSoundPreviewUserWidget->GetWidgetFromName(TEXT("EditableTextBoxPreivew")));
	Preivew->SetText(FText::FromString(Message));

	if (CurrentFX)
	{
		CurrentFX->Deactivate();
		CurrentFX->ResetParticles(true);
	}
	if (CurrentFXNiagara)
	{
		CurrentFXNiagara->DeactivateImmediate();
		CurrentFXNiagara->ResetSystem();
		CurrentFXNiagara->Activate(false);
	}
	UGameplayStatics::SpawnSoundAttached
	(Sound, RootComponent, NAME_None, FVector::ZeroVector, EAttachLocation::SnapToTarget, true);
	CommonSoundsIndex++;
}

void AEffectSoundPreviewCharacter::TestSpawnSoundReverse()
{
	CommonSoundsIndex--;
	if (CommonSoundsIndex < 0)
		CommonSoundsIndex = CommonSounds.Num() - 1;

	USoundCue* Sound = CommonSounds[CommonSoundsIndex];
	FString Message = 
		FString::Printf(TEXT("%d / %d : %s"), CommonSoundsIndex, CommonSounds.Num() - 1, *Sound->GetName());
	AEffectSoundPreviewGameMode* GameMode =
		Cast<AEffectSoundPreviewGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	UEditableTextBox* Preivew =
		Cast<UEditableTextBox>(GameMode->EffectSoundPreviewUserWidget->GetWidgetFromName(TEXT("EditableTextBoxPreivew")));
	Preivew->SetText(FText::FromString(Message));

	if (CurrentFX)
	{
		CurrentFX->Deactivate();
		CurrentFX->ResetParticles(true);
	}
	if (CurrentFXNiagara)
	{
		CurrentFXNiagara->DeactivateImmediate();
		CurrentFXNiagara->ResetSystem();
		CurrentFXNiagara->Activate(false);
	}
	UGameplayStatics::SpawnSoundAttached
	(Sound, RootComponent, NAME_None, FVector::ZeroVector, EAttachLocation::SnapToTarget, true);
}

