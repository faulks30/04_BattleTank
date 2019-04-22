// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("ERROR: No AI tanks"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI possessed tank: %s"), *ControlledTank->GetName())
	}
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("ERROR: AI cant find player tank"))
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI found player tank: %s"), *PlayerTank->GetName())
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//TODO move toward player
	AimTowardsPlayerTank();
	//TODO fire if ready
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn);
}

void ATankAIController::AimTowardsPlayerTank()
{
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
}