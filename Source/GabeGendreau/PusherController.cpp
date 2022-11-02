// Fill out your copyright notice in the Description page of Project Settings.


#include "PusherController.h"
// Include gameplay statics
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


void APusherController::BeginPlay()
{
	Super::BeginPlay();

	// Create an array of all target points in level
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), Waypoints);

	// Calls function to start character moving
	GoToNextWaypoint();
}

ATargetPoint* APusherController::GetNextWaypoint()
{
	// Generate a random number within the range of number of target points,
	// and set as the next point to be moved to
	auto index = FMath::RandRange(0, Waypoints.Num() - 1);
	return Cast<ATargetPoint>(Waypoints[index]);
}

void APusherController::GoToNextWaypoint()
{
	// Move the character to whatever point has been chosen
	MoveToActor(GetNextWaypoint());
}

// Acknowledges move completed successfully and advances character to next move
void APusherController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);

	// Commented out because no delay is desired for back and forth pusher - TimerHandle declaration is commented out
	// GetWorldTimerManager().SetTimer(TimerHandle, this, &APusherController::GoToRandomWaypoint, 0.0f, false);

	// Call function to move pusher character to next point
	APusherController::GoToNextWaypoint();
}