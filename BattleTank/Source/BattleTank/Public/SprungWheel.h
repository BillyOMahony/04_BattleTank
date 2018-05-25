// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsConstraintComponent.h"
#include "Components/SphereComponent.h"
#include "SprungWheel.generated.h"

UCLASS()
class BATTLETANK_API ASprungWheel : public AActor
{
GENERATED_BODY()
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Sets default values for this actor's properties
	ASprungWheel();
	
	void SetupConstraint();

	void AddDrivingForce(float ForceMagnitude);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Components
	UPROPERTY(VisibleAnywhere, Category = Component)
	USphereComponent* Wheel = nullptr;

	UPROPERTY(VisibleAnywhere, Category = Component)
	USphereComponent* Axle = nullptr;

	UPROPERTY(VisibleAnywhere, Category = Component)
	UPhysicsConstraintComponent* PhysicsConstraint = nullptr;

	UPROPERTY(VisibleAnywhere, Category = Component)
	UPhysicsConstraintComponent* AxleWheelConstraint = nullptr;

	float ForceMagnitude = 0.f;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
