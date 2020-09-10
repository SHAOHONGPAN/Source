//// Fill out your copyright notice in the Description page of Project Settings.


#include "Boss.h"
#include "EnemyHealthComponent.h"
#include "AIController.h"
#include "nest.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
// Sets default values
ABoss::ABoss()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	HealthCom = CreateDefaultSubobject<UEnemyHealthComponent>("Health");
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkelMesh(
		TEXT("SkeletalMesh'/Engine/Tutorial/SubEditors/TutorialAssets/Character/TutorialTPP.TutorialTPP'")
	);
	GetMesh()->SetSkeletalMesh(SkelMesh.Object);

	if (GetMesh() != NULL)
	{

		GetMesh()->SetRelativeLocation(FVector(
			GetActorLocation().X,
			GetActorLocation().Y,
			GetActorLocation().Z - 90.f)
		);

		GetMesh()->SetRelativeRotation(FRotator(
			GetActorRotation().Pitch,
			GetActorRotation().Yaw - 90.f,
			GetActorRotation().Roll)
		);
	}
	//this->RootComponent = HealthCom;
}

// Called when the game starts or when spawned
void ABoss::BeginPlay()
{
	Super::BeginPlay();
	AIController = Cast<AAIController>(this->GetController());
	TArray<AActor*> ArryActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), Anest::StaticClass(), ArryActors);
	for (int32 i = 0; i < ArryActors.Num(); i++)
	{
		NestLocation = Cast<Anest>(ArryActors[i])->GetActorLocation();

	}
	//GetAllActorsOfClass1(GetWorld(),UClass::StaticClass(), TargetPonit);
	AIController->MoveToLocation(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn()->GetActorLocation());
	GEngine->AddOnScreenDebugMessage(0, 10, FColor::Red, "Begineplaye");

}

// Called every frame
void ABoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (RemainingHealth <= 50)
	{
		UAIBlueprintHelperLibrary::CreateMoveToProxyObject(GetWorld(), this, UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetPawn()->GetActorLocation());
	}
	else {

		UAIBlueprintHelperLibrary::CreateMoveToProxyObject(GetWorld(), this, NestLocation);
	}

}

// Called to bind functionality to input
void ABoss::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ABoss::UpdataHealth(float Health)
{

	RemainingHealth = HealthCom->UpdataRemainHealth(Health);

	return RemainingHealth;
}


