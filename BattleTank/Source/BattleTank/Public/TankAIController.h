// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

protected:
	// How close the AI tank gets to the player
	UPROPERTY(EditAnywhere, Category = Setup)
	float AcceptanceRadius = 3000.f;

private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void SetPawn(APawn* InPawn) override;

	UTankAimingComponent* TankAimingComponent;

	UFUNCTION()
	void OnPossessedTankDeath();
};
