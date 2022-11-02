// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RealLastDoor.generated.h"

UCLASS()
class GABEGENDREAU_API ARealLastDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARealLastDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Declare UBoxComponent variable for scout trigger
	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* ScoutHomeTrigger;

	// Declare a static mesh for door
	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* OutsideDoor;

	// Declare function to register when component is hit
	UFUNCTION()
		void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

private:
	// Boolean var to hold state of door
	bool doorDestroyed;
};
