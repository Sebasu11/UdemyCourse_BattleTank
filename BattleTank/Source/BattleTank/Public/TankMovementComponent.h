// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTrackTank;
/**
 * 
 */

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void IntentdMoveForward(float Throw);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialise(UTrackTank* LeftTrackToSet, UTrackTank* RightTrackToSet);
	
private:
	UTrackTank*	LeftTrack = nullptr;
	UTrackTank*	RightTrack = nullptr;
};
