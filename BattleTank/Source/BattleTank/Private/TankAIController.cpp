// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	FVector PlayerTankLocation;
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank) {

		// Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius);

		// Aim towards player and fire
		PlayerTankLocation = PlayerTank->GetActorLocation();
		ControlledTank->AimAt(PlayerTankLocation);
		ControlledTank->Fire(); // TODO Limit Fire Rate
	}
}