// Fill out your copyright notice in the Description page of Project Settings.


#include "LastDoor.h"
// Include files for box components
#include "Components/BoxComponent.h"
#include "Engine.h"

// Sets default values
ALastDoor::ALastDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a new box component for detecting collisions
	DoorwayTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxTrig"));
	DoorwayTrigger->SetSimulatePhysics(true);
	DoorwayTrigger->SetNotifyRigidBodyCollision(true);

	// Add an OnHit collision event to the component
	DoorwayTrigger->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	DoorwayTrigger->OnComponentHit.AddDynamic(this, &ALastDoor::OnCompHit);

	// Create a cube to be used for the door to the next room
	FinalDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));

	// Set as root coponent
	RootComponent = FinalDoor;
}

// Called when the game starts or when spawned
void ALastDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALastDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// OnCompHit function - When collision box is hit call function on door to destroy it
void ALastDoor::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
	{
		// Only allow our scout camera cube to trigger the doorway opening
		if (OtherActor->GetName() == "Scout")
		{
			// Remove the door to the next room
			FinalDoor->DestroyComponent();
		}
	}
}