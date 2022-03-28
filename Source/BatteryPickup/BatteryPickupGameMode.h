// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BatteryPickupGameMode.generated.h"

UCLASS(minimalapi)
class ABatteryPickupGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABatteryPickupGameMode();

	virtual void Tick(float DeltaTime) override;

protected:
	/** The rate at which the character loses power */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = true))
		float DecayRate;
};



