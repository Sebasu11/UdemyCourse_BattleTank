// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
# include "TankBarrel.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	//auto OurTankName = GetOwner()->GetName();
	//auto BarrelLocation = Barrel->GetComponentLocation().ToString();
	// Checks tank name, where is it pointing where is the barrel located
	//UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s from %s"), *OurTankName, *HitLocation.ToString(),*BarrelLocation);
	//UE_LOG(LogTemp, Warning, TEXT(" Firing at %f "), LaunchSpeed);

	if (!Barrel) {
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
			MoveBarrelTowards(AimDirection);
		}
	//If no solution found do nothing 
		//UE_LOG(LogTemp, Warning, TEXT(" no solution found do nothing "));
		}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection )
{
	//Difference between current barrel location and AimDirection
	auto tankName = GetOwner()->GetName();
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	//UE_LOG(LogTemp, Warning, TEXT("%s Tank  AimRotator at %s "),*tankName, *AimAsRotator.ToString());

	//Move Barrrel the right amount of frame
	Barrel->Elevate(5);

	//Given the max elevation speed and the frame line
}

