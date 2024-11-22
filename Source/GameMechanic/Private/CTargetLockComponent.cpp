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

TArray<AActor*> UCTargetLockComponent::TraceForTargets(AActor* CplayerRef, float CLockOnRadius, TSubclassOf<AActor> CLockOnClass)
{
	TArray<AActor*> CLocalTargets;
	//prevent crash
	if (!CplayerRef) return CLocalTargets;

	//get player local
	FVector start = CplayerRef->GetActorLocation();

	//prepare paramiters for line trace sphere
	TArray<FHitResult> hitResults;
	FCollisionShape zone = FCollisionShape::MakeSphere(CLockOnRadius);
	FCollisionQueryParams params;
	params.AddIgnoredActor(CplayerRef); // Ignore self
	params.bTraceComplex = false;

	//perform multi sphere line trace
	bool bHit = GetWorld()->SweepMultiByObjectType(
		hitResults,
		start,
		start,
		FQuat::Identity,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_Pawn),
		zone,
		params
	);

	// Debug visualization (optional)
	DrawDebugSphere(GetWorld(), start, CLockOnRadius, 32, FColor::Green, false, 1.0f);

	//proces results
	if (bHit)
	{
		for (FHitResult& hit : hitResults)
		{
			if (AActor* hitActor = hit.GetActor())
			{
				if (hitActor->IsA(CLockOnClass))
				{
					CLocalTargets.Add(hitActor);
				}
			}

		}
	}

	return CLocalTargets;
}


AActor* UCTargetLockComponent::CCheckForClosestTarget(TArray<AActor*> Targets, AActor* CplayerRef, UCameraComponent* FollowCamera)
{
	if (CplayerRef || Targets.Num() == 0) return nullptr;
	AActor* ClosestTarget = nullptr;
	
	for (AActor* target : Targets)
	{
		if (!target) continue;

		//get starts and end for line trace
		FVector start = FollowCamera->GetComponentLocation();
		FVector end = target->GetActorLocation();

		// prepeare line trace porams
		FHitResult hitResult;
		FCollisionQueryParams params;
		params.AddIgnoredActor(CplayerRef); // Ignore self
		params.bTraceComplex = false;

		bool bHit = GetWorld()->LineTraceSingleByChannel(
			hitResult,
			start,
			end,
			ECC_Visibility,
			params
		);

	}

	return ClosestTarget;
}
float UCTargetLockComponent::CheckHowCloseTargetToCenter(AActor* target, AActor* CplayerRef, UCameraComponent* followCamera)
{
	if (!target || !CplayerRef || !followCamera) return 0.0f;

	//get locations 
	FVector playerLocation = CplayerRef->GetActorLocation();
	FVector targetLocation = target->GetActorLocation();

	//get foward vector
	FVector cameraForward = followCamera->GetForwardVector();

	//calculate direction/ look at vector
	FVector direction = (targetLocation - playerLocation).GetSafeNormal();

	//calculate dot product
	float dot = FVector::DotProduct(cameraForward, direction);


	return dot;
}
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

