// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameWinner.generated.h"

UCLASS()
class GABEGENDREAU_API AGameWinner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameWinner();

	// Declare a static mesh for our game winning target
	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* WinTargetMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
