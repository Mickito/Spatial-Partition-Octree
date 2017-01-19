#pragma once

#include "GameFramework/Actor.h"
#include "Otree.generated.h"

UCLASS()
class CUSTOM_API AOtree : public AActor
{
	GENERATED_BODY()

public:

	Otree();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable, Category = "Octree")
		AActor* PreIntialize(AActor* A, FBox R);


};