// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is udes to apply force to the tank.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	//max force per track in newtons
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 30000000; //assume 40 ton tank and 1g acceleration

private:
	UTankTrack();

	virtual void BeginPlay() override;

	void ApplySidwaysForce();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);
	
	void DriveTrack();

	float CurrentThrottle = 0;

};
