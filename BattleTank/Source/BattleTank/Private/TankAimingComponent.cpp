// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "TankBarrel.h"
#include "TankTurret.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true; //TODO should this really tick?

	// ...
}

void UTankAimingComponent::Initialise(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet)
{
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel)
	{
		UE_LOG(LogTemp, Warning, TEXT("Elephant: NO TANK BARREL"))
		return;
	}
	FVector LaunchVelocity; // Out param
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool AimSolutionFound = UGameplayStatics::SuggestProjectileVelocity(
		this, 
		LaunchVelocity, 
		StartLocation, 
		HitLocation, 
		LaunchSpeed, 
		false, 
		0.f, 
		0.f, 
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (AimSolutionFound) {
		FVector AimDirection = LaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);
		auto Time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%s %f: Aim Solution found %s"), *GetOwner()->GetName() , Time, *AimDirection.ToString());
	}
	else {
		auto Time = GetWorld()->GetTimeSeconds();
		//UE_LOG(LogTemp, Warning, TEXT("%f: No Aim Solution found"), Time);
	}
}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{

	if (!Barrel || !Turret) { return; }

	// Work out the difference between the current barrel rotation and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	
	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);
}
