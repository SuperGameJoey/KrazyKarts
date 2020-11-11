// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GoKart.generated.h"

UCLASS()
class KRAZYKARTS_API AGoKart : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AGoKart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void UpdateLocationFromVelocity(float DeltaTime);
	void ApplyRotation(float DeltaTime);
	FVector GetAirResistance();
	FVector GetRollingResistance();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// Mass of the car in kilograms (kg)
	UPROPERTY(EditAnywhere)
	float Mass = 1000;
	
	UPROPERTY(EditAnywhere)
	float MaxDrivingForce = 10000;

	// amount of air resistance to apply, kg/m
	UPROPERTY(EditAnywhere)
	float DragCoefficient = 16; // 10,000 / 25*25

	// amount of rolling resistance to apply, Higher means more resistance
	UPROPERTY(EditAnywhere)
	float RollingResistanceCoefficient = 0.015; // Tires on Concrete

	// Size of the turning circle in meters
	UPROPERTY(EditAnywhere)
	float TurningRadius = 50;

	float Throttle;
	float SteeringThrow;
	
	FVector Velocity;
	void MoveForward(float Value);
	void MoveRight(float Value);
	
};
