// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//Forward declarations
class UTankBarrel;

class UTankAimingComponent;

class UTankTurret;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurretReference(UTankTurret* TurretToSet);

	void AimtAt(FVector HitLocation);

<<<<<<< HEAD
	UFUNCTION(BlueprintCallable, Category = Firing)
		void Fire();



protected:

	UTankAimingComponent* TankAimingComponent = nullptr;


=======
protected:
	UTankAimingComponent* TankAimingComponent = nullptr;
>>>>>>> 08bd16f0103c98e3845f17fa6bd5aaccae39ba99
private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 4000.0f; // 40 m/s
	
};

