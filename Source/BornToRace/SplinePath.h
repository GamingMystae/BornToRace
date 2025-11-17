// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SplinePath.generated.h"

UCLASS()
class BORNTORACE_API ASplinePath : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASplinePath();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Spline component to define the path
	UPROPERTY(EditAnywhere, Category = "Components")
	class USplineComponent* SplineComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	

};
