// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

<<<<<<< HEAD
class UTankBarrel;//Forward declaration -> Allows to reference the utank and use the dependencies
class UTankTurret;//Forward declaration -> Allows to reference the utank and use the dependencies
=======
>>>>>>> 08bd16f0103c98e3845f17fa6bd5aaccae39ba99

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

<<<<<<< HEAD
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void SetTurretReference(UTankTurret* TurretToSet);

=======
>>>>>>> 08bd16f0103c98e3845f17fa6bd5aaccae39ba99
	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

<<<<<<< HEAD
	void AimAt(FVector HitLocation, float LaunchSpeed);

	

private:
	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
=======
	void AimAt(FVector HitLocation);

		
>>>>>>> 08bd16f0103c98e3845f17fa6bd5aaccae39ba99
	
};
