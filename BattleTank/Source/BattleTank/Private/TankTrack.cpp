// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "SprungWheel.h"
#include "SpawnPoint.h"

TArray<class ASprungWheel*> UTankTrack::GetWheels() const
{
	TArray<class ASprungWheel*> WheelsArray;
	TArray<USceneComponent*> Children;
	GetChildrenComponents(true, Children);
	for(USceneComponent* Child : Children)
	{
		auto SpawnPointChild = Cast<USpawnPoint>(Child);
		if (!SpawnPointChild) { continue; }

		auto SprungWheel = SpawnPointChild->GetSprungWheel();
		if (!SprungWheel) { continue; }
		
		WheelsArray.Add(SprungWheel);
	}
	return WheelsArray;
}

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankTrack::DriveTrack(float CurrentThrottle)
{
	auto ForceApplied = CurrentThrottle * TrackMaxDrivingForce;
	auto Wheels = GetWheels();
	auto ForcePerWheel = ForceApplied / Wheels.Num();
	for(ASprungWheel* Wheel : Wheels)
	{
		Wheel->AddDrivingForce(ForcePerWheel);
	}
}

void UTankTrack::SetThrottle(float Throttle)
{
	float CurrentThrottle = FMath::Clamp<float>(Throttle, -1, 1);
	DriveTrack(CurrentThrottle);
}
