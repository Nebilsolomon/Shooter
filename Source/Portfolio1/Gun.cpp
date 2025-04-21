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

bool AGun::GunTrace(FHitResult &Hit, FVector &ShotDirection)
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
   
     
   
     
     
       AController *ownerController = GetOwnerController();
       if(ownerController== nullptr)  
       return false; 
   
   
   FVector Location; 
   FRotator Rotation;
   ownerController->GetPlayerViewPoint(Location, Rotation);

  ShotDirection =  - Rotation.Vector(); 

   
   
   
   //ECC_GameTraceChannel1
   
   //DrawDebugSphere(GetWorld(), Location, 10.0f, 12, FColor::Red, true, 4.1f);
   FCollisionQueryParams Params;
   Params.AddIgnoredActor(this);
   Params.AddIgnoredActor(GetOwner());
   

   FVector Start = Location; // Starting point of the trace (player's camera position)
   FVector End = Start + (Rotation.Vector() * 1000); // Direction of the trace based on rotation, and scaled by 1000 units
   ECollisionChannel TraceChannel = ECC_GameTraceChannel1; // The channel to use for the trace, such as ECC_Visibility, ECC_WorldStatic, etc.
   
   return  GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECollisionChannel::ECC_GameTraceChannel1, Params);
   








}




void AGun::PullTrigger()
{
  





FHitResult Hit; 
FVector ShotDirection; 


bool bHit  = GunTrace(Hit, ShotDirection); 


if (bHit)
{

    UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.Location, ShotDirection.Rotation() );

    UGameplayStatics::SpawnSoundAttached(MuzzleSound,  Mesh, TEXT("MuzzleFlashSocket") );


    AActor * HitActor = Hit.GetActor();
    if (HitActor != nullptr) {
      
        FPointDamageEvent DamageEvent(Damage,Hit, ShotDirection, nullptr );
        AController *ownerController = GetOwnerController();


        HitActor->TakeDamage(Damage, DamageEvent, ownerController, this );

    }
   
    






}



}



AController * AGun::GetOwnerController () const{

    APawn * OwnerPawn = Cast<APawn>(GetOwner());
    if(OwnerPawn== nullptr){ return nullptr;} 
    
    
   return OwnerPawn->GetController();
}
