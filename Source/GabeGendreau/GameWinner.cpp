// Fill out your copyright notice in the Description page of Project Settings.


#include "GameWinner.h"

// Sets default values
AGameWinner::AGameWinner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a mesh to be used for the game winning target
	WinTargetMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GameWinMesh"));

	// Set root component
	RootComponent = WinTargetMesh;
}

// Called when the game starts or when spawned
void AGameWinner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameWinner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// remove hit registered
// pause game