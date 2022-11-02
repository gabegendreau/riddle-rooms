// Fill out your copyright notice in the Description page of Project Settings.


#include "LightSwitchTrigger.h"
#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"
// include draw debug helpers header file
#include "DrawDebugHelpers.h"

// Sets default values
ALightSwitchTrigger::ALightSwitchTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Adjusting this float will change the brightness of the point light component - Default: 3000.0f
	LightIntensity = 3000.0f;

	// Create Point Light and set attributes
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Point Light"));
	PointLight->Intensity = LightIntensity;
	PointLight->bVisible = true;
	RootComponent = PointLight;

	// Create Collision Sphere and set attributes
	LightSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Light Sphere Component"));
	LightSphere->InitSphereRadius(300.0f);
	LightSphere->SetCollisionProfileName(TEXT("Trigger"));
	LightSphere->SetupAttachment(RootComponent);

	// Add overlap begin and end events to collision sphere
	LightSphere->OnComponentBeginOverlap.AddDynamic(this, &ALightSwitchTrigger::OnOverlapBegin);
	LightSphere->OnComponentEndOverlap.AddDynamic(this, &ALightSwitchTrigger::OnOverlapEnd);
}

// Called when the game starts or when spawned
void ALightSwitchTrigger::BeginPlay()
{
	Super::BeginPlay();

	// Uncommenting line of code below this will add a debug sphere to your light/switch set
	// DrawDebugSphere(GetWorld(), GetActorLocation(), 300.0f, 50, FColor::Green, true, -1, 0, 2);
	
	// Switches the point light on and off
	PointLight->ToggleVisibility();
	
}

// Called every frame
void ALightSwitchTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Overlap begin event for collision sphere
void ALightSwitchTrigger::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}

// Overlap end event for collision sphere
void ALightSwitchTrigger::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}

// Calls a function to turn the light on and off
void ALightSwitchTrigger::ToggleLight()
{
	PointLight->ToggleVisibility();
}