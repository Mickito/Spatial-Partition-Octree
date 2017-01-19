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
	if (Actors.Num() <= 0 || (dimensions.X <= 500 && dimensions.Y <= 500 && dimensions.Z <= 500))
		return;

	//Generates box dimensions
	FVector Dimensions = Region.Max - Region.Min;
	FVector center = Region.Min + (dimensions / 2.0);
	
	//Subdivide into 8 regions
	subdivideBox.Insert(FBox(Region.Min, center), 0);
	subdivideBox.Insert(FBox(center, Region.Max), 1);
	subdivideBox.Insert(FBox(FVector(center.X, Region.Min.Y, center.Z), FVector(Region.Max.X, center.Y, Region.Max.Z)), 2);
	subdivideBox.Insert(FBox(FVector(center.X, center.Y, Region.Min.Z), FVector(Region.Max.X, Region.Max.Y, center.Z)), 3);
	subdivideBox.Insert(FBox(FVector(center.X, Region.Min.Y, Region.Min.Z), FVector(Region.Max.X, center.Y, center.Z)), 4);
	subdivideBox.Insert(FBox(FVector(Region.Min.X, Region.Min.Y, center.Z), FVector(center.X, center.Y, Region.Max.Z)), 5);
	subdivideBox.Insert(FBox(FVector(Region.Min.X, center.Y, Region.Min.Z), FVector(center.X, Region.Max.Y, center.Z)), 6);
	subdivideBox.Insert(FBox(FVector(Region.Min.X, center.Y, center.Z), FVector(center.X, Region.Max.Y, Region.Max.Z)), 7);




}