// Fill out your copyright notice in the Description page of Project Settings.


#include "RealLastDoor.h"
// Include files for box components
#include "Components/BoxComponent.h"
#include "Engine.h"

// Sets default values
ARealLastDoor::ARealLastDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a new box component for detecting collisions
	ScoutHomeTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("ScoutBoxTrig"));
	ScoutHomeTrigger->SetSimulatePhysics(true);
	ScoutHomeTrigger->SetNotifyRigidBodyCollision(true);

	// Add an OnHit collision event to the component
	ScoutHomeTrigger->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	ScoutHomeTrigger->OnComponentHit.AddDynamic(this, &ARealLastDoor::OnCompHit);

	// Create a cube to be used for the door to the next room
	OutsideDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));

	// Set as root coponent
	RootComponent = OutsideDoor;

	// Keep track of state of door, if it has been destroyed we want to prevent attempting to do anything with it
	ARealLastDoor::doorDestroyed = false;
}

// Called when the game starts or when spawned
void ARealLastDoor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARealLastDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// OnCompHit function - When collision box is hit call function on door to destroy it
void ARealLastDoor::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
	{
			ARealLastDoor::OutsideDoor->DestroyComponent();
	}
}