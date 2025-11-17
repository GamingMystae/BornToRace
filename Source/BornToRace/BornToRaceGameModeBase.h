// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BornToRaceGameModeBase.generated.h"

/**
 * Game mode base class for lap counting in the car race game
 */
UCLASS()
class BORNTORACE_API ABornToRaceGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	// Constructor
	ABornToRaceGameModeBase();

	// Total number of laps
	int TotalLaps;

	// Tracks the current lap of the player
	UPROPERTY(VisibleAnywhere, BlueprintReadonly, Category = "Settings")
	int CurrentLap;

	UFUNCTION(BlueprintCallable, Category = "Score")
	void ResetLap();
	
	//we call it from blueprint code
	UFUNCTION(BlueprintCallable)
	int GetLap();

	// Called when the player completes a lap
	UFUNCTION(BlueprintCallable, Category = "Race")
	static void AddLap(int LapToAdd);
			
	// when the laps completed ending the race
	UFUNCTION(BlueprintCallable, Category = "Race")
	static void EndRace();

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Variable to store the score
	inline static int PlayersLap;
};
