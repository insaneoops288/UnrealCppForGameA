// Fill out your copyright notice in the Description page of Project Settings.


#include "Chap35_TypeCasting.h"

// Sets default values
AChap35_TypeCasting::AChap35_TypeCasting()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChap35_TypeCasting::BeginPlay()
{
	Super::BeginPlay();

	double doubleValue1 = 3.14159265358979;
	int32 intValue1 = (int32)doubleValue1;
	int32 intValue2 = int32(doubleValue1);

	double DoubleValue2 = 3.14159265;
	int32* IntPtr2 = (int32*)&DoubleValue2; 
	// int32* IntPtr3 = static_cast<int32*>(&DoubleValue2); 


	UE_LOG(LogTemp, Warning, TEXT("DoubleValue2 : %lf"), DoubleValue2);
	UE_LOG(LogTemp, Warning, TEXT("IntPtr2 : %d"), *IntPtr2);

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));
	

	double DoubleValue3 = 3.14159265;
	int32 IntValue3 = static_cast<int32>(DoubleValue3);
	// int32 IntValue4 = dynamic_cast<int32>(DoubleValue3);

	UE_LOG(LogTemp, Warning, TEXT("DoubleValue3 : %lf"), DoubleValue3);
	UE_LOG(LogTemp, Warning, TEXT("IntValue3 : %d"), IntValue3);

	float FloatValue5 = 3.14159265f;
	int32 IntValue5 = 200;
	// int32* IntPtr5 = static_cast<int32*>(FloatValue5);
	IntValue5 = static_cast<int32>(FloatValue5);

	UE_LOG(LogTemp, Warning, TEXT("FloatValue5 : %f"), FloatValue5);
	UE_LOG(LogTemp, Warning, TEXT("IntValue5 : %f"), IntValue5);

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	FAnimal1* Animal1 = new FLion1(20, 15);
	FLion1* Lion1 = static_cast<FLion1*>(Animal1); 
	Lion1->ShowInfo();

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	FAnimal1* Animal2 = new FAnimal1(20);
	FLion1* Lion2 = static_cast<FLion1*>(Animal2); 

	Lion2->ShowInfo();

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	FAnimal1* Animal3 = new FLion1(20, 15);

	// FLion1* Lion3 = dynamic_cast<FLion1*>(Animal3);
	// Lion3->ShowInfo();

	FAnimal1* Animal4 = new FAnimal1(20);
	// FLion1* Lion4 = dynamic_cast<FLion1*>(Animal4); 
	// Lion4->ShowInfo();

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	FLion1* Lion5 = new FLion1(20, 20);
	FAnimal1* Animal5 = dynamic_cast<FAnimal1*>(Lion5); 
	Animal5->ShowInfo();

	FAnimal1* Animal6 = new FLion1(20, 15);
	//FLion* Lion6 = dynamic_cast<FLion*>(Animal6); // 에러! 
	// Lion6->ShowInfo();

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	FAnimalA1* AnimalA1 = new FTiger1(20, 15);
	// FTiger1* Tiger1 = dynamic_cast<FTiger1*>(AnimalA1); // 컴파일 실패 
	//Tiger1->showInfo();

	FTiger1* Tiger2 = new FTiger1(20, 20);
	FAnimalA1* AnimalA2 = dynamic_cast<FAnimalA1*>(Tiger2); // 컴파일 성공
	AnimalA2->ShowInfo();

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	float* floatPtr3 = new float(3.14159265);
	int* IntPtr3 = reinterpret_cast<int*>(floatPtr3); //컴파일 성공했지만? 

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	const TCHAR* CharPtr5 = TEXT("Hello");

	// TCHAR* CharPtr6 = TEXT("Hello"); 
	TCHAR* CharPtr6 = const_cast<TCHAR*>(CharPtr5); 

	// CharPtr6[0] = 'U';
	UE_LOG(LogTemp, Warning, TEXT("CharPtr6[0] : %c"), CharPtr6[0]);

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	FAnimalB1* AnimalB1;
	FCat1* Cat1 = new FCat1();
	AnimalB1 = static_cast<FAnimalB1*>(Cat1);
	AnimalB1->SetInfo();

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	delete Cat1;

	FAnimalB1* AnimalB2 = new FAnimalB1();
	FCat1* Cat2;
	Cat2 = static_cast<FCat1*>(AnimalB2);
	Cat2->SetInfo();

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	delete Cat2;

	FDog1* Dog1 = new FDog1();
	FBird1* Bird1 = new FBird1();
	// Bird1 = static_cast<FBird1*>(Dog1); 
	// Bird1 = reinterpret_cast<FBird1*>(Dog1);

	delete Dog1;
	delete Bird1;

	FAnimalC1* Cow1 = new FCow1();
	Cow1->Eat();

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	// FFox* Fox1 = dynamic_cast<FFox*>(Cow1); 
	// Fox1->Eat();
	delete Cow1;
	// delete Fox1;
	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	FAnimalC1* Cow2 = new FCow1();
	Cow2->Eat();

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	// FCow1* Cow3 = dynamic_cast<FCow1*>(Cow2); 
	// Cow3->Eat();

	delete Cow2;

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));

	// delete Cow3;

	UE_LOG(LogTemp, Warning, TEXT("<-------------------------------->"));



}

// Called every frame
void AChap35_TypeCasting::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

