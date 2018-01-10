// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TamkPlayerController.h"




ATank* ATamkPlayerController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}