// Copyright Epic Games, Inc. All Rights Reserved.


#include "BornToRaceGameModeBase.h"
#include "Kismet/GameplayStatics.h"

ABornToRaceGameModeBase::ABornToRaceGameModeBase()
{
	// Default values
	TotalLaps = 5; // setting the laps of the game
	CurrentLap = 0;
	PlayersLap = 0;
}

void ABornToRaceGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	TotalLaps = 5; // setting the laps of the game
	CurrentLap = 0;
	PlayersLap = 0;
}

void ABornToRaceGameModeBase::EndRace()
{
	// Implement the end-of-race logic (e.g., display a win screen or reset the game)
	UE_LOG(LogTemp, Warning, TEXT("Race Complete!"));
	// Additional end-game logic here, like stopping the player car or displaying a UI
}

void ABornToRaceGameModeBase::ResetLap()
{
	PlayersLap = 0;
}

int ABornToRaceGameModeBase::GetLap()
{
	return PlayersLap;
}

void ABornToRaceGameModeBase::AddLap(int LapToAdd)
{
	PlayersLap += LapToAdd;
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Player Lap: %d / %d"), PlayersLap));
	}

	// Check if the race is complete
	if (PlayersLap >= 5)
	{
		EndRace();
	}
}

