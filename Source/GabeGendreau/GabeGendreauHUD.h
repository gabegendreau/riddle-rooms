// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include <string>
#include "GabeGendreauHUD.generated.h"

UCLASS()
class AGabeGendreauHUD : public AHUD
{
	GENERATED_BODY()

public:
	AGabeGendreauHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;
};

