// Fill out your copyright notice in the Description page of Project Settings.


#include "CTargetLockComponent.h"

// Sets default values for this component's properties
UCTargetLockComponent::UCTargetLockComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCTargetLockComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCTargetLockComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

//TArray<AActor> UCTargetLockComponent::TraceForTargets()
//{
//	TArray<AActor> funky;
//
//	return funky;
//}
//
////AActor UCTargetLockComponent::CheckForClosestTarget(TArray<AActor>* Targets)
////{
////	return AActor();
////}
//
//float UCTargetLockComponent::CheckHowCloseTargetToCenter(AActor* target)
//{
//	return 0.0f;
//}
//
//FRotator3f UCTargetLockComponent::GetLockOnCameraRotation() 
//{
//	return FRotator3f(); 
//}

