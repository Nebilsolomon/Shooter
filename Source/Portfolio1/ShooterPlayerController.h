// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"


/**
 * 
 */
UCLASS()
class PORTFOLIO1_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()
	public:
   virtual void GameHasEnded(class AActor* EndGameFocus = nullptr, bool bIsWinner = false) override;
   
   private:
   UPROPERTY(EditAnywhere, Category = "Nebil")
   TSubclassOf<class UUserWidget> LoseScreenClass;


   private:
   UPROPERTY(EditAnywhere, Category = "Nebil")
   TSubclassOf<class UUserWidget> WinScreenClass;
   
   
  
   UPROPERTY(EditAnywhere)
   float RestartDelay = 5; 
   FTimerHandle RestartTimer;
};
