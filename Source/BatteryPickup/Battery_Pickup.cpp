// Fill out your copyright notice in the Description page of Project Settings.


#include "Battery_Pickup.h"

ABattery_Pickup::ABattery_Pickup()
{
	GetMesh()->SetSimulatePhysics(true);

	BatteryPower = 150.f;
}

void ABattery_Pickup::WasCollected_Implementation()
{
	// Use the base pickup behavior
	Super::WasCollected_Implementation();
	// Destroy the battery	
	Destroy();
}

float ABattery_Pickup::GetPower()
{
	return BatteryPower;
}
