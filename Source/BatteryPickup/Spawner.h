// Copywright 2022 all Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Spawner.generated.h"

UCLASS()
class BATTERYPICKUP_API ASpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Returns the WhereToSpawn subObject */
	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; }

	/** Find a random point within the BoxComponent */
	UFUNCTION(BlueprintPure, Category = "Spawning")
		FVector GetRandomPointInVolume();


private:
	/** Box Component to specify where the pickups should be spawned */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
		UBoxComponent* WhereToSpawn;


	// what to spawn

protected:
	/** The pickup to spawn */
	UPROPERTY(EditAnywhere, Category = "Spawning")
		TSubclassOf<class APickup> WhatToSpawn;

private:
	/** Handle spawning a new pickup */
	void SpawnPickup();


	//Timer
protected:
	FTimerHandle SpawnTimer;
	/** Minimum spawn delay */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		float SpawnDelayRangeLow;
	/** Maximum spawn delay */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
		float SpawnDelayRangeHigh;
private:
	/** The current spawn delay */
	float SpawnDelay;
};
