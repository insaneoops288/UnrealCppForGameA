// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EffectSoundPreviewCharacter.generated.h"

UCLASS()
class UNREALCPPFORGAMEA_API AEffectSoundPreviewCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEffectSoundPreviewCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditDefaultsOnly, Category = "Effect")
	TArray<class UParticleSystem*> CommonFXs;

	int32 CommonFXsIndex;

	/** 위치를 문자열로 저장 */
	UPROPERTY(EditDefaultsOnly, Category = "Effect")
	TArray<class UNiagaraSystem*> CommonFXsNiagara;

	int32 CommonFXsIndexNiagara;

	UPROPERTY(EditDefaultsOnly, Category = "Effect")
	TArray<class USoundCue*> CommonSounds;

	int32 CommonSoundsIndex;

	UFUNCTION()
	void TestSpawnFX();
	UFUNCTION()
	void TestSpawnFXReverse();
	UPROPERTY(EditAnywhere, Category = "FX")
	class UParticleSystemComponent* CurrentFX;

	UFUNCTION()
	void TestSpawnFXNiagara();
	UFUNCTION()
	void TestSpawnFXNiagaraReverse();
	UPROPERTY(EditAnywhere, Category = FX)
	class UNiagaraComponent* CurrentFXNiagara;

	UFUNCTION()
	void TestSpawnSound();
	UFUNCTION()
	void TestSpawnSoundReverse();
	UPROPERTY(EditAnywhere, Category = "FX")
	class USoundCue* CurrentSoundSource;

};
