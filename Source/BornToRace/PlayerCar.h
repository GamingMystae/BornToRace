// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerCar.generated.h"

UCLASS()
class BORNTORACE_API APlayerCar : public APawn
{
	GENERATED_BODY()

public:
    // Constructor
    APlayerCar();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = "Speed")
    float BaseMovementSpeed = 1000.0f; // Store the base speed to restore after reduction

    UPROPERTY(EditAnywhere, Category = "Speed")
    float RotationSpeed = 200.0f; // Rotation speed
   
    // create the Components
    UPROPERTY(EditAnywhere, Category = "Components")
    class UCapsuleComponent* CapsuleComp;

    UPROPERTY(EditAnywhere, Category = "Components")
    class USpringArmComponent* SpringArm;

    UPROPERTY(EditAnywhere, Category = "Components")
    class UCameraComponent* Camera;

    UPROPERTY(EditAnywhere, Category = "Components")
    class UPaperSpriteComponent* CarSprite;

public:
    virtual void Tick(float DeltaTime) override;

    void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);

    // Input functions
    void MoveForward(float Value);
    void RotatePlayer(float Value);

    //function to reduce speed
    void ReduceSpeed();
   
private:
    
     void RestoreSpeed();
    float MovementSpeed;// speed used for reducing it
    FTimerHandle SpeedRestoreTimerHandle;  // Timer handle for speed restoration
};
