// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Kismet/GameplayStatics.h"
#include "Components/PointLightComponent.h"

#include "DrawDebugHelpers.h"

#include "Engine/DamageEvents.h" // This is the most important missing include


// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    RootComponent = Root;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);


	
}






// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




void AGun::PullTrigger()
{
   // UE_LOG(LogTemp, Warning, TEXT("You have been shot, Nebil!"));

    if (MuzzleFlash)  
    {
        UGameplayStatics::SpawnEmitterAttached(
            MuzzleFlash,
            Mesh,  // Your gun mesh component
            TEXT("MuzzleFlashSocket")
        );
    }
    else  
    {
        UE_LOG(LogTemp, Warning, TEXT("MuzzleFlash is NULL! Assign a valid particle effect."));
    }

  

  
APawn * OwnerPawn = Cast<APawn>(GetOwner());
if(OwnerPawn== nullptr) return; 


AController *ownerController = OwnerPawn->GetController(); 
if(ownerController== nullptr) return; 


FVector Location; 
FRotator Rotation;
ownerController->GetPlayerViewPoint(Location, Rotation);



//ECC_GameTraceChannel1

DrawDebugSphere(GetWorld(), Location, 10.0f, 12, FColor::Red, true, 4.1f);


FHitResult HitResult;
FVector Start = Location; // Starting point of the trace (player's camera position)
FVector End = Start + (Rotation.Vector() * 1000); // Direction of the trace based on rotation, and scaled by 1000 units
ECollisionChannel TraceChannel = ECC_GameTraceChannel1; // The channel to use for the trace, such as ECC_Visibility, ECC_WorldStatic, etc.

bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECollisionChannel::ECC_GameTraceChannel1);

if (bHit)
{

   FVector ShotDirection =  - Rotation.Vector(); 
    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, HitResult.Location, ShotDirection.Rotation() );



    AActor * HitActor = HitResult.GetActor();
    if (HitActor != nullptr) {
      
        FPointDamageEvent DamageEvent(Damage,HitResult, ShotDirection, nullptr );

        HitActor->TakeDamage(Damage, DamageEvent, ownerController, this );

    }
   
    






}




    



}
