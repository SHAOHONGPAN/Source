// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AIController.h"
#include "AIModule.h"
#include <chrono>
#include "Kismet/KismetMathLibrary.h"
#include "Bullet.h"
#include "Perception/PawnSensingComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "EnemyCharacter_Base.generated.h"

using namespace std;
using namespace chrono;

UCLASS()
class ASSIGNMENT2_API AEnemyCharacter_Base : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter_Base();

	// maximum ammount of health the character can have
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicStats")
		float MaxHealth = 100.f;
	// current amount of health the character has
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicStats")
		float CurrentHealth = 100.f;
	// current amount of bullets the character has
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicStats")
		int CurrentAmmo = 20;
private:
	AAIController* AIController;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

    int Health = 100;
    // Time between attacks
    int CooldownPeriod = 400;
	// Previous time an event was executed at
	long PreviousTime = 0;

    APawn* FocusTarget;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Awareness)
		UPawnSensingComponent* PawnSensor;

	UFUNCTION()
		void OnSeePawn(APawn* OtherPawn);

    // Returns amount of health agent has left
	int GetHealth();

	void PostInitializeComponents() override;

    // Inflicts damage / lowers lives of pawn
	void InflictDamage(int damage);

    // Shoots a projectile
	void ShootProjectile();

	// Shoots target pawn
	void ShootTarget(APawn* Target);

	// Faces target pawn
	void FaceTarget(APawn* Target);

	// Moves to target's location
	void MoveToTarget(APawn* Target);
};
