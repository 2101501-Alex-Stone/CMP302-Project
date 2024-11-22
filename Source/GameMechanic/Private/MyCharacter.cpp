// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameMechanic/Public/CStatusComponent.h"
#include "GameMechanic/Public/CTargetLockComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Test Object Begin Play"));
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow,TEXT("Test debug message!"));
	
}


// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	
}

void AMyCharacter::CStaminaRegenTick()
{
	float stamina = 10;
	if (cStatusComponent->currentStamina >= cStatusComponent->maxStamina)
	{
		stamina = 20;
	}
}

void AMyCharacter::CHandleStaminaRegen(bool StartStaminaRegen, float duration)
{
}

void AMyCharacter::CRunTick()
{
}

void AMyCharacter::CHandleRollStepBack()
{
}

void AMyCharacter::CHandleAttack()
{
}

bool AMyCharacter::CHasMovementKeyInput()
{
	return false;
}

bool AMyCharacter::CCheckForStamina()
{
	return false;
}

void AMyCharacter::CUpdateAttackRotation()
{
}

void AMyCharacter::CRefreshStamina(bool startStaminaRegen)
{
	
}

