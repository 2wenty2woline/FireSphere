// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "FireSphereHUD.generated.h"

UCLASS()
class AFireSphereHUD : public AHUD
{
	GENERATED_BODY()

public:
	AFireSphereHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

