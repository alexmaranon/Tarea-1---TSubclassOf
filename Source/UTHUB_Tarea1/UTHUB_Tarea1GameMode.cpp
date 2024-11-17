// Copyright Epic Games, Inc. All Rights Reserved.

#include "UTHUB_Tarea1GameMode.h"
#include "UTHUB_Tarea1Character.h"
#include "UObject/ConstructorHelpers.h"

AUTHUB_Tarea1GameMode::AUTHUB_Tarea1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
