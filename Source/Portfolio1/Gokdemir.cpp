// Fill out your copyright notice in the Description page of Project Settings.


#include "Gokdemir.h"

// Sets default values
AGokdemir::AGokdemir()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGokdemir::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGokdemir::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGokdemir::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

