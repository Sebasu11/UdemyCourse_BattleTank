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
	
public:

	ATank* GetControlledTank() const;


	
	
};
