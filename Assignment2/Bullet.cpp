// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Mesh(
		TEXT("StaticMesh'/Game/StarterContent/Props/MaterialSphere.MaterialSphere'")
	);

	// initialise static mesh
	body = CreateDefaultSubobject<UStaticMeshComponent>("body");
	body->SetRelativeScale3D(FVector(0.2f, 0.2f, 0.2f));
	body->SetStaticMesh(Mesh.Object);
	this->RootComponent = body;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();
	body->SetSimulatePhysics(true);
	body->SetEnableGravity(true);
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FHitResult Hit;
	FVector StartLoc = this->GetActorLocation();
	FVector EndLoc = (Velocity * DeltaTime) + StartLoc;

	// Apply velocity to bullet
	SetActorLocation(EndLoc, true, &Hit);

	// If bullet collides with actor
	if (Hit.GetActor())
	{

		// If the object hit was a pawn
		if (Hit.GetActor()->IsA(ABaseAgent::StaticClass()))
		{

			ABaseAgent* Pawn = Cast<ABaseAgent>(Hit.GetActor());

			Pawn->InflictDamage(1);
			if (Pawn->GetHealth() <= 0)
			{
				Pawn->Destroy();
			}
		}

		// Destroy the bullet
		this->Destroy();
	}
	// Else no collision
	else
	{
		// Lower pitch velocity
		Velocity += FVector(0.f, 0.f, -100.f) * DeltaTime;
		// Increase distance travelled
		distance_travelled += travel_rate;
	}
	// If the bullet has been alive for too long without collision
	if (distance_travelled > max_range)
	{
		// Destroy the bullet
		this->Destroy(false, true);
	}
}

