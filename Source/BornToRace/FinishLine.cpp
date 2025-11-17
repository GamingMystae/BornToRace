// Fill out your copyright notice in the Description page of Project Settings.


#include "FinishLine.h"
#include "Components/BoxComponent.h"
#include "PaperSpriteComponent.h"
#include "PlayerCar.h"
#include "BornToRaceGameModeBase.h"


// Sets default values
AFinishLine::AFinishLine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	SetRootComponent(MyBox);

	FinishLine = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Finish Line"));
	FinishLine->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AFinishLine::BeginPlay()
{
    Super::BeginPlay();

    // always need this in the begin play for trigger the collision
    MyBox->OnComponentBeginOverlap.AddDynamic(this, &AFinishLine::OnCollision);

}
// Called every frame
void AFinishLine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AFinishLine::OnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor->IsA(APlayerCar::StaticClass())) // Check if the other actor is PlayerCar
    {
        // Display a message on the screen to confirm overlap
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Player Car overlapped the finish line"));
        }
            ABornToRaceGameModeBase* BornToRaceGameModeBase = Cast<ABornToRaceGameModeBase>(GetWorld()->GetAuthGameMode());
            if (BornToRaceGameModeBase)
            {
                // Increment the current lap
                BornToRaceGameModeBase->AddLap(1);

                // Check if the race is over
                if (BornToRaceGameModeBase->CurrentLap >= BornToRaceGameModeBase->TotalLaps)
                {
                    // Destroy the player car
                    OtherActor->Destroy();
                    // End the race and open the win or lose level 
                    // *********** To enter the win or lose
                    BornToRaceGameModeBase->EndRace();
                }
            }
    }
}

