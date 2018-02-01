// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "Tank.h"
#include "TamkPlayerController.h"
#define OUT



ATank* ATamkPlayerController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}

void ATamkPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto AimComponent = GetControlledTank()->FindComponentByClass<UTankAimingComponent>();
	if (ensure(AimComponent))
	{
		FoundAimingComponent(AimComponent);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player controller cant find aiming component"))
	}
	auto ControlledTank = GetControlledTank();
	if (!ensure(ControlledTank)) {
		//UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"));
	}
	else {
		//UE_LOG(LogTemp, Warning, TEXT("PlayerController BeginPlay %s"), *ControlledTank->GetName());
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
	if (!ensure(GetControlledTank())) {
		return;
	}
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {
	
		//UE_LOG(LogTemp, Warning, TEXT("Hit Location %s"), *HitLocation.ToString());
		//This method was created in the Tank file 
		GetControlledTank()->AimtAt(HitLocation);
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
		//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation %s"), *OUTHitLocation.ToString());

		//LineTrace
		GetLookVectorHitLocation(LookDirection, OUTHitLocation);

	}
	return true;
}

bool ATamkPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
	
}

bool ATamkPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(HitResult,StartLocation,EndLocation,ECollisionChannel::ECC_Visibility))
	{
		HitLocation=HitResult.Location;
		return true;
	}
	HitLocation = FVector(0);
	return false;
}
