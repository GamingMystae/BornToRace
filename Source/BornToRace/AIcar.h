// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AIcar.generated.h"

UCLASS()
class BORNTORACE_API AAIcar : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAIcar();
	
	//	Called every frame
	virtual void Tick(float DeltaTime) override;
		
	//finction for reducing speed
	void ReduceSpeed();

protected:
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	//set the components
	UPROPERTY(EditAnywhere, Category = "BoxComponent")
	class UBoxComponent* BoxComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpriteComponent")
	class UPaperSpriteComponent* CarSprite;

	// for following the spline path
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	class ASplinePath* SplinePath;  // Reference to the spline path

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float Speed = 500.f;  // Movement speed on the spline
	

private:

	float MovementSpeed;// speed used for reducing it
	void RestoreSpeed();
	FTimerHandle SpeedRestoreTimerHandle;  // Timer handle for speed restoration
	float DistanceAlongSpline;
};
