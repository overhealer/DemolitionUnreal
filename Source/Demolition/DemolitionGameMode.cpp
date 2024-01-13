// Copyright Epic Games, Inc. All Rights Reserved.

#include "DemolitionGameMode.h"
#include "DemolitionCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADemolitionGameMode::ADemolitionGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
