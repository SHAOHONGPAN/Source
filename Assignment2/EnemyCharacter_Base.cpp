// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter_Base.h"

// Sets default values
AEnemyCharacter_Base::AEnemyCharacter_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// give it the enemy tag
	this->Tags.Add("Enemy");

	if (GetCapsuleComponent())
	{
		GetCapsuleComponent()->SetGenerateOverlapEvents(true);
	}
}

// Called when the game starts or when spawned
void AEnemyCharacter_Base::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AEnemyCharacter_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AEnemyCharacter_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

