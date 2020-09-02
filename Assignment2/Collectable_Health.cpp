// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectable_Health.h"

// Sets default values
ACollectable_Health::ACollectable_Health()
{
	// add the tag "Ammo" so that it can be wasily identified
	this->Tags.Add(FName("Health"));

	// set the default material to usem in this case a plain white material
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'"));
	DefaultMaterial = MaterialAsset.Object;
	// set the default material of the mesh ot the defined default material
	//this->MeshComp->GetStaticMesh()->SetMaterial(0, DefaultMaterial);
}

// Called when the game starts or when spawned
void ACollectable_Health::BeginPlay()
{
	Super::BeginPlay();

	//CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &ACollectable_Base::WalkedOver);
}

// Called every frame
void ACollectable_Health::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}