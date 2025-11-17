#include "PlayerCar.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "PaperSpriteComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Constructor
APlayerCar::APlayerCar()
{
    PrimaryActorTick.bCanEverTick = true;

    // Define the capsule component and set it as root
    CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Component"));
    SetRootComponent(CapsuleComp);
   
    // Define the spring arm component and attach to capsule
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm Component"));
    SpringArm->SetupAttachment(CapsuleComp);

    // Define the camera component and attach to spring arm
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
    Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);

    // Define the car sprite and attach to capsule
    CarSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Car Sprite"));
    CarSprite->SetupAttachment(CapsuleComp);

    // Initialize movement speeds
    MovementSpeed = BaseMovementSpeed; 
}

void APlayerCar::BeginPlay()
{
    Super::BeginPlay();
        
}

void APlayerCar::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Input setup
void APlayerCar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCar::MoveForward);
    PlayerInputComponent->BindAxis("Rotate", this, &APlayerCar::RotatePlayer);
}

// Move forward function
void APlayerCar::MoveForward(float Value)
{
      if (FMath::Abs(Value) > 0.0f)
    {
        float DeltaTime = GetWorld()->GetDeltaSeconds();

        // Move in the local Z-axis using MovementSpeed
        FVector Movement = FVector(0.0f, 0.0f, 1.0f) * MovementSpeed * Value * DeltaTime;
        AddActorLocalOffset(Movement, true);
    }
}

// Rotate function
void APlayerCar::RotatePlayer(float Value)
{
    if (FMath::Abs(Value) > 0.0f)
    {
        float DeltaTime = GetWorld()->GetDeltaSeconds();

        // Apply rotation on the Pitch axis (controls left/right turning)
        AddActorLocalRotation(FRotator(Value * RotationSpeed * DeltaTime, 0.0f, 0.0f));
    }
}

// Function to reduce speed temporarily
void APlayerCar::ReduceSpeed()
{
    // Halve the movement speed
    MovementSpeed = BaseMovementSpeed * 0.5f;
       
    // Set a timer to restore speed after 2 seconds
    GetWorld()->GetTimerManager().SetTimer(SpeedRestoreTimerHandle, this, &APlayerCar::RestoreSpeed, 2.0f, false);
}

// Function to restore original speed
void APlayerCar::RestoreSpeed()
{
    // Restore movement speed to original
    MovementSpeed = BaseMovementSpeed;

}







