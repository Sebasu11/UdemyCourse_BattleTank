// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::Initialise(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}


void UTankAimingComponent::AimAt(FVector HitLocation)
{
	//auto OurTankName = GetOwner()->GetName();
	//auto BarrelLocation = Barrel->GetComponentLocation().ToString();
	// Checks tank name, where is it pointing where is the barrel located
	//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s"), *OurTankName, *HitLocation.ToString(),*BarrelLocation);
	//UE_LOG(LogTemp, Warning, TEXT(" Firing at %f "), LaunchSpeed);

	if (!ensure(Barrel)) {
		//UE_LOG(LogTemp, Warning, TEXT(" No Barrel"));
	return; }

	//const UObject * WorldContextObject;
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	//FVector EndLocation;

	// Calculation outLaunchVelocity
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, HitLocation, LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace);
		if (bHaveAimSolution)
		{
			auto AimDirection = OutLaunchVelocity.GetSafeNormal();
			//UE_LOG(LogTemp, Warning, TEXT(" Aiming at %s "), *AimDirection.ToString());

			//auto Time = GetWorld()->GetTimeSeconds();
			//UE_LOG(LogTemp, Warning, TEXT("%f: Aim solution found "), Time);

			MoveBarrelTowards(AimDirection);
		}
		else {
	//If no solution found do nothing 
		auto Time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f: no aim solution found "),Time);
		}
		}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection )
{
	if (!ensure(Barrel && Turret)) { return; }
	//Difference between current barrel location and AimDirection
	auto tankName = GetOwner()->GetName();
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	//UE_LOG(LogTemp, Warning, TEXT("%s Tank  AimRotator at %s "),*tankName, *AimAsRotator.ToString());

	//Move Barrrel and Turret the right amount of frame
	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);

	//Given the max elevation speed and the frame line
}

void UTankAimingComponent::Fire()
{
	if (!ensure(Barrel && ProjectileBlueprint	)) { return; }
	//auto Time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("%f Tank fires"),Time);
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;

	if (isReloaded) {

		// Spawn Projectile at the socket location
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
			ProjectileBlueprint,
			Barrel->GetSocketLocation(FName("Projectile")),
			Barrel->GetSocketRotation(FName("Projectile")));

		Projectile->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
	else {
		//UE_LOG(LogTemp, Warning, TEXT(" Nor Barrel")); return;
	}
}


