// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"


void AKillEmAllGameMode::PawnKilled(APawn * PawnKilled)
{
    Super::PawnKilled(PawnKilled);

    UE_LOG(LogTemp, Display, TEXT("Pawn Killed now !!!!!!!!"));

    APlayerController * PlayerController = Cast<APlayerController>(PawnKilled->GetController()); 

    if (PlayerController != nullptr)
    {
        PlayerController->GameHasEnded(nullptr, false);
    }
    
}
