// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameMechanic/Public/CStatusComponent.h"
#include "MyCharacter.generated.h"

UCLASS()
class GAMEMECHANIC_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 TestVariable;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCStatusComponent* cStatusComponent;

	UFUNCTION(BlueprintCallable, Category = "Macro")
	void CStaminaRegenTick();

	UFUNCTION(BlueprintCallable, Category = "Macro")
	void CHandleStaminaRegen(bool StartStaminaRegen, float duration);

	UFUNCTION(BlueprintCallable, Category = "Macro")
	void CRunTick();

	UFUNCTION(BlueprintCallable, Category = "Macro")
	void CHandleRollStepBack();

	UFUNCTION(BlueprintCallable, Category = "Macro")
	void CHandleAttack();

	UFUNCTION(BlueprintCallable, Category = "Func")
	bool CCheckForStamina();

	UFUNCTION(BlueprintCallable, Category = "Func")
	void CUpdateAttackRotation();

	UFUNCTION(BlueprintCallable, Category = "Event")
	void CRefreshStamina(bool startStaminaRegen);
};
