// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Classes/Engine/Blueprint.h"
#include "BatteryPickupCharacter.generated.h"

UCLASS(config=Game)
class ABatteryPickupCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Collection sphere */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Pickups, meta = (AllowPrivateAccess = "true"))
		class USphereComponent* CollectionSphere;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;
public:
	ABatteryPickupCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

protected:

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/** Handler for when a touch input begins. */
	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);

	/** Handler for when a touch input stops. */
	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);
	/** Called when we press a key to collect any pickups inside the CollectionSphere */
	UFUNCTION(BlueprintCallable, Category = "Pickups") void CollectPickups();


protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	/** Return CollectionSphere subobject **/
	FORCEINLINE class USphereComponent* GetCollectionSphere() const {return CollectionSphere;}

protected:
	/** The starting power level of our character */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battery Pickup", Meta = (BlueprintProtected = "true"))
		float InitialPower;
	/** Multiplier for character speed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battery Pickup", Meta = (BlueprintProtected = "true"))
		float SpeedFactor;
	/** Speed when power level = 0 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Battery Pickup", Meta = (BlueprintProtected = "true"))
		float BaseSpeed;
	UFUNCTION(BlueprintImplementableEvent, Category = "Battery Pickup")
		void PowerChangeEffect();
public:
	/** Accessor function for initial power */
	UFUNCTION(BlueprintPure, Category = "Battery Pickup")
		float GetInitialPower();
	/** Accessor function for current power */
	UFUNCTION(BlueprintPure, Category = "Battery Pickup")
		float GetCurrentPower();
	/**
	Function to update the character's power
	* @param PowerChange This is the amount to change the power by, and it can be positive or negative.
	*/
	UFUNCTION(BlueprintCallable, Category = "Battery Pickup")
		void UpdatePower(float PowerChange);


private:
	/** Current power level of our character */
	UPROPERTY(VisibleAnywhere, Category = "Battery Pickup")
		float CharacterPower;


};

