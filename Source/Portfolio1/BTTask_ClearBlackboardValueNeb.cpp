// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_ClearBlackboardValueNeb.h"
#include "BehaviorTree/BlackboardComponent.h"






UBTTask_ClearBlackboardValueNeb::UBTTask_ClearBlackboardValueNeb()
{
    NodeName = "Clear Blackboard Value Nebil";
}

EBTNodeResult::Type UBTTask_ClearBlackboardValueNeb::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

   
    
        OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
        return EBTNodeResult::Succeeded;
    

   
}
