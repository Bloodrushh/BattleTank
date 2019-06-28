// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{
	auto ForceAplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRootComp = Cast <UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRootComp->AddForceAtLocation(ForceAplied, ForceLocation);
}

