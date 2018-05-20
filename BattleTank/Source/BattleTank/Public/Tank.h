// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

	// Returns current health as a percentage of starting health, between 0 and 1
	UFUNCTION(BlueprintPure, Category = Health)
	float GetHealthPercent() const;

protected:
	virtual void BeginPlay() override;	

private:

	ATank();

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	int32 StartingHealth = 100.f;

	UPROPERTY(VisibleAnywhere)
	int32 CurrentHealth = StartingHealth;
};
