// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class PORTFOLIO1_API AShooterAIController : public AAIController
{
	GENERATED_BODY()
	protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
public:
	bool IsDead() const;

	
	APawn* PlayerPawn;

	UPROPERTY(EditAnywhere, Category="nebil")
    class UBehaviorTree * AIBehavior;


	
};
