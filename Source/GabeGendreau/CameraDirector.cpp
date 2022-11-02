// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraDirector.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACameraDirector::ACameraDirector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraDirector::BeginPlay()
{
	Super::BeginPlay();
    PrimaryActorTick.bCanEverTick = true;

    cameraChange = false;

    UE_LOG(LogTemp, Warning, TEXT("Camera Director BeginPlay"));	
}

// Called every frame
void ACameraDirector::Tick(float DeltaTime) {

    Super::Tick(DeltaTime);

    const float TimeBetweenCameraChange = 2.0f;
    const float SmoothBlendTime = 0.75f;
    TimeToNextCameraChange -= DeltaTime;

    // This logic keeps back and forth movement between cameras on track 
    if (cameraChange)
    {
        if (TimeToNextCameraChange <= 0.0f) {
            TimeToNextCameraChange += TimeBetweenCameraChange;

            APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);

            if (OurPlayerController) {

                if (CameraTwo && (OurPlayerController->GetViewTarget() == CameraOne)) {
                    OurPlayerController->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
                }
                else if (CameraOne) {
                    OurPlayerController->SetViewTargetWithBlend(CameraOne, SmoothBlendTime);
                }


            }
        }
        // Allows camera movement to happen again when previos movement is done
        else {
            cameraChange = false;
            TimeToNextCameraChange = 0.0f;
        }
    }
}

// Called every frame
/**
***** This code was from original tutorial and was used to move camera on timer at game start *****
* 
void ACameraDirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    const float TimeBetweenCameraChanges = 2.0f;
    const float SmoothBlendTime = 0.75f;
    TimeToNextCameraChange -= DeltaTime;
    if (TimeToNextCameraChange <= 0.0f)
    {
        TimeToNextCameraChange += TimeBetweenCameraChanges;

        // Find the actor that handles control for the local player.
        APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
        if (OurPlayerController)
        {
            if ((OurPlayerController->GetViewTarget() != CameraOne) && (CameraOne != nullptr))
            {
                // Cut instantly to camera one.
                OurPlayerController->SetViewTarget(CameraOne);
            }
            else if ((OurPlayerController->GetViewTarget() != CameraTwo) && (CameraTwo != nullptr))
            {
                // Blend smoothly to camera two.
                OurPlayerController->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
            }
        }
    }

}
*/

// Sets everything proper when new movement begins
void ACameraDirector::cameraGo()
{
    cameraChange = true;
    TimeToNextCameraChange = 0.0f;

    UE_LOG(LogTemp, Warning, TEXT("cameraGo function activated!"));
}