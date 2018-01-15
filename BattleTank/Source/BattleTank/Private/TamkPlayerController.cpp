// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TamkPlayerController.h"
#define OUT



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

void ATamkPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("ATamkPlayerController ticking"));
	AimTowardsCrosshair();
}

void ATamkPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) {
		return;
	}
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {
	
		//UE_LOG(LogTemp, Warning, TEXT("Hit Location %s"), *HitLocation.ToString());
	}
	 
}

bool ATamkPlayerController::GetSightRayHitLocation(FVector & OUTHitLocation) const
{
	//OUTHitLocation = FVector(1.0);
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	
	auto ScreenLocation = FVector2D(ViewportSizeX*CrosshairXLocation, ViewportSizeY*CrosshairYLocation);
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("ScreenLocation %s"), *LookDirection.ToString());

	}
	return true;
}

bool ATamkPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
	
}
