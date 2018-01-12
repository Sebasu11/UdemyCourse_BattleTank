// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"

#include "TamkPlayerController.generated.h"//Generated always the last one

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATamkPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:

	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	// Start moving the barrel
	void AimTowardsCrosshair() ;

	bool GetSightRayHitLocation(FVector& OUTHitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.3333;

};
