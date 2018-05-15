// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	TankAimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
}

void ATankAIController::Tick(float DeltaTime)
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) {
		return;
	}

	// Move towards player
	MoveToActor(PlayerTank, AcceptanceRadius);

	// Aim towards player and fire
	FVector PlayerTankLocation = PlayerTank->GetActorLocation();

	TankAimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	TankAimingComponent->AimAt(PlayerTankLocation);

	if (TankAimingComponent->GetFiringState() == EFiringState::Locked) {
		TankAimingComponent->Fire();
	}
}