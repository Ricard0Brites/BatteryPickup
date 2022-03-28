// Copyright Epic Games, Inc. All Rights Reserved.

#include "BatteryPickup.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE( FDefaultGameModuleImpl, BatteryPickup, "BatteryPickup" );

ABatteryPickup::ABatteryPickup()
{

}

void ABatteryPickup::BeginPlay()
{
	Super::BeginPlay();
}

void ABatteryPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
