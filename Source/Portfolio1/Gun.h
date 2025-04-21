// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SkeletalMeshComponent.h" // Move this above the generated.h file

#include "Gun.generated.h" // This must always be the last include

UCLASS()
class PORTFOLIO1_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();
   void PullTrigger();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;


	UPROPERTY(EditAnywhere, Category = "nebil")
	UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere, Category = "nebil")
	UParticleSystem* ImpactEffect;

	UPROPERTY(EditAnywhere, Category = "nebil")
	USoundBase * MuzzleSound;


	UPROPERTY(EditAnywhere)
	 float Damage = 10 ; 

	 bool GunTrace(FHitResult &Hit, FVector &ShotDirection );

	 AController * GetOwnerController () const; 

};
