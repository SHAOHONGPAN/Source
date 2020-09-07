// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "EnemyCharacter_Base.generated.h"

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
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
