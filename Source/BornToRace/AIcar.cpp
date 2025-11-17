// Fill out your copyright notice in the Description page of Project Settings.


#include "AIcar.h"
#include "Components/BoxComponent.h" 
#include "PaperSpriteComponent.h" 
#include "SplinePath.h"
#include "Components/SplineComponent.h"

// Sets default values
AAIcar::AAIcar()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//define the caspule component and set it as root component
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Capsule Component"));
	SetRootComponent(BoxComp);

	//define the carsprite and attached to the Capsule component
	CarSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Car Sprite"));
	CarSprite->SetupAttachment(BoxComp);

	// Initialize movement speeds
	MovementSpeed = Speed;
}

// Called when the game starts or when spawned
void AAIcar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAIcar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (SplinePath && SplinePath->SplineComponent)
	{
		// Move along the spline based on speed and delta time
		DistanceAlongSpline += Speed * DeltaTime;

		// Get the location and rotation along the spline at the current distance
		FVector NewLocation = SplinePath->SplineComponent->GetLocationAtDistanceAlongSpline(DistanceAlongSpline, ESplineCoordinateSpace::World);
		FRotator NewRotation = SplinePath->SplineComponent->GetRotationAtDistanceAlongSpline(DistanceAlongSpline, ESplineCoordinateSpace::World);

		// Update the AICar's position and rotation
		SetActorLocation(NewLocation);
		SetActorRotation(NewRotation);
	}
}
// Function to reduce speed temporarily
void AAIcar::ReduceSpeed()
{
	// Halve the movement speed
	MovementSpeed = Speed * 0.5f;

	// Set a timer to restore speed after 2 seconds
	GetWorld()->GetTimerManager().SetTimer(SpeedRestoreTimerHandle, this, &AAIcar::RestoreSpeed, 2.0f, false);
}

// Function to restore original speed
void AAIcar::RestoreSpeed()
{
	// Restore movement speed to original
	MovementSpeed = Speed;

}

