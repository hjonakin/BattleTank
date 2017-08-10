// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "Tank.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

//called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		//move towards player
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO check that radius is in cm

		//aim towrds the [player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		//fire if ready
		ControlledTank->Fire(); //TODO limit firing rate
	}
}








