// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class BATTERYPICKUP_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/* Return the mesh for the pickup */
	FORCEINLINE UStaticMeshComponent* GetMesh() const { return pickupMesh; }

	/** Function to call when the pickup is collected */
	UFUNCTION(BlueprintNativeEvent)
		void WasCollected();
		virtual void WasCollected_Implementation();

	// function to return the variable value
	UFUNCTION(BlueprintPure, category = "Pickup")
		bool IsActive();

	//function to change the value of the variable
	UFUNCTION(BlueprintCallable, Category = "Pickup")
		void SetActive(bool NewPickupState);



protected:
	bool bIsActive;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup", meta = (allowprivateaccess = true))
	UStaticMeshComponent* pickupMesh;
};
