// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/PlayerController.h"

#include "TamkPlayerController.generated.h"//Generated always the last one
class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATamkPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, category= "Setup")
	ATank* GetControlledTank() const;
	
private:


	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	// Start moving the barrel
	void AimTowardsCrosshair() ;

	bool GetSightRayHitLocation(FVector& OUTHitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;



};
