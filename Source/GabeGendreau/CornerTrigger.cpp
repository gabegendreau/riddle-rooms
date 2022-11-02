// Fill out your copyright notice in the Description page of Project Settings.


#include "CornerTrigger.h"
#include "Engine.h"

// Sets default values
ACornerTrigger::ACornerTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Start the sphere-in-corner bools as false
	bFirstSphere = false;
	bSecondSphere = false;

	// Start off with the door set to not destroyed yet
	doorDestroyed = false;

	// Create a static mesh for door to next room
	CornerDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));

	// Create first collision box and set attributes
	CornerOneBox = CreateDefaultSubobject<UBoxComponent>(TEXT("First Box Component"));
	CornerOneBox->SetCollisionProfileName(TEXT("Trigger"));

	// Add overlap begin and end events to first collision box
	CornerOneBox->OnComponentBeginOverlap.AddDynamic(this, &ACornerTrigger::OnOverlapBegin);
	CornerOneBox->OnComponentEndOverlap.AddDynamic(this, &ACornerTrigger::OnOverlapEnd);

	// Create second collision box and set attributes
	CornerTwoBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Second Box Component"));
	CornerTwoBox->SetCollisionProfileName(TEXT("Trigger"));

	// Add overlap begin and end events to second collision box
	CornerTwoBox->OnComponentBeginOverlap.AddDynamic(this, &ACornerTrigger::OnOverlapBegin);
	CornerTwoBox->OnComponentEndOverlap.AddDynamic(this, &ACornerTrigger::OnOverlapEnd);

	// Set up hierarchy of objects
	RootComponent = CornerDoor;
	CornerOneBox->SetupAttachment(CornerDoor);
	CornerTwoBox->SetupAttachment(CornerDoor);
}

// Called when the game starts or when spawned
void ACornerTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACornerTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!doorDestroyed)
	{
		if (bFirstSphere && bSecondSphere)
		{
			ACornerTrigger::DestroyCornerDoor();
		}
	}

}

// Overlap begin event for collision box
void ACornerTrigger::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		// Keep track of if spheres are in boxes by setting boolean variables
		if (OverlappedComp == CornerOneBox) {
			bFirstSphere = true;
		}
		if (OverlappedComp == CornerTwoBox) {
			bSecondSphere = true;
		}
	}
}

// Overlap end event for collision box
void ACornerTrigger::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		// Keep track of if spheres are out of boxes by setting boolean variables
		if (OverlappedComp == CornerOneBox) {
			bFirstSphere = false;
		}
		if (OverlappedComp == CornerTwoBox) {
			bSecondSphere = false;
		}
	}
}

// Remove door to next room
void ACornerTrigger::DestroyCornerDoor()
{
	// Set the door as destroyed
	doorDestroyed = true;

	// Destroy door
	CornerDoor->DestroyComponent();
}