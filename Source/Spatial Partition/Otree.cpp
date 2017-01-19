#include "Custom.h"
#include "Otree.h"


// Sets default values
Otree::Otree()
{
	PrimaryActorTick.bCanEverTick = false;
}

AActor* Otree::PreIntialize(AActor* Actor, FBox Region)
{
	AActor* TempActor = NULL;

	if (Region.IsInside(Actor->GetActorLocation()))
	{
		TempActor = Actor;
	}

	return TempActor;
}

void Otree::BeginPlay()
{
	Super::BeginPlay();

}

void Otree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}