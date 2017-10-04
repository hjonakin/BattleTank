// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"


/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:

	//how close can the ai get to the player
	UPROPERTY(EditDefaultsOnly, Category ="Setup") //consider EditDefaultsOnly
	float AcceptanceRadius = 8000; //80 meters


private:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	
};
