// Fill out your copyright notice in the Description page of Project Settings.


#include "ForceControl.h"

// Sets default values for this component's properties
UForceControl::UForceControl()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UForceControl::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UForceControl::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


bool UForceControl::ChangePhysics()
{
	if (bSimulatePhysics == true)
	{
		bSimulatePhysics = false;
	}
	else
	{
		bSimulatePhysics = true;
	}
	return bSimulatePhysics;
}

double UForceControl::DipoleDipoleInteraction(double SelfOriginOfForce, double TargetOriginOfForce, double DDInfluenceDistance, double AffinityContribution, double ForceModifier);
{
	double DistanceToTarget = VectorLength(SelfOriginOfForce - TargetOriginOfForce);
	double NormalizedDistanceVector = Normalize(SelfOriginOfForce - TargetOriginOfForce);
	double ForceDistanceComponent = pow((DDInfluenceDistance - clamp(DistanceToTarget, 0.0, DDInfluenceDistance)) / DDInfluenceDistance, 2);
	double Force = ForceDistanceComponent * (ForceModifier * 10000) * NormalizedDistanceVector * AffinityContribution;
	return Force;
}