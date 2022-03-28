// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "Battery_Pickup.generated.h"

/**
 * 
 */
UCLASS()
class BATTERYPICKUP_API ABattery_Pickup : public APickup
{
	GENERATED_BODY()
	
public:
	//sets the default values for this actor's properties
	ABattery_Pickup();

	/** Override the WasCollected function - use Implementation because it's a Blueprint Native Event */
	void WasCollected_Implementation() override;

protected:
	/** Set the amount of power the battery gives to the character */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
		float BatteryPower;

public:
	float GetPower();
};
