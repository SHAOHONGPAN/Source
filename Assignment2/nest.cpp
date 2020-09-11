// Fill out your copyright notice in the Description page of Project Settings.


#include "nest.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
Anest::Anest()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	St = CreateDefaultSubobject<UStaticMeshComponent>("St");
	this->RootComponent = St;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SkelMesh(
		TEXT("SkeletalMesh'/Engine/Tutorial/SubEditors/TutorialAssets/Character/TutorialTPP.TutorialTPP'"));
	St->SetStaticMesh(SkelMesh.Object);
	bool AA = false;
	St->SetCanEverAffectNavigation(AA);
}

// Called when the game starts or when spawned
void Anest::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void Anest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

