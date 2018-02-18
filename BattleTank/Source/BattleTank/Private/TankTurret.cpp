// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void UTankTurret::Rotate(float RelativeSpeed) { 
	float RotationSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
	
	auto RotationChange = RotationSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	
	auto NewRotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(0, NewRotation, 0));
}