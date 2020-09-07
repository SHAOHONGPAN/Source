// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter_Base.h"

// Sets default values
AEnemyCharacter_Base::AEnemyCharacter_Base()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// give it the enemy tag
	this->Tags.Add("Enemy");

	if (GetCapsuleComponent())
	{
		GetCapsuleComponent()->SetGenerateOverlapEvents(true);
	}

    PawnSensor = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Pawn Sensor"));
	PawnSensor->SensingInterval = .25f;
	PawnSensor->bOnlySensePlayers = false;
	PawnSensor->SetPeripheralVisionAngle(50.f);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkelMesh(
		TEXT("SkeletalMesh'/Engine/Tutorial/SubEditors/TutorialAssets/Character/TutorialTPP.TutorialTPP'")
	);
	
	GetMesh()->SetSkeletalMesh(SkelMesh.Object);

	if (GetMesh() != NULL)
	{

		GetMesh()->SetRelativeLocation(FVector(
			GetActorLocation().X, 
			GetActorLocation().Y, 
			GetActorLocation().Z - 90.f)
		);

		GetMesh()->SetRelativeRotation(FRotator(
			GetActorRotation().Pitch,
			GetActorRotation().Yaw - 90.f,
			GetActorRotation().Roll)
		);
	}
}

// Called when the game starts or when spawned
void AEnemyCharacter_Base::BeginPlay()
{
	Super::BeginPlay();
	AIController = Cast<AAIController>(this->GetController());
}

// Called every frame
void AEnemyCharacter_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    if(FocusTarget != NULL)
    {
		ShootTarget(FocusTarget);
    }
}

// Called to bind functionality to input
void AEnemyCharacter_Base::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Shoots projectile infront of the pawn
void AEnemyCharacter_Base::ShootProjectile()
{
	long CurrTime = duration_cast<milliseconds>(
		system_clock::now().time_since_epoch()).count();

	// If cooldown is over
	if (CurrTime - PreviousTime > CooldownPeriod)
	{
		PreviousTime = CurrTime;
		const UWorld* world = this->GetWorld();

		if (world)
		{
			FActorSpawnParameters sparams;
			sparams.Owner = this;
			sparams.Instigator = this;

			//Spawn bullet
			ABullet* bullet = GetWorld()->SpawnActor<ABullet>(
				this->GetActorLocation() + 
					(this->GetActorForwardVector() * 200.f) + 
					(this->GetActorUpVector() * 100.f),
				this->GetBaseAimRotation(),
				sparams
			);

			// Apply velocity
			FVector Velocity = GetActorForwardVector() * 5000.f;
			bullet->Velocity = FVector(Velocity);
		}
	}
}

// Shoots projectile at target
void AEnemyCharacter_Base::ShootTarget(APawn* Target)
{
	FaceTarget(Target);
	ShootProjectile();
}

// Rotates to face target pawn
void AEnemyCharacter_Base::FaceTarget(APawn* Target)
{
	if (Target != NULL)
	{
		FRotator FaceTargetRotation = UKismetMathLibrary::FindLookAtRotation(
			GetActorLocation(), 
			Target->GetActorLocation()
		);

		FRotator FaceTargetYaw = FRotator(
			GetActorRotation().Pitch,
			FaceTargetRotation.Yaw,
			GetActorRotation().Roll
		);

		SetActorRotation(FaceTargetYaw);
	}
}

//Inflict damage to pawn by removing damage from health
void AEnemyCharacter_Base::InflictDamage(int damage)
{
	Health -= damage;
}

// Returns health of agent
int AEnemyCharacter_Base::GetHealth()
{
	return Health;
}

// Sets new focus target when a new enemy is seen
void AEnemyCharacter_Base::OnSeePawn(APawn* OtherPawn)
{
	FocusTarget = OtherPawn;
}

void AEnemyCharacter_Base::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	PawnSensor->OnSeePawn.AddDynamic(this, &AEnemyCharacter_Base::OnSeePawn);
}

// Moves to target's location
void AEnemyCharacter_Base::MoveToTarget(APawn* Target)
{
	if (Target != NULL)
	{
		AIController->MoveToLocation(Target->GetActorLocation());
	}
}

