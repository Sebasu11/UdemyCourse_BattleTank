// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TamkPlayerController.h"




ATank* ATamkPlayerController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}

void ATamkPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController BeginPlay %s"), *ControlledTank->GetName());
	}
}
