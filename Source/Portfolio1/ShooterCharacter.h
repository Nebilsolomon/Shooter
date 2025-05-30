// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class AGun;

UCLASS()
class PORTFOLIO1_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();
		void Shoot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	UFUNCTION(BlueprintPure)
	bool IsDead() const;
	


	private: 

	void MoveForward(float axisValue);
	void LookUp(float axisValue);

	void MoveRight(float axisValue);
	void LookRight(float axisValue);


	public:
	UPROPERTY(EditDefaultsOnly, Category = "nebil")
	TSubclassOf<AGun> GunClass;

 
   UPROPERTY()
   AGun* Gun;  // This is the member variable

   UPROPERTY(EditDefaultsOnly, Category = "nebil")
	float MaxHealth = 100; 

	UPROPERTY(EditDefaultsOnly, Category = "nebil")
	float Health = 10; 
};
