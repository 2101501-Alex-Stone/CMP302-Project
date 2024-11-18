// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CTargetLockComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEMECHANIC_API UCTargetLockComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCTargetLockComponent();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float lockOnRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> lockOnClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AMyCharacter* playerRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AActor* targetLockedOn;
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//UFUNCTION(BlueprintCallable)
	//void TraceForTargets();

	////UFUNCTION(BlueprintCallable)
	////AActor CheckForClosestTarget(TArray<AActor>* Targets);

	//UFUNCTION(BlueprintCallable)
	//float CheckHowCloseTargetToCenter(AActor* target);

	//UFUNCTION(BlueprintCallable)
	//FRotator3f GetLockOnCameraRotation();
};
