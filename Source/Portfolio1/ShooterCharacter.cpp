// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"
#include "Gun.h"


// Sets default values
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	// Spawn the Gun actor


	Gun= GetWorld()->SpawnActor<AGun>(GunClass);


// If you want to attach it, use the correct variable name
if (Gun)
{
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));

	Gun->SetOwner(this);
}



}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
     
	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AShooterCharacter::MoveForward);


	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AShooterCharacter::LookUp);

	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AShooterCharacter::MoveRight);

	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &AShooterCharacter::AddControllerYawInput);

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AShooterCharacter::Jump);

	PlayerInputComponent->BindAction(TEXT("Shoot"), EInputEvent::IE_Pressed, this, &AShooterCharacter::Shoot);



	
	

	





	
}

float AShooterCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	
  float DamageApplied = Super::TakeDamage( DamageAmount,  DamageEvent, EventInstigator,  DamageCauser); 


  return DamageApplied; 

}

void AShooterCharacter::MoveForward(float axisValue)
{
	AddMovementInput(GetActorForwardVector() * axisValue);
}

void AShooterCharacter::LookUp(float axisValue)
{

	AddControllerPitchInput(axisValue);
	
}





void AShooterCharacter::MoveRight(float axisValue)
{
	AddMovementInput(GetActorRightVector() *axisValue );



}

// void AShooterCharacter::LookRight(float axisValue)
// {
	


// }

void AShooterCharacter::Shoot()
{
	Gun->PullTrigger();
}

