// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CStatusComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEMECHANIC_API UCStatusComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCStatusComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float maxStamina;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float currentStamina;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float staminaRegen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float walkSpeed ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float runSpeed ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float jogSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float maxHealth ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float currentHealth;
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	virtual void DecreaseStamina(float amount);

	UFUNCTION(BlueprintCallable) 
	bool DecreaseHealth(float amount);

		
};
