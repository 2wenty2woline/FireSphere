// Copyright Epic Games, Inc. All Rights Reserved.

#include "FireSphereGameMode.h"
#include "FireSphereHUD.h"
#include "FireSphereCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFireSphereGameMode::AFireSphereGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFireSphereHUD::StaticClass();
}
