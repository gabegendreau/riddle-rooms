// Fill out your copyright notice in the Description page of Project Settings.


#include "ExitTrigger.h"
// Include files for box components
#include "Components/BoxComponent.h"
#include "Engine.h"
//#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
AExitTrigger::AExitTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a new box component for detecting collisions
	GameEndTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("GameEndTrigger"));
	GameEndTrigger->SetSimulatePhysics(true);
	GameEndTrigger->SetNotifyRigidBodyCollision(true);

	// Add an OnHit collision event to the component
	GameEndTrigger->BodyInstance.SetCollisionProfileName("OverlapAll");
	GameEndTrigger->OnComponentHit.AddDynamic(this, &AExitTrigger::OnCompHit);

	// Create a cube to be used for the door to the next room
	ExitDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Exit Door Mesh"));
}

// Called when the game starts or when spawned
void AExitTrigger::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AExitTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// OnCompHit function - When collision box is hit by the scout cube the game is over
void AExitTrigger::OnCompHit(UPrimitiveComponent * HitComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
	{
		ExitDoor->DestroyComponent();
	}
}