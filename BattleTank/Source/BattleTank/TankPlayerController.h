// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


class UTankAimingComponent;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = Setup)
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

private:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	virtual void SetPawn(APawn* InPawn) override;

	UFUNCTION()
	void OnPossessedTankDeath();

	// Start the tank moving the barrel to aim towards the crosshair
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector &HitLocation) const;
	
	// Returns the direction the player is looking
	bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = .5f;
	
	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = .333333333f;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 100000.f;

	UTankAimingComponent* AimingComponent;



};
