// Fill out your copyright notice in the Description page of Project Settings.


#include "Chap38_FObjectFinder.h"

#include "NiagaraSystem.h"
#include "NiagaraEmitter.h"
#include "Particles/ParticleSystem.h"
#include "Sound/SoundCue.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Materials/MaterialInstanceConstant.h"
#include "Blueprint/UserWidget.h"


// Sets default values
AChap38_FObjectFinder::AChap38_FObjectFinder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

// SkeletalMesh'/Game/Assets/USkeletalMesh/SK_Mannequin.SK_Mannequin'
FString SkeletalMeshPath = TEXT("SkeletalMesh'/Game/Assets/USkeletalMesh/SK_Mannequin.SK_Mannequin'");
static ConstructorHelpers::FObjectFinder<USkeletalMesh>  SkeletalMeshAsset(*SkeletalMeshPath);
if (SkeletalMeshAsset.Succeeded())
{
	SkeletalMesh = SkeletalMeshAsset.Object;
	UE_LOG(LogTemp, Warning, TEXT("SkeletalMesh : %s"), *SkeletalMesh->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

// StaticMesh'/Game/Assets/UStaticMesh/SM_Chair.SM_Chair'
FString StaticMeshPath = TEXT("StaticMesh'/Game/Assets/UStaticMesh/SM_Chair.SM_Chair'");
static ConstructorHelpers::FObjectFinder<UStaticMesh>  StaticMeshAsset(*StaticMeshPath);
if (StaticMeshAsset.Succeeded())
{
	StaticMesh = StaticMeshAsset.Object;
	UE_LOG(LogTemp, Warning, TEXT("StaticMesh : %s"), *StaticMesh->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

// Material'/Game/Assets/UMaterial/M_Brick_Clay_Beveled.M_Brick_Clay_Beveled'
FString MaterialPath = TEXT("Material'/Game/Assets/UMaterial/M_Brick_Clay_Beveled.M_Brick_Clay_Beveled'");
static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(*MaterialPath);
if (MaterialAsset.Succeeded())
{
	Material = MaterialAsset.Object;
	UE_LOG(LogTemp, Warning, TEXT("Material : %s"), *Material->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

// Texture2D'/Game/Assets/UTexture2D/T_Brick_Clay_Beveled_D.T_Brick_Clay_Beveled_D'
FString Texture2DPath = TEXT("Texture2D'/Game/Assets/UTexture2D/T_Brick_Clay_Beveled_D.T_Brick_Clay_Beveled_D'");
static ConstructorHelpers::FObjectFinder<UTexture2D> Texture2DAsset(*Texture2DPath);
if (Texture2DAsset.Succeeded())
{
	Texture2D = Texture2DAsset.Object;
	UE_LOG(LogTemp, Warning, TEXT("Texture2D : %s"), *Texture2D->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

// ParticleSystem'/Game/Assets/UParticleSystem/P_ky_aquaStorm.P_ky_aquaStorm'
FString ParticleSystemPath = TEXT("ParticleSystem'/Game/Assets/UParticleSystem/P_ky_aquaStorm.P_ky_aquaStorm'");
static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleSystemAsset(*ParticleSystemPath);
if (ParticleSystemAsset.Succeeded())
{
	ParticleSystem = ParticleSystemAsset.Object;
	UE_LOG(LogTemp, Warning, TEXT("ParticleSystem : %s"), *ParticleSystem->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

// NiagaraSystem'/Game/Assets/UNiagaraSystem/PSN_Dirt_Surface.PSN_Dirt_Surface'
FString NiagaraSystemPath = TEXT("NiagaraSystem'/Game/Assets/UNiagaraSystem/PSN_Dirt_Surface.PSN_Dirt_Surface'");
static ConstructorHelpers::FObjectFinder<UNiagaraSystem> NiagaraSystemAsset(*NiagaraSystemPath);
if (NiagaraSystemAsset.Succeeded())
{
	NiagaraSystem = NiagaraSystemAsset.Object;
	UE_LOG(LogTemp, Warning, TEXT("NiagaraSystem : %s"), *NiagaraSystem->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

// NiagaraEmitter'/Game/Assets/UNiagaraEmitter/PEN_DirtBits.PEN_DirtBits'
FString NiagaraEmitterPath = TEXT("NiagaraEmitter'/Game/Assets/UNiagaraEmitter/PEN_DirtBits.PEN_DirtBits'");
static ConstructorHelpers::FObjectFinder<UNiagaraEmitter> NiagaraEmitterAsset(*NiagaraEmitterPath);
if (NiagaraEmitterAsset.Succeeded())
{
	NiagaraEmitter = NiagaraEmitterAsset.Object;
	UE_LOG(LogTemp, Warning, TEXT("NiagaraEmitter : %s"), *NiagaraEmitter->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

// SoundCue'/Game/Assets/USoundCue/Abstract_Pop_01_Cue.Abstract_Pop_01_Cue'
FString SoundCuePath = TEXT("SoundCue'/Game/Assets/USoundCue/Abstract_Pop_01_Cue.Abstract_Pop_01_Cue'");
static ConstructorHelpers::FObjectFinder<USoundCue> SoundCueAsset(*SoundCuePath);
if (SoundCueAsset.Succeeded())
{
	SoundCue = SoundCueAsset.Object;
	UE_LOG(LogTemp, Warning, TEXT("SoundCue : %s"), *SoundCue->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

// SoundWave'/Game/Assets/USoundWave/Abstract_Pop_01.Abstract_Pop_01'
FString SoundWavePath = TEXT("SoundWave'/Game/Assets/USoundWave/Abstract_Pop_01.Abstract_Pop_01'");
static ConstructorHelpers::FObjectFinder<USoundWave> SoundWaveAsset(*SoundWavePath);
if (SoundWaveAsset.Succeeded())
{
	SoundWave = SoundWaveAsset.Object;
	UE_LOG(LogTemp, Warning, TEXT("SoundWave : %s"), *SoundWave->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

// BlackboardData'/Game/Assets/UBlackboardData/BB_Creature.BB_Creature'
FString BlackboardDataPath = TEXT("BlackboardData'/Game/Assets/UBlackboardData/BB_Creature.BB_Creature'");
static ConstructorHelpers::FObjectFinder<UBlackboardData> BlackboardDataAsset(*BlackboardDataPath);
if (BlackboardDataAsset.Succeeded())
{
	BlackboardData = BlackboardDataAsset.Object;
	UE_LOG(LogTemp, Warning, TEXT("BlackboardData : %s"), *BlackboardData->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

// BehaviorTree'/Game/Assets/UBehaviorTree/BT_Creataure.BT_Creataure'
FString BehaviorTreePath = TEXT("BehaviorTree'/Game/Assets/UBehaviorTree/BT_Creataure.BT_Creataure'");
static ConstructorHelpers::FObjectFinder<UBehaviorTree> BehaviorTreeAsset(*BehaviorTreePath);
if (BehaviorTreeAsset.Succeeded())
{
	BehaviorTree = BehaviorTreeAsset.Object;
	UE_LOG(LogTemp, Warning, TEXT("BehaviorTree : %s"), *BehaviorTree->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

// AnimMontage'/Game/Assets/UAnimMontage/Aim_Space_Hip_Montage.Aim_Space_Hip_Montage'
FString AnimMontagePath = TEXT("AnimMontage'/Game/Assets/UAnimMontage/Aim_Space_Hip_Montage.Aim_Space_Hip_Montage'");
static ConstructorHelpers::FObjectFinder<UAnimMontage> AnimMontageAsset(*AnimMontagePath);
if (AnimMontageAsset.Succeeded())
{
	AnimMontage = AnimMontageAsset.Object;
	UE_LOG(LogTemp, Warning, TEXT("AnimMontage : %s"), *AnimMontage->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

// AnimSequence'/Game/Assets/UAnimSequence/Aim_Space_Hip.Aim_Space_Hip'
FString AnimSequencePath = TEXT("AnimSequence'/Game/Assets/UAnimSequence/Aim_Space_Hip.Aim_Space_Hip'");
static ConstructorHelpers::FObjectFinder<UAnimSequence> AnimSequenceAsset(*AnimSequencePath);
if (AnimSequenceAsset.Succeeded())
{
	AnimSequence = AnimSequenceAsset.Object;
	UE_LOG(LogTemp, Warning, TEXT("AnimSequence : %s"), *AnimSequence->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

// MaterialInstanceConstant'/Game/Assets/UMaterialInstanceConstant/Ice_inst.Ice_inst'
FString MaterialInstanceConstantPath = TEXT("MaterialInstanceConstant'/Game/Assets/UMaterialInstanceConstant/Ice_inst.Ice_inst'");
static ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant> MaterialInstanceConstantAsset(*MaterialInstanceConstantPath);
if (MaterialInstanceConstantAsset.Succeeded())
{
	MaterialInstanceConstant = MaterialInstanceConstantAsset.Object;
	UE_LOG(LogTemp, Warning, TEXT("MaterialInstanceConstant : %s"), *MaterialInstanceConstant->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

// Blueprint'/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter'
FString ThirdPersonPlayerPath = TEXT("Blueprint'/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter_C'");
static ConstructorHelpers::FClassFinder<APawn> ThirdPersonPlayerAsset(*ThirdPersonPlayerPath);
if (ThirdPersonPlayerAsset.Succeeded())
{
	ThirdPersonPlayer = ThirdPersonPlayerAsset.Class;
	UE_LOG(LogTemp, Warning, TEXT("ThirdPersonPlayer : %s"), *ThirdPersonPlayer->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

// WidgetBlueprint'/Game/Assets/UUserWidget/WBP_PianoAsset.WBP_PianoAsset'
FString UserWidgetPath = TEXT("WidgetBlueprint'/Game/Assets/UUserWidget/WBP_PianoAsset.WBP_PianoAsset_C'");
static ConstructorHelpers::FClassFinder<UUserWidget> UserWidgetAsset(*UserWidgetPath);
if (UserWidgetAsset.Succeeded())
{
	UserWidget = UserWidgetAsset.Class;
	UE_LOG(LogTemp, Warning, TEXT("UserWidget : %s"), *UserWidget->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

// AnimBlueprint'/Game/Assets/UAnimInstance/ABP_Creature.ABP_Creature'
FString AnimInstancePath = TEXT("AnimBlueprint'/Game/Assets/UAnimInstance/ABP_Creature.ABP_Creature_C'");
static ConstructorHelpers::FClassFinder<UAnimInstance> AnimInstanceAsset(*AnimInstancePath);
if (AnimInstanceAsset.Succeeded())
{
	AnimInstance = AnimInstanceAsset.Class;
	UE_LOG(LogTemp, Warning, TEXT("AnimInstance : %s"), *AnimInstance->GetName());

}

UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));
}

// Called when the game starts or when spawned
void AChap38_FObjectFinder::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChap38_FObjectFinder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

