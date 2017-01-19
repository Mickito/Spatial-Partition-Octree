#include "Custom.h"
#include "Otree.h"


// Sets default values
Otree::Otree()
{
	PrimaryActorTick.bCanEverTick = false;
}

AActor* Otree::PreIntialize(AActor* actor, FBox region)
{
	AActor* TempActor = NULL;

	if (region.IsInside(actor->GetActorLocation()))
	{
		TempActor = actor;
	}

	return TempActor;
}

void Otree::Initialize(TArray<AActor*> actors, FBox region)
{
	Actors = actors;
	Region = region;
}


void Otree::BeginPlay()
{
	Super::BeginPlay();

}

void Otree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void Otree::BuildTree()
{
}