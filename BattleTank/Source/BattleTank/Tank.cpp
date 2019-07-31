// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine/World.h"
#include "TankBarrel.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "TankMovementComponent.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s DONKEY::Tank CONSTRUCTOR called from CPP"),*TankName);

	// No need to protect points as added at construction
	//TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));	
	//TankMovementComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("Movement Component"));

	//TankAimingComponent = Cast<UTankAimingComponent>(GetComponentByClass(UTankAimingComponent::StaticClass()));
	//TankMovementComponent = Cast<UTankMovementComponent>(GetComponentByClass(UTankMovementComponent::StaticClass()));
}

void ATank::AimAt(FVector HitLocation)
{
	//auto OurTankName = GetName();
	if (!TankAimingComponent) { return; }
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();	// Needed to BP begin play to run

	auto TankName = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s DONKEY::Tank BEGINPLAY called from CPP"),*TankName);

	//Test_Test();
}

void ATank::Test_Test_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Test_Test from CPP"));
}

void ATank::Fire()
{
	auto bIsReloaded = (GetWorld()->GetRealTimeSeconds() - LastFrieTime > ReloadTimeInSeconds);
	if (Barrel && bIsReloaded)
	{
		//SpawnProjectile
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, Barrel->GetSocketLocation("Projectile"), Barrel->GetSocketRotation("Projectile"));	
		Projectile->LaunchPRojectile(LaunchSpeed);		
		LastFrieTime = GetWorld()->GetRealTimeSeconds();
	}
}
