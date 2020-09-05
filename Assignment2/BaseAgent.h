// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AIController.h"
#include "AIModule.h"
#include "Perception/PawnSensingComponent.h"
#include "BaseAgent.generated.h"

UCLASS()
class ASSIGNMENT2_API ABaseAgent : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseAgent();

private:
	AAIController* AIController;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Awareness)
		UPawnSensingComponent* PawnSensor;

	UFUNCTION()
		void OnSeePawn(APawn* OtherPawn);

	void PostInitializeComponents() override;

};
