// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OnHitComponent.generated.h"

UCLASS()
class GABEGENDREAU_API AOnHitComponent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOnHitComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Declare a UBoxComponent variable
	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* MyComp;

	// Declare a static mesh for door
	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* TargetDoor;

	// Declare function to register when component is hit
	UFUNCTION()
		void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
