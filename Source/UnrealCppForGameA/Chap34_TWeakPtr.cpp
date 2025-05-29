// Fill out your copyright notice in the Description page of Project Settings.


#include "Chap34_TWeakPtr.h"

// Sets default values
AChap34_TWeakPtr::AChap34_TWeakPtr()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChap34_TWeakPtr::BeginPlay()
{
	Super::BeginPlay();

	TSharedPtr<FPersonA> SharedPtr1 = MakeShared<FPersonA>(TEXT("강아지"));
	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	TWeakPtr<FPersonA> WeakPtr1(SharedPtr1);
	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	TWeakPtr<FPersonA> WeakPtr2 = WeakPtr1;
	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	TSharedPtr<FPersonA> SharedPtr2 = MakeShared<FPersonA>(TEXT("고양이"));

	TSharedPtr<FPersonA> SharedPtr3 = MakeShared<FPersonA>(TEXT("사자"));

	TWeakPtr<FPersonA> WeakPtr3(SharedPtr2);
	// WeakPtr3->SetSharedPtr(SharedPtr3); 

	TSharedPtr<FPersonA> SharedPtr4 = WeakPtr3.Pin();

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	UE_LOG(LogTemp, Warning, TEXT("SharedPtr2 : %#x"), SharedPtr2.Get());
	UE_LOG(LogTemp, Warning, TEXT("SharedPtr3 : %#x"), SharedPtr3.Get());
	UE_LOG(LogTemp, Warning, TEXT("SharedPtr4 : %#x"), SharedPtr4.Get());

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	if (SharedPtr4.GetSharedReferenceCount() != 0)
	{
		SharedPtr4->SetSharedPtr(SharedPtr3);
	}

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	TSharedPtr<FPersonB> SharedPtr5 = MakeShared<FPersonB>(TEXT("호랑이"));
	TSharedPtr<FPersonB> SharedPtr6 = MakeShared<FPersonB>(TEXT("참새"));

	SharedPtr5->SetSharedPtr(SharedPtr6);
	SharedPtr6->SetSharedPtr(SharedPtr5);

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	TSharedPtr<FPersonD> SharedPtr7 = MakeShared<FPersonD>(TEXT("나비"));
	TSharedPtr<FPersonD> SharedPtr8 = MakeShared<FPersonD>(TEXT("표범"));

	FPersonD PersonD1(TEXT("돼지"));
	PersonD1.SetSharedPtr(SharedPtr7, SharedPtr8);

	UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	//TSharedPtr<FPersonE> SharedPtr9 = MakeShared<FPersonE>(TEXT("소"));
	//UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	//TSharedPtr<FPersonE> SharedPtr10 = MakeShared<FPersonE>(TEXT("하마"));
	//UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	//FPersonE PersonE1(TEXT("기린"));
	//UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	//PersonE1.SetSharedPtr(SharedPtr9, SharedPtr10);
	//UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	//UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	//TSharedPtr<FPersonF> SharedPtr11 = MakeShared<FPersonF>(TEXT("거북이"));
	//TSharedPtr<FPersonF> SharedPtr12 = MakeShared<FPersonF>(TEXT("치타"));

	//FPersonF PersonF1(TEXT("코끼리")); // 확인 해야 함.
	//PersonF1.SetWeakPtr(SharedPtr11, SharedPtr12);

	//UE_LOG(LogTemp, Warning, TEXT("SharedPtr12->GetName() : %s"), *SharedPtr12->GetName());

	//UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	//TSharedPtr<FPersonG> SharedPtr13 = MakeShared<FPersonG>(TEXT("코뿔소"));
	//TSharedPtr<FPersonG> SharedPtr14 = MakeShared<FPersonG>(TEXT("펭귄"));

	//SharedPtr13->SetWeakPtr(SharedPtr14);
	//SharedPtr13->GetSharedPtr();

	//SharedPtr14->SetWeakPtr(SharedPtr13);
	//SharedPtr14->GetSharedPtr();

	//UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	//TSharedPtr<FPersonH> SharedPtr15 = MakeShared<FPersonH>(TEXT("부엉이"));
	//TWeakPtr<FPersonH> WeakPtr15 = SharedPtr15;
	//UE_LOG(LogTemp, Warning, TEXT("SharedPtr15.GetSharedReferenceCount() : %d"), SharedPtr15.GetSharedReferenceCount());

	//UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	//TSharedPtr<FPersonI> SharedPtr16 = MakeShared<FPersonI>(TEXT("곰"));
	//TWeakPtr<FPersonI> WeakPtr16 = SharedPtr16;

	//if (SharedPtr16 = WeakPtr16.Pin())
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("SharedPtr16.GetSharedReferenceCount() : %d"), SharedPtr16.GetSharedReferenceCount());
	//}
	//UE_LOG(LogTemp, Warning, TEXT("SharedPtr16.GetSharedReferenceCount() : %d"), SharedPtr16.GetSharedReferenceCount());

	//UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	//TSharedPtr<FPersonI> SharedPtr16A = MakeShared<FPersonI>(TEXT("여우"));
	//TWeakPtr<FPersonI> WeakPtr16A(SharedPtr16A);
	//SharedPtr16A = nullptr;
	//if (WeakPtr16A.IsValid())
	//{

	//}

	//UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	//TSharedPtr<FPersonN> sharedPtr24 = MakeShared<FPersonN>(TEXT("고래"));
	//TSharedPtr<FPersonN> sharedPtr25 = MakeShared<FPersonN>(TEXT("상어"));
	//sharedPtr24->SetWeakPtr(sharedPtr25);
	//sharedPtr25->SetWeakPtr(sharedPtr24);
	//sharedPtr24->SetSharedPtr();
	//sharedPtr25->SetSharedPtr();
	//sharedPtr24->SetSharedPtr();
	//sharedPtr25.Reset();
	//// sharedPtr25->SetSharedPtr();

	//UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));

	//TArray<TSharedPtr<FPersonO>> vectors;
	//vectors.Add(MakeShared<FPersonO>(TEXT("칠면조")));
	//vectors.Add(MakeShared<FPersonO>(TEXT("앵무새")));

	//vectors[0]->SetWeakPtr(vectors[1]);
	//vectors[1]->SetWeakPtr(vectors[0]);

	//UE_LOG(LogTemp, Warning, TEXT("vectors[0].GetSharedReferenceCount() : %d"), vectors[0].GetSharedReferenceCount());
	//UE_LOG(LogTemp, Warning, TEXT("vectors[1].GetSharedReferenceCount() : %d"), vectors[1].GetSharedReferenceCount());

	//vectors[0]->SetSharedPtr();
	//vectors[1]->SetSharedPtr();

	//vectors.Pop();

	//UE_LOG(LogTemp, Warning, TEXT("vectors.Num() : %d"), vectors.Num());
	//UE_LOG(LogTemp, Warning, TEXT("vectors[0]->GetName() : %s"), *vectors[0]->GetName());

	//// vectors[0]->SetSharedPtr();
	//// vectors[1]->SetSharedPtr(); 

	//UE_LOG(LogTemp, Warning, TEXT("<------------------------------>"));


}

// Called every frame
void AChap34_TWeakPtr::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

