// Fill out your copyright notice in the Description page of Project Settings.


#include "Chap39_GetAllActorsWithTag.h"

#include "Kismet/GameplayStatics.h"
#include "RandomPosition.h"
#include "Engine/StaticMeshActor.h"
#include "Item.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimBlueprint.h"

#include "UnrealCppForGameACharacter.h"

#include "EngineUtils.h"

#include "Components/CapsuleComponent.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"

#include "Particles/ParticleSystem.h"
#include "Engine/Texture2D.h"
#include "Sound/SoundCue.h"


// Sets default values
AChap39_GetAllActorsWithTag::AChap39_GetAllActorsWithTag()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChap39_GetAllActorsWithTag::BeginPlay()
{
	Super::BeginPlay();

TArray<AActor*> CollectActorsWithTag1;
UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName(TEXT("Item")), CollectActorsWithTag1);

UE_LOG(LogTemp, Warning, TEXT("CollectActorsWithTag1 Count : %d"), CollectActorsWithTag1.Num());

for (AActor* Actor : CollectActorsWithTag1)
{
	UE_LOG(LogTemp, Warning, TEXT("Actor : %s"), *Actor->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

TArray<AActor*> CollectActors2 = GetWorld()->GetCurrentLevel()->Actors;
UE_LOG(LogTemp, Warning, TEXT("CollectActors2.Num : %d"), CollectActors2.Num());

TArray<AActor*> CollectActorsWithTag2;

for (TActorIterator<AActor> Iterator2(GetWorld()); Iterator2; ++Iterator2)
{
	if (Iterator2->ActorHasTag(FName(TEXT("Item"))))
	{
		CollectActorsWithTag2.Add(*Iterator2);
	}
}
UE_LOG(LogTemp, Warning, TEXT("CollectActorsWithTag2.Num : %d"), CollectActorsWithTag2.Num());

for (AActor* Actor : CollectActorsWithTag2)
{
	UE_LOG(LogTemp, Warning, TEXT("ActorWithTag2 : %s"), *Actor->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

AUnrealCppForGameACharacter* Player =
	Cast<AUnrealCppForGameACharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

if (Player)
{
	if (Player->ActorHasTag(FName(TEXT("player"))))
	{
		UE_LOG(LogTemp, Warning, TEXT("Player has tag named \"Player\""));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player has not tag named \"Player\""));
	}
}

UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

TArray<AActor*> CollectActorsOfClass2;

TArray<ARandomPosition*> RandomPositions2;

UGameplayStatics::GetAllActorsOfClass(GetWorld(), ARandomPosition::StaticClass(), CollectActorsOfClass2);

for (AActor* Actor : CollectActorsOfClass2)
{
	RandomPositions2.Add(Cast<ARandomPosition>(Actor));
}

UE_LOG(LogTemp, Warning, TEXT("RandomPositions2 Count : %d"), RandomPositions2.Num());

for (ARandomPosition* RandomPosition : RandomPositions2)
{
	UE_LOG(LogTemp, Warning, TEXT("RandomPosition : %s"), *RandomPosition->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

TArray<AActor*> CollectActorsOfClass3;
TArray<AStaticMeshActor*> CollectStaticMeshActors3;
UGameplayStatics::GetAllActorsOfClass(GetWorld(), AStaticMeshActor::StaticClass(), CollectActorsOfClass3);
for (AActor* Actor : CollectActorsOfClass3)
{
	CollectStaticMeshActors3.Add(Cast<AStaticMeshActor>(Actor));
}

UE_LOG(LogTemp, Warning, TEXT("CollectStaticMeshActors Count : %d"), CollectStaticMeshActors3.Num());

for (AStaticMeshActor* StaticMeshActo : CollectStaticMeshActors3)
{
	UE_LOG(LogTemp, Warning, TEXT("StaticMeshActor : %s"), *StaticMeshActo->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

// Class'/Script/UnrealCppForGameA.Item'
FString ClassPath1 = TEXT("Class'/Script/UnrealCppForGameA.Item'");
UClass* ClassAsset1 = FindObject<UClass>(ANY_PACKAGE, *ClassPath1);
if (ClassAsset1)
{
	UE_LOG(LogTemp, Warning, TEXT("ClassAsset1 : %s"), *ClassAsset1->GetFName().ToString());
}

UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

// Blueprint'/Game/Blueprints/BP_Item.BP_Item'
FString ClassPath2 = TEXT("Blueprint'/Game/Blueprints/BP_Item.BP_Item_C'");
UClass* ClassAsset2 = FindObject<UClass>(ANY_PACKAGE, *ClassPath2);
AItem* AItemAsset2 = (AItem*)(ClassAsset2);
if (ClassAsset2)
{
	UE_LOG(LogTemp, Warning, TEXT("ClassAsset2 : %s"), *ClassAsset2->GetFName().ToString());
}

if (AItemAsset2)
{
	UE_LOG(LogTemp, Warning, TEXT("AItemAsset2 : %s"), *AItemAsset2->GetFName().ToString());
}

UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

// SkeletalMesh'/Game/Assets/USkeletalMesh/SK_Mannequin.SK_Mannequin'
FString SkeletalMeshPath2 = TEXT("SkeletalMesh'/Game/Assets/USkeletalMesh/SK_Mannequin.SK_Mannequin'");
USkeletalMesh* SkeletalMeshAsset2 = FindObject<USkeletalMesh>(ANY_PACKAGE, *SkeletalMeshPath2);
if (SkeletalMeshAsset2)
{
	UE_LOG(LogTemp, Warning, TEXT("SkeletalMeshAsset2 : %s"), *SkeletalMeshAsset2->GetFName().ToString());
}

UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

// Texture2D'/Game/Assets/UTexture2D/T_Brick_Clay_Beveled_D.T_Brick_Clay_Beveled_D'
FString Texture2DPath3 = TEXT("Texture2D'/Game/Assets/UTexture2D/T_Brick_Clay_Beveled_D.T_Brick_Clay_Beveled_D'");
UTexture2D* Texture2DAsset3 = LoadObject<UTexture2D>(NULL, *Texture2DPath3, NULL, LOAD_None, NULL);
if (Texture2DAsset3)
{
	UE_LOG(LogTemp, Warning, TEXT("Texture2DAsset3 : %s"), *Texture2DAsset3->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

// SkeletalMesh'/Game/Assets/USkeletalMesh/SK_Mannequin.SK_Mannequin'
FString SkeletalMeshPath3 = TEXT("SkeletalMesh'/Game/Assets/USkeletalMesh/SK_Mannequin.SK_Mannequin'");
USkeletalMesh* SkeletalMeshAsset3 = LoadObject<USkeletalMesh>(NULL, *SkeletalMeshPath3, NULL, LOAD_None, NULL);
if (SkeletalMeshAsset3)
{
	UE_LOG(LogTemp, Warning, TEXT("SkeletalMeshAsset3 : %s"), *SkeletalMeshAsset3->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

// AnimBlueprint'/Game/Assets/UAnimInstance/ABP_Creature.ABP_Creature'
FString AnimInstancePath3 = TEXT("AnimBlueprint'/Game/Assets/UAnimInstance/ABP_Creature.ABP_Creature'");
UAnimBlueprint* AnimInstanceAsset3 = LoadObject<UAnimBlueprint>(NULL, *AnimInstancePath3, NULL, LOAD_None, NULL);
// UAnimInstance* AnimInstanceAsset31 = LoadObject<UAnimInstance>(NULL, *AnimInstancePath3, NULL, LOAD_None, NULL); // (X)
UAnimInstance* AnimInstanceAsset32 = (UAnimInstance*)(AnimInstanceAsset3);

if (AnimInstanceAsset3)
{
	UE_LOG(LogTemp, Warning, TEXT("AnimInstanceAsset3 : %s"), *AnimInstanceAsset3->GetName());
}
if (AnimInstanceAsset32)
{
	UE_LOG(LogTemp, Warning, TEXT("AnimInstanceAsset32 : %s"), *AnimInstanceAsset32->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

// Material'/Game/Assets/UMaterial/M_Brick_Clay_Beveled.M_Brick_Clay_Beveled'
FString MaterialPath4 = TEXT("Material'/Game/Assets/UMaterial/M_Brick_Clay_Beveled.M_Brick_Clay_Beveled'");
UMaterial* MaterialAsset4 = (UMaterial*)StaticLoadObject(UMaterial::StaticClass(), NULL, *MaterialPath4, NULL, LOAD_None, NULL);
if (MaterialAsset4)
{
	UE_LOG(LogTemp, Warning, TEXT("MaterialAsset4 : %s"), *MaterialAsset4->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

// Blueprint'/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter'
FString ObjectPath4 = TEXT("Blueprint'/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter'");
UObject* ObjectAsset4 = StaticLoadObject(UObject::StaticClass(), NULL, *ObjectPath4, NULL, LOAD_None, NULL);
UBlueprint* BlueprintAsset4 = Cast<UBlueprint>(ObjectAsset4);
UClass* ClassAsset4 = (UClass*)BlueprintAsset4->GeneratedClass;
AUnrealCppForGameACharacter* CharacterAsset4 = (AUnrealCppForGameACharacter*)ClassAsset4;

// UBlueprint* ObjectAsset5 = StaticLoadObject(UBlueprint::StaticClass(), NULL, *ObjectPath4, NULL, LOAD_None, NULL); // (X)
if (ObjectAsset4)
{
	UE_LOG(LogTemp, Warning, TEXT("ObjectAsset4 : %s"), *ObjectAsset4->GetName());
}
if (BlueprintAsset4)
{
	UE_LOG(LogTemp, Warning, TEXT("BlueprintAsset4 : %s"), *BlueprintAsset4->GetName());
}
if (ClassAsset4)
{
	UE_LOG(LogTemp, Warning, TEXT("ClassAsset4 : %s"), *ClassAsset4->GetName());
}
if (CharacterAsset4)
{
	UE_LOG(LogTemp, Warning, TEXT("CharacterAsset4 : %s"), *CharacterAsset4->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

// ParticleSystem'/Game/Assets/UParticleSystem/P_ky_aquaStorm.P_ky_aquaStorm'
FString ParticleSystemPath4 = TEXT("ParticleSystem'/Game/Assets/UParticleSystem/P_ky_aquaStorm.P_ky_aquaStorm'");
UParticleSystem* ParticleSysemAsset4 =
	(UParticleSystem*)StaticLoadObject(UParticleSystem::StaticClass(), NULL, *ParticleSystemPath4, NULL, LOAD_None, NULL);
if (ParticleSysemAsset4)
{
	UE_LOG(LogTemp, Warning, TEXT("ParticleSysemAsset4 : %s"), *ParticleSysemAsset4->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

// Texture2D'/Game/Assets/UTexture2D/T_Brick_Clay_Beveled_D.T_Brick_Clay_Beveled_D'
FString Texture2DPath4 = TEXT("Texture2D'/Game/Assets/UTexture2D/T_Brick_Clay_Beveled_D.T_Brick_Clay_Beveled_D'");
UTexture2D* Texture2DAsset4 =
	(UTexture2D*)StaticLoadObject(UTexture2D::StaticClass(), NULL, *Texture2DPath4, NULL, LOAD_None, NULL);
if (Texture2DAsset4)
{
	UE_LOG(LogTemp, Warning, TEXT("Texture2DAsset4 : %s"), *Texture2DAsset4->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

// StaticMesh'/Game/Assets/UStaticMesh/SM_Chair.SM_Chair'
FString StaticMeshPath4 = TEXT("StaticMesh'/Game/Assets/UStaticMesh/SM_Chair.SM_Chair'");
UStaticMesh* StaticMeshAsset4 =
	Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr, *StaticMeshPath4, nullptr, LOAD_None, nullptr));
if (StaticMeshAsset4)
{
	UE_LOG(LogTemp, Warning, TEXT("StaticMeshAsset4 : %s"), *StaticMeshAsset4->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

// SoundCue'/Game/Assets/USoundCue/Abstract_Pop_01_Cue.Abstract_Pop_01_Cue'
FString SoundCuePath4 = TEXT("SoundCue'/Game/Assets/USoundCue/Abstract_Pop_01_Cue.Abstract_Pop_01_Cue'");
USoundCue* SoundCueAsset4 =
	Cast<USoundCue>(StaticLoadObject(USoundCue::StaticClass(), NULL, *SoundCuePath4, NULL, LOAD_None, NULL));
if (SoundCueAsset4)
{
	UE_LOG(LogTemp, Warning, TEXT("SoundCueAsset4 : %s"), *SoundCueAsset4->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

AUnrealCppForGameACharacter* PlayerAvatar =
	Cast<AUnrealCppForGameACharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

if (PlayerAvatar)
{
	UE_LOG(LogTemp, Warning, TEXT("PlayerAvatar : %s"), *PlayerAvatar->GetName());
	USkeletalMeshComponent* SkeletalMeshComponent = PlayerAvatar->FindComponentByClass<USkeletalMeshComponent>();
	if (SkeletalMeshComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("SkeletalMeshComponent : %s"), *SkeletalMeshComponent->GetName());
	}

	UCapsuleComponent* CapsuleComponent = PlayerAvatar->FindComponentByClass<UCapsuleComponent>();
	if (CapsuleComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("CapsuleComponent : %s"), *CapsuleComponent->GetName());
	}

	UArrowComponent* ArrowComponent = PlayerAvatar->FindComponentByClass<UArrowComponent>();
	if (ArrowComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("ArrowComponent : %s"), *ArrowComponent->GetName());
	}

	USpringArmComponent* SpringArmComponent = PlayerAvatar->FindComponentByClass<USpringArmComponent>();
	if (SpringArmComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("SpringArmComponent : %s"), *SpringArmComponent->GetName());
	}

	UCameraComponent* CameraComponent = PlayerAvatar->FindComponentByClass<UCameraComponent>();
	if (CameraComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("CameraComponent : %s"), *CameraComponent->GetName());
	}

	UBoxComponent* BoxComponent = PlayerAvatar->FindComponentByClass<UBoxComponent>();
	if (BoxComponent)
	{
		UE_LOG(LogTemp, Warning, TEXT("BoxComponent : %s"), *BoxComponent->GetName());
	}
}

UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

TArray<USceneComponent*> CollectActorsWithItemTag4;

for (TActorIterator<AActor> Iterator4(GetWorld()); Iterator4; ++Iterator4)
{
	USceneComponent* SceneComponent = Iterator4->FindComponentByClass<USceneComponent>();
	if (SceneComponent)
	{
		if (SceneComponent->ComponentHasTag(FName(TEXT("Item"))))
		{
			CollectActorsWithItemTag4.Add(SceneComponent);
		}
	}
}

UE_LOG(LogTemp, Warning, TEXT("CollectActorsWithItemTag4 Count : %d"), CollectActorsWithItemTag4.Num());

UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

for (USceneComponent* SceneComponent : CollectActorsWithItemTag4)
{
	UE_LOG(LogTemp, Warning, TEXT("SceneComponent : %s"), *SceneComponent->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

TArray<UStaticMeshComponent*> CollectStaticMeshComponent5;

for (TActorIterator<AActor> Iterator5(GetWorld()); Iterator5; ++Iterator5)
{
	UStaticMeshComponent* StaticMeshComponent = Iterator5->FindComponentByClass<UStaticMeshComponent>();
	if (StaticMeshComponent)
	{
		CollectStaticMeshComponent5.Add(StaticMeshComponent);
	}
}

UE_LOG(LogTemp, Warning, TEXT("CollectStaticMeshComponent5 Count : %d"), CollectStaticMeshComponent5.Num());

UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

for (UStaticMeshComponent* StaticMeshComponent : CollectStaticMeshComponent5)
{
	UE_LOG(LogTemp, Warning, TEXT("StaticMeshComponent : %s"), *StaticMeshComponent->GetName());
}

UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	
}

// Called every frame
void AChap39_GetAllActorsWithTag::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

