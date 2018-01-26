// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TrackTank.generated.h"

/**
 * 
 */
UCLASS(meta =(BlueprintSpawnableComponent))
class BATTLETANK_API UTrackTank : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:

	UFUNCTION(BlueprintCallable, Category = Setup)
	void ThrottleRequest(float Throttle);

	//Max force pair track in newton
	UPROPERTY(EditDefaultsOnly, Category = TrackForce)
	float TrackMaxDrivingForce = 40000000;
	
};
