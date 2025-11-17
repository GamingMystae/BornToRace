// Fill out your copyright notice in the Description page of Project Settings.


#include "Oil.h"
#include "Components/BoxComponent.h"
#include "PaperSpriteComponent.h"
#include "PlayerCar.h"
#include <Kismet/GameplayStatics.h>
#include "AIcar.h"

// Sets default values
AOil::AOil()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    //define the block component and set it as root component
    BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Capsule Component"));
    SetRootComponent(BoxComponent);

    //define the sprite component and attached it in box component
    BlockSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Oil Sprite"));
    BlockSprite->SetupAttachment(BoxComponent);

}

// Called when the game starts or when spawned
void AOil::BeginPlay()
{
	Super::BeginPlay();
    // Assign PlayerCar with a reference to the player character
    PlayerCar = Cast<APlayerCar>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

    //always need to to trigger the overlapp event in the begin play
    BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AOil::OverlapBegin);
	
    // Assign AICar with a reference to the AAcar
    AICar = Cast<AAIcar>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
}

// Called every frame
void AOil::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOil::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult)
{
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Red, TEXT("OverlapBegin triggered."));
    }

    if (OtherActor && OtherActor == PlayerCar)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Green, TEXT("Overlap with PlayerCar detected."));
        }

        // Call ReduceSpeed directly
        PlayerCar->ReduceSpeed();
    }

    if (OtherActor && OtherActor == AICar)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 1.5f, FColor::Green, TEXT("Overlap with AICar detected.")); // Corrected to AICar

        }

        // Call ReduceSpeed directly
        AICar->ReduceSpeed();
    }
}
