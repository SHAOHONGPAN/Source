// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAgent.h"

// Sets default values
ABaseAgent::ABaseAgent()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnSensor = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Pawn Sensor"));
	PawnSensor->SensingInterval = .25f;
	PawnSensor->bOnlySensePlayers = false;
	PawnSensor->SetPeripheralVisionAngle(50.f);
}

// Called when the game starts or when spawned
void ABaseAgent::BeginPlay()
{
	Super::BeginPlay();
	AIController = Cast<AAIController>(this->GetController());
}

// Called every frame
void ABaseAgent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseAgent::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseAgent::OnSeePawn(APawn* OtherPawn)
{
	AIController->MoveToLocation(OtherPawn->GetActorLocation());
}

void ABaseAgent::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	PawnSensor->OnSeePawn.AddDynamic(this, &ABaseAgent::OnSeePawn);
}

