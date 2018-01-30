// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TrackTank.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::IntentdMoveForward(float Throw) {

	LeftTrack->ThrottleRequest(Throw);
	RightTrack->ThrottleRequest(Throw);

	//UE_LOG(LogTemp, Warning, TEXT("Intend move forward thorw %f"), Throw);
}

void UTankMovementComponent::IntentdMoveRight(float Throw) {

	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->ThrottleRequest(Throw);
	RightTrack->ThrottleRequest(-Throw);

	//UE_LOG(LogTemp, Warning, TEXT("Intend move Right thorw %f"), Throw);
}


void UTankMovementComponent::Initialise(UTrackTank * LeftTrackToSet, UTrackTank * RightTrackToSet)
{
	RightTrack = RightTrackToSet;
	LeftTrack = LeftTrackToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	//auto TankName = GetOwner()->GetName();
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();//.ToString();
	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	//UE_LOG(LogTemp, Warning, TEXT("%s Vectoring to %s "), *TankName, *AIForwardIntention);
	
	IntentdMoveForward(ForwardThrow);
}
