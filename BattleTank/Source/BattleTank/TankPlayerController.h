// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"


class ATank;
/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;

	// Start the tank moving the barrel to aim towards the crosshair
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector &HitLocation) const;
	
	// Returns the direction the player is looking
	bool GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = .5f;
	
	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = .333333333f;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 100000.f;
	
};
