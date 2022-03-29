// Copyright Epic Games, Inc. All Rights Reserved.

#include "BatteryPickupGameMode.h"
#include "BatteryPickupCharacter.h"
#include "BatteryPickup/BatteryPickupCharacter.h"
#include "BatteryPickup.h"
#include "Blueprint/UserWidget.h"
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

void ABatteryPickupGameMode::BeginPlay()
{
	Super::BeginPlay();
	ABatteryPickupCharacter* MyCharacter = Cast<ABatteryPickupCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
	SetCurrentState(EBatteryPlayState::EPlaying);
	if (MyCharacter)
	{
		// If our power is greater than needed to win, set the game's state to Won
		if (MyCharacter->GetCurrentPower() > PowerToWin)
		{
			SetCurrentState(EBatteryPlayState::EWon);
		}
		// if the character's power is positive
		else if (MyCharacter->GetCurrentPower() > 0)
		{
			// decrease the character's power using the decay rate
			MyCharacter->UpdatePower(DecayRate * (MyCharacter->GetInitialPower()));
		}
		else
		{
			SetCurrentState(EBatteryPlayState::EGameOver);
		}
	}
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

float ABatteryPickupGameMode::GetPowerToWin()
{
	return PowerToWin;
}

EBatteryPlayState ABatteryPickupGameMode::GetCurrentState() const
{
	return CurrentState;
}

void ABatteryPickupGameMode::SetCurrentState(EBatteryPlayState state)
{
	CurrentState = state;
}