// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GabeGendreauGameMode.h"
#include "GabeGendreauHUD.h"
#include "GabeGendreauCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "GabeGendreau.h"
#include "Blueprint/UserWidget.h"

// Overrides BeginPlay to include adding widget for riddles and timer to viewport
void AGabeGendreauGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Create a pointer for the character
	AGabeGendreauCharacter* MyCharacter = Cast<AGabeGendreauCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

	// Make sure there is a viable HUD class
	if (PlayerHUDClass != nullptr)
	{
		// Create the widget that will be added
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerHUDClass);

		// Verify widget before adding to viewport
		if (CurrentWidget != nullptr)
		{
			// Add widget to the viewport
			CurrentWidget->AddToViewport();
		}
	}
}

AGabeGendreauGameMode::AGabeGendreauGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGabeGendreauHUD::StaticClass();
}
