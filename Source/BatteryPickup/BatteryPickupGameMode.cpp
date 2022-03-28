// Copyright Epic Games, Inc. All Rights Reserved.

#include "BatteryPickupGameMode.h"
#include "BatteryPickupCharacter.h"
#include "BatteryPickup/BatteryPickupCharacter.h"
#include <Kismet/GameplayStatics.h>
#include "UObject/ConstructorHelpers.h"

ABatteryPickupGameMode::ABatteryPickupGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
		PrimaryActorTick.bCanEverTick = true;
	}
	// base decay rate
	DecayRate = 0.01f;
}

void ABatteryPickupGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
		// Check that we are using the battery collector character
		ABatteryPickupCharacter* MyCharacter = Cast<ABatteryPickupCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	if (MyCharacter)
	{
		// if the character's power is positive
		if (MyCharacter->GetCurrentPower() > 0)
		{
			// decrease the character's power using the decay rate
			MyCharacter->UpdatePower(-DeltaTime * DecayRate * (MyCharacter->GetInitialPower()));
		}
	}
}
