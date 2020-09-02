// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Collectable_Base.h"
#include "Collectable_Health.generated.h"

/**
 * This call inherits from the Collectable_Base class
 * 
 * This Class will restore some of the entity's health when it collides with the object
 */
UCLASS()
class ASSIGNMENT2_API ACollectable_Health : public ACollectable_Base
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ACollectable_Health();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// A value to give a standard amount of health to whoever claims it
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
		int HealthGiven = 50;
	// a value to give a dynamic amount of health based on the targets maximum health
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
		float PercentHealthGiven = 0.5f;
};
