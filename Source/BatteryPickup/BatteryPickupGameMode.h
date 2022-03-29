// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BatteryPickupGameMode.generated.h"

// enum to store the current state of game play
UENUM(BlueprintType)
enum class EBatteryPlayState : uint8
{
	EPlaying,
	EGameOver,
	EWon,
	EUnknown
};

UCLASS(minimalapi)
class ABatteryPickupGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ABatteryPickupGameMode();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:
	/** The rate at which the character loses power */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Battery Pickup", Meta = (BlueprintProtected = true))
		float DecayRate;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Battery Pickup", Meta = (BlueprintProtected = true))
		float PowerToWin;
public:
	UFUNCTION(BlueprintPure, category = "Battery Pickup")
		float GetPowerToWin();


protected:
	/** The Widget class to use for our HUD screen */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Battery Pickup", Meta = (BlueprintProtected = true))
		TSubclassOf<class UUserWidget> HUDWidgetClass;
	/** The instance of the HUD */
	UPROPERTY()
		class UUserWidget* CurrentWidget;
	private:
	//set the current state
	EBatteryPlayState CurrentState;

public:
	UFUNCTION(BlueprintPure, Category = "Battery Pickup")
		EBatteryPlayState GetCurrentState() const;

	void SetCurrentState(EBatteryPlayState state);
};