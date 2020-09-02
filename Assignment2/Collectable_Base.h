// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Collectable_Base.generated.h"

/**
 * This is the base class for creating the various collectable items in the game
 * It initializes a Box Collider as the root component
 * And it initializes a Static Mesh Component attached to the root component
 * It also adds the tag "Collectable" to the actor
 * It also has a virtual "WalkedOver" collision function that is trigger by the 
   OnBeginOverlap event of the Box Collider
 */
UCLASS()
class ASSIGNMENT2_API ACollectable_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACollectable_Base();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Collision component for detecting overlap with the collectable
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UBoxComponent* CollisionComp;
	// Static mesh component for the visual aspect of the collectable
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* MeshComp;

	// Default Scale for default mesh to fit in the collision box
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default Values")
		FVector DefaultMeshScale = FVector(0.5f, 0.5f, 0.1f);
	// default rate for the mesh to rotate
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default Values")
		FRotator RotationSpeed = FRotator(0.f, 1.f, 0.f);
	// Default Static mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default Values")
		UStaticMesh* DefaultMesh;
	// default material to apply to the static mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Default Values")
		UMaterial* DefaultMaterial;

	/*
	* Funciton called when and object collides with the collision component
	* 
	* This function will collect information of a collision into the various parameter
	* and then do something based on the results.
	* The OverlapComponent will be the collsion component of this classs
	* The Other Actor will be the actor that triggered the collsion even
	* The Other Comp will be the componet of the Other actor that triggered the collision
	*/
	UFUNCTION()
		virtual void WalkedOver(class UPrimitiveComponent* OverlapComponent, class AActor*
			OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
			bool bFromSweep, const FHitResult& SweepResult);

	// funciton to make the mesh rotate
	UFUNCTION()
		void RotateMesh();
};
