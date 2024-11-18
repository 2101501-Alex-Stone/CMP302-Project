// Fill out your copyright notice in the Description page of Project Settings.


#include "CStatusComponent.h"

// Sets default values for this component's properties
UCStatusComponent::UCStatusComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	maxStamina = 60;
	currentStamina = 30;
	staminaRegen = 0.2;
	walkSpeed = 200;
	runSpeed = 600;
	jogSpeed = 450;
	maxHealth = 100;
	currentHealth = 80;

	// ...
}


// Called when the game starts
void UCStatusComponent::BeginPlay()
{
	Super::BeginPlay();
	
	// ...
	
}


// Called every frame
void UCStatusComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCStatusComponent::DecreaseStamina(float amount)
{
	bool index = false;
	float temp = currentStamina - amount;

	if (temp < 0)
	{
		index = true;
	}

	float selectVal = index ? 0.0 : temp;
	currentStamina = selectVal;
}

bool UCStatusComponent::DecreaseHealth(float amount)
{
	bool isDead = false;
	float temp = currentHealth - amount;

	if (temp < 0)
	{
		isDead = true;
	}
	float selectVal = isDead ? 0.0 : temp;
	currentHealth = selectVal;

	return isDead;
}

