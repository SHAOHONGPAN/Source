// Fill out your copyright notice in the Description page of Project Settings.


#include "Collectable_Base.h"

// Sets default values
ACollectable_Base::ACollectable_Base()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// set the collectable to have the tag "Collectable"
	this->Tags.Add(FName("Collectable"));

	// define the collision component
	CollisionComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollisionComponent"));
	// definethe root component as the collison component
	RootComponent = this->CollisionComp;

	// define the static mesh
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	// attache the mesh to the collision component
	MeshComp->SetupAttachment(RootComponent);

	// select the default mesh to use, in this case a cylinder shape
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cylinder.Shape_Cylinder'"));
	DefaultMesh = MeshAsset.Object;
	// set the mesh of the static mesh component to the default mesh
	MeshComp->SetStaticMesh(DefaultMesh);
	// scale the default mesh to fit in the collision box
	MeshComp->SetWorldScale3D(DefaultMeshScale);
	// rotate the cylinder so that its on its side
	MeshComp->SetRelativeRotation(FRotator(0.f, 0.f, 90.f));

	// set the default material to usem in this case a plain white material
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Basic_Wall.M_Basic_Wall'"));
	DefaultMaterial = MaterialAsset.Object;
}

// Called when the game starts or when spawned
void ACollectable_Base::BeginPlay()
{
	Super::BeginPlay();

	// set the default material of the mesh ot the defined default material
	MeshComp->SetMaterial(0, DefaultMaterial);
	
	CollisionComp->OnComponentBeginOverlap.AddDynamic(this, &ACollectable_Base::WalkedOver);
}

// Called every frame
void ACollectable_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	this->RotateMesh();
}

/*
	* Funciton called when and object collides with the collision component
	*
	* This function will collect information of a collision into the various parameter
	* and then do something based on the results.
	* The OverlapComponent will be the collsion component of this classs
	* The Other Actor will be the actor that triggered the collsion even
	* The Other Comp will be the componet of the Other actor that triggered the collision
	*/
void ACollectable_Base::WalkedOver(class UPrimitiveComponent* OverlapComponent, class AActor*
	OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	
}

// funciton to make the mesh rotate
void ACollectable_Base::RotateMesh()
{
	MeshComp->AddRelativeRotation(RotationSpeed);
}