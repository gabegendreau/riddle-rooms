// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Public/EngineGlobals.h"
#include "CornerTrigger.generated.h"

UCLASS()
class GABEGENDREAU_API ACornerTrigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACornerTrigger();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Declare a bool variable for first sphere in corner
	UPROPERTY(VisibleAnywhere, Category = "Corner Trigger")
		bool bFirstSphere;

	// Declare a bool variable for second sphere in corner
	UPROPERTY(VisibleAnywhere, Category = "Corner Trigger")
		bool bSecondSphere;

	// Declare a bool variable for if door is destroyed yet
	// this will prevent an attempt to destroy an object that no longer exists
	UPROPERTY(VisibleAnywhere, Category = "Corner Trigger")
		bool doorDestroyed;

	// Declare a UBoxComponent for first collision box
	UPROPERTY(VisibleAnywhere, Category = "Corner Trigger")
		class UBoxComponent* CornerOneBox;

	// Declare a UBoxComponent for second collision box
	UPROPERTY(VisibleAnywhere, Category = "Corner Trigger")
		class UBoxComponent* CornerTwoBox;

	// Declare a static mesh for door
	UPROPERTY(VisibleAnywhere, Category = "Corner Trigger")
		class UStaticMeshComponent* CornerDoor;

	// Declare the overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// Declare the overlap end function
	UFUNCTION()
		void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);

	// Declare function to destroy door to next room
	UFUNCTION()
		void DestroyCornerDoor();

};
