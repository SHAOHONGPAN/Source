// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Collectable_Base.h"
#include "Collectable_Ammo.generated.h"

/**
 * This call inherits from the Collectable_Base class
 * 
 * This Class will give an entity ammo when it collides with the object
 */
UCLASS()
class ASSIGNMENT2_API ACollectable_Ammo : public ACollectable_Base
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ACollectable_Ammo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// A value to give a standard amount of ammo to whoever claims it
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
		int AmmoGiven = 30;
	// a value to give a dynamic amount of ammo based on the targets magazine size
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ammo")
		float MagazinesGiven = 1.f;
};
