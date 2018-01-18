// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//Move the barrel 
	//Given max speed
	//UE_LOG(LogTemp, Warning, TEXT(" TankBarrel called %f "), DegreesPerSecond);

	auto RelativeSpeed1 = FMath::Clamp<float>(RelativeSpeed,-1,+1);
	auto ElevationChange = RelativeSpeed1 *MaxDegreesPerSecond *GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}
