// Fill out your copyright notice in the Description page of Project Settings.


#include "OnHitComponent.h"
// Include files for box components
#include "Components/BoxComponent.h"
#include "Engine.h"

// Sets default values
AOnHitComponent::AOnHitComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a new box component for detecting collisions
	MyComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	MyComp->SetSimulatePhysics(true);
	MyComp->SetNotifyRigidBodyCollision(true);

	// Add an OnHit collision event to the component
	MyComp->BodyInstance.SetCollisionProfileName("BlockAllDynamic");
	MyComp->OnComponentHit.AddDynamic(this, &AOnHitComponent::OnCompHit);

	// Create a cube to be used for the door to the next room
	TargetDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));

	// Set as root coponent
	RootComponent = MyComp;
}

// Called when the game starts or when spawned
void AOnHitComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOnHitComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// OnCompHit function - When collision box is hit call function on door to destroy it
void AOnHitComponent::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != NULL) && (OtherActor != this) && (OtherComp != NULL))
	{
		// Remove the door to the next room
		TargetDoor->DestroyComponent();
	}
}