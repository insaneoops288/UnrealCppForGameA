// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chap38_FObjectFinder.generated.h"

UCLASS()
class UNREALCPPFORGAMEA_API AChap38_FObjectFinder : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChap38_FObjectFinder();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Find", meta = (AllowPrivateAccess = true))
	class USkeletalMesh* SkeletalMesh;

	UPROPERTY(EditAnywhere, Category = "Find", meta = (AllowPrivateAccess = true))
	class UStaticMesh* StaticMesh;

	UPROPERTY(EditAnywhere, Category = "Find", meta = (AllowPrivateAccess = true))
	class UMaterial* Material;

	UPROPERTY(EditAnywhere, Category = "Find", meta = (AllowPrivateAccess = true))
	class UTexture2D* Texture2D;

	UPROPERTY(EditAnywhere, Category = "Find", meta = (AllowPrivateAccess = true))
	class UParticleSystem* ParticleSystem;

	UPROPERTY(EditAnywhere, Category = "Find", meta = (AllowPrivateAccess = true))
	class UNiagaraSystem* NiagaraSystem;

	UPROPERTY(EditAnywhere, Category = "Find", meta = (AllowPrivateAccess = true))
	class UNiagaraEmitter* NiagaraEmitter;

	UPROPERTY(EditAnywhere, Category = "Find", meta = (AllowPrivateAccess = true))
	class USoundCue* SoundCue;

	UPROPERTY(EditAnywhere, Category = "Find", meta = (AllowPrivateAccess = true))
	class USoundWave* SoundWave;

	UPROPERTY(EditAnywhere, Category = "Find", meta = (AllowPrivateAccess = true))
	class UBlackboardData* BlackboardData;

	UPROPERTY(EditAnywhere, Category = "Find", meta = (AllowPrivateAccess = true))
	class UBehaviorTree* BehaviorTree;

	UPROPERTY(EditAnywhere, Category = "Find", meta = (AllowPrivateAccess = true))
	class UAnimMontage* AnimMontage;

	UPROPERTY(EditAnywhere, Category = "Find", meta = (AllowPrivateAccess = true))
	class UAnimSequence* AnimSequence;

	UPROPERTY(EditAnywhere, Category = "Find", meta = (AllowPrivateAccess = true))
	class UMaterialInstanceConstant* MaterialInstanceConstant;

	UPROPERTY(EditAnywhere, Category = "Find", meta = (AllowPrivateAccess = true))
	TSubclassOf<class APawn> ThirdPersonPlayer;

	UPROPERTY(EditAnywhere, Category = "Find", meta = (AllowPrivateAccess = true))
	TSubclassOf<class UUserWidget> UserWidget;

	UPROPERTY(EditAnywhere, Category = "Find", meta = (AllowPrivateAccess = true))
	TSubclassOf<class UAnimInstance> AnimInstance;


};
