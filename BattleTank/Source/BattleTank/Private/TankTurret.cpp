// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTurret.h"


void UTankTurret::Rotate(float RelativeSpeed)
{
	//Move the Turret 
	//Given max speed
	//UE_LOG(LogTemp, Warning, TEXT(" TankTurret called %f "), DegreesPerSecond);

	auto RelativeSpeed1 = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto RotationChange = RelativeSpeed1 *MaxDegreesPerSecond *GetWorld()->DeltaTimeSeconds;
	auto RawNewRotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0,RawNewRotation, 0));
}

