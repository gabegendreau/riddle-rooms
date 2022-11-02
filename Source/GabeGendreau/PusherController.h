// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Engine/World.h"
// Include target point class so we can use target points
#include "Runtime/Engine/Classes/Engine/TargetPoint.h"
#include "PusherController.generated.h"

/**
 * 
 */
UCLASS()
class GABEGENDREAU_API APusherController : public AAIController
{
	GENERATED_BODY()
	
public:
	void BeginPlay() override;

	void OnMoveCompleted(FAIRequestID, const FPathFollowingResult& Result) override;

private:
	UPROPERTY()
		TArray<AActor*> Waypoints;

	UFUNCTION()
		ATargetPoint* GetNextWaypoint();

	UFUNCTION()
		void GoToNextWaypoint();

// Commented out because function using timer is commented out, no delay used for back and forth pusher
//	FTimerHandle TimerHandle;
};