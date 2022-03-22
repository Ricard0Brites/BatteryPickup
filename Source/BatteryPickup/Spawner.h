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

	/** Returns the WhereToSpawn subobject */
	FORCEINLINE class UBoxComponent* GetWhereToSpawn() const { return WhereToSpawn; }

	/** Find a random point within the BoxComponent */
	UFUNCTION(BlueprintPure, Category = "Spawning")
		FVector GetRandomPointInVolume();


private:
	/** Box Component to specify where the pickups should be spawned */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning", meta = (AllowPrivateAccess = "true"))
		UBoxComponent* WhereToSpawn;
};
