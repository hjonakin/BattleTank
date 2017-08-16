// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

//forward declarations
class UTankBarrel; 
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:



	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

private:
	// Sets default values for this pawn's properties
	ATank();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Setup") 
	TSubclassOf<AProjectile> ProjectileBlueprint;
	
	//TODO remove after moved into aiming component
	UPROPERTY(EditAnywhere, Category = "Firing") //allows change on all instances of tanks
	float LaunchSpeed = 4000;

	UPROPERTY(EditDefaultsOnly, Category = "Firing") //allows change only on Tank Blueprint for ALL Tanks
	float ReloadTimeInSeconds = 3;

	//local reference for spawning projectile
	UTankBarrel* Barrel = nullptr; //TODO remove

	double LastFireTime = 0;



protected:
	
};
