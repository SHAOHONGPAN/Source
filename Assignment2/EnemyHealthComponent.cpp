// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyHealthComponent.h"

// Sets default values for this component's properties
UEnemyHealthComponent::UEnemyHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnemyHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	EnemyTotalHealth = 100.0f;
	// ...

}


// Called every frame
void UEnemyHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

float UEnemyHealthComponent::UpdataRemainHealth(float ReduceBloodVolume)
{
	RemainHealingPoint = EnemyTotalHealth - ReduceBloodVolume;
	
	return RemainHealingPoint;
}

