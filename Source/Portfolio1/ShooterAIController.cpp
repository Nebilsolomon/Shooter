// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterAIController.h"
#include "Kismet/GameplayStatics.h"

void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();

    // Get the player pawn
PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

    // Set focus on the player pawn
   
   
}





void AShooterAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);  // Properly call the base Tick function

    // Check if the AI has line of sight to the player
    if (LineOfSightTo(PlayerPawn))
    {
        // Set focus and move to the player
        SetFocus(PlayerPawn);
        MoveToActor(PlayerPawn, 400);
    }
    else
    {
        // Clear focus and stop movement if no line of sight
        ClearFocus(EAIFocusPriority::Gameplay);
        StopMovement();
    }
}










// void AShooterAIController::Tick(float DeltaTime)
// {
//     Super::Tick(float DeltaTime);
     




//      if (LineOfSightTo(PlayerPawn))
//      {
//             SetFocus(PlayerPawn);
//             MoveToActor(PlayerPawn,200);
//      }
//      else {


//         ClearFocus(EAIFocusPriority::Gameplay);
//         StopMovement();
//      }

     
// }
