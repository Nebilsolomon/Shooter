// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"


void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();

    // Get the player pawn
//PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    // Set focus on the player pawn
   

    if (AIBehavior != nullptr)
    {

        RunBehaviorTree(AIBehavior);

        PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
        GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"),GetPawn()->GetActorLocation());

        
       
       
    }
    
   
}





void AShooterAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);  // Properly call the base Tick function



    

 
}

bool AShooterAIController::IsDead() const
{
AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
if (ControlledCharacter == nullptr) return true;

return ControlledCharacter->IsDead();
}



