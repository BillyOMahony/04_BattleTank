// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Runtime/Engine/Classes/Engine/World.h"

void UTankBarrel::Elevate(float RelativeSpeed) {
	// Move the barrel the right amound this frame given a max elevation speed and frame time
	float ElevationSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);

	auto ElevationChange = ElevationSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}
