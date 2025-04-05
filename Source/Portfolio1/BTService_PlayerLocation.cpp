// BTService_PlayerLocation.cpp

#include "BTService_PlayerLocation.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Pawn.h"

UBTService_PlayerLocation::UBTService_PlayerLocation()
{
    NodeName = "Update Player Location N";
}

void UBTService_PlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds); // Fixed Super:: (not :::)

    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0); // Fixed type and added APawn*
    if (PlayerPawn == nullptr)
    {
        return;
    }

    OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), PlayerPawn->GetActorLocation()); // Added semicolon
}
