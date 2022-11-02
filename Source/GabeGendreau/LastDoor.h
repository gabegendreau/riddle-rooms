// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LastDoor.generated.h"

UCLASS()
class GABEGENDREAU_API ALastDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALastDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Declare a UBoxComponent variable
	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* DoorwayTrigger;

	// Declare a static mesh for door
	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* FinalDoor;

	// Declare function to register when component is hit
	UFUNCTION()
		void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
