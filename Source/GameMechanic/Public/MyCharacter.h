// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameMechanic/Public/CStatusComponent.h"
#include "EnhancedInputComponent.h"
#include "InputAction.h"
#include "GameMechanic/public/CTargetLockComponent.h"
#include "MyCharacter.generated.h"

UENUM(BlueprintType)
enum class EPlayerState : uint8{
	NONE =0 UMETA(DisplayName = "NONE"),
	RUNNING =1 UMETA(DisplayName = "RUNNING"),
	ROLLING =2 UMETA(DisplayName = "ROLLING"),
	STEPBACK=3 UMETA(DisplayName = "STEPBACK"),
	LIGHTATTACK=4 UMETA(DisplayName = "LIGHTATTACK"),
	HEAVYATTACK=5 UMETA(DisplayName = "HEAVYATTACK")

};

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

	//variables
	//combat
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool cCanBeHit;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputAction* inputToMove;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int cAttackCounter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float cDamage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool cSwordAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> cHitTargets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool cIsAttacking;

	//movment
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool cMovmentInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EPlayerState cCurrentPlayerState;


	//components
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCStatusComponent* cStatusComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCTargetLockComponent* cTargetLockComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UEnhancedInputComponent* Input;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UCapsuleComponent* CCapsualComponent;
	
	
	//macros
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

	//functions
	UFUNCTION(BlueprintCallable,BlueprintPure, Category = "Func")
	bool CHasMovementKeyInput();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Func")
	bool CCheckForStamina();

	UFUNCTION(BlueprintCallable, Category = "Func")
	void CUpdateAttackRotation();

	//events
	UFUNCTION(BlueprintCallable, Category = "Event")
	void CRefreshStamina(bool startStaminaRegen);

};
