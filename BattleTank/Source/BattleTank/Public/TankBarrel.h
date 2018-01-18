// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
		void Elevate(float RelativeSpeed);
private:

	UPROPERTY(EditAnyWhere, Category = Setup)
	float MaxDegreesPerSecond = 10;

	UPROPERTY(EditAnyWhere, Category = Setup)
	float MaxElevationDegrees = 40;

	UPROPERTY(EditAnyWhere, Category = Setup)
	float MinElevationDegrees = 0;
};
