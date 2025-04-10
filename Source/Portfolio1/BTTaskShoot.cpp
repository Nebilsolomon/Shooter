// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskShoot.h"
#include "ShooterCharacter.h"
#include "AIController.h"


UBTTaskShoot::UBTTaskShoot()
{
    NodeName = "shoot ++";
}

EBTNodeResult::Type UBTTaskShoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);   


    if (OwnerComp.GetAIOwner()== nullptr)
    {
      return  EBTNodeResult::Failed;
    }

    AShooterCharacter * EnemyShooter = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());

    if (EnemyShooter == nullptr)
    
    {
        return  EBTNodeResult::Failed;
    }
    EnemyShooter->Shoot();

    
   return  EBTNodeResult::Succeeded;
}
