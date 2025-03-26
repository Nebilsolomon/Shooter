// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"


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

        GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"),PlayerPawn->GetActorLocation());
       
    }
    
   
}





void AShooterAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);  // Properly call the base Tick function






 
}



