// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExitTrigger.generated.h"

UCLASS()
class GABEGENDREAU_API AExitTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AExitTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Declare a static mesh for door
	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* ExitDoor;

	// Declare UBoxComponent variable for game end trigger
	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* GameEndTrigger;

	// Declare function to register when component is hit, used for scout cube exiting level
	UFUNCTION()
		void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
