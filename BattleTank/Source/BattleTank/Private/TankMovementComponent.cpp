// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TrackTank.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::IntentdMoveForward(float Throw) {

	LeftTrack->ThrottleRequest(Throw);
	RightTrack->ThrottleRequest(Throw);

	UE_LOG(LogTemp, Warning, TEXT("Intend move forward thorw %f"), Throw);
}

void UTankMovementComponent::IntentdMoveRight(float Throw) {

	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->ThrottleRequest(Throw);
	RightTrack->ThrottleRequest(-Throw);

	UE_LOG(LogTemp, Warning, TEXT("Intend move forward thorw %f"), Throw);
}


void UTankMovementComponent::Initialise(UTrackTank * LeftTrackToSet, UTrackTank * RightTrackToSet)
{
	RightTrack = RightTrackToSet;
	LeftTrack = LeftTrackToSet;
}
