// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ensure(ControlledTank != nullptr)) return;
	//UE_LOG(LogTemp, Warning, TEXT("AI controlled pawn is : %s"), *ControlledTank->GetName());

	auto PlayerTank = GetPlayerTank();
	if (!ensure(PlayerTank != nullptr)) return;	
	UE_LOG(LogTemp, Warning, TEXT("AI found player tank : %s"), *PlayerTank->GetName());
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (GetPlayerTank())
	{
		// TODO Move towards the player

		// Aim towards the player		
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());

		//Fire if ready
	}
	
}

ATank * ATankAIController::GetPlayerTank() const
{	
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
