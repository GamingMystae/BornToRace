// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Oil.generated.h"

UCLASS()
class BORNTORACE_API AOil : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOil();

	// Called every frame
	virtual void Tick(float DeltaTime) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
private:
	//declare components box and sprite
	UPROPERTY(EditAnywhere, Category = "Component")
	class UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere, Category = "Component")
	class UPaperSpriteComponent* BlockSprite;

	//create function for triger the hit envent
	UFUNCTION()
	void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult);
	


	class APlayerCar* PlayerCar; // Reference to store the Playercar that collides with the block
	class AAIcar* AICar; // Reference to store the Playercar that collides with the block
};
