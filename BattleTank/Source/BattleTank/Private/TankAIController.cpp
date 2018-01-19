// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AIController not possesing a tank"));
	}
	else {
		//UE_LOG(LogTemp, Warning, TEXT("AIController BeginPlay %s"), *ControlledTank->GetName());
	}
	GetPlayerTank();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick( DeltaTime );
	//UE_LOG(LogTemp, Warning, TEXT("AIController tickinng"));
	if (GetControlledTank()) {
		
		//Move Barrel

		//Aim at the player location
		GetControlledTank()->AimtAt(GetPlayerTank()->GetActorLocation());

		//Fire 
	}
}

ATank* ATankAIController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {

	auto PlayerTankPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTankPawn) {
		UE_LOG(LogTemp, Warning, TEXT("AIController haven´t found a tank"));
		return nullptr;
	}
	else {
		//UE_LOG(LogTemp, Warning, TEXT("AIController  found a tank %s"), *PlayerTankPawn->GetName());
	}

	return  Cast<ATank>(PlayerTankPawn);
}

