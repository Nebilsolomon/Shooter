// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Gokdemir.generated.h"

UCLASS()
class PORTFOLIO1_API AGokdemir : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGokdemir();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
