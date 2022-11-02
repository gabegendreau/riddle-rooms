// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GabeGendreauGameMode.generated.h"

UCLASS(minimalapi)
class AGabeGendreauGameMode : public AGameModeBase
{
	GENERATED_BODY()

		// Declare we will be overriding BeginPlay from base class
		virtual void BeginPlay() override;

public:
	AGabeGendreauGameMode();

protected:

	// Create a subclass for our HUD class
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Riddle", Meta = (BlueprintProtected = "true"))
		TSubclassOf<class UUserWidget> PlayerHUDClass;

	// Declare a pointer to a widget object we can use in Unreal
	UPROPERTY()
		class UUserWidget* CurrentWidget;
};



