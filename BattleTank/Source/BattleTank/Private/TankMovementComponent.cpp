// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TrackTank.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::IntentdMoveForward(float Throw) {

	LeftTrack->ThrottleRequest(Throw);
	RightTrack->ThrottleRequest(Throw);

	UE_LOG(LogTemp, Warning, TEXT("Intend move forward thorw %f"), Throw);
}

void UTankMovementComponent::Initialise(UTrackTank * LeftTrackToSet, UTrackTank * RightTrackToSet)
{

	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	RightTrack = RightTrackToSet;
	LeftTrack = LeftTrackToSet;
}
