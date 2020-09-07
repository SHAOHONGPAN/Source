// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseAgent.h"
#include "Bullet.generated.h"

UCLASS()
class ASSIGNMENT2_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

	// Base velocity of bullet
	UPROPERTY(EditAnywhere)
		FVector Velocity = FVector(100.f);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Max range bullet can travel
	float max_range = 3000.0;

	// Distance bullet has travelled
	float distance_travelled = 0.f;

	// Rate bullet travels at
	float travel_rate = 10.f;

	// Static mesh body of bullet
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* body;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
