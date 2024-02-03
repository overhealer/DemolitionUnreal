// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindPatrolPoint.h"
#include "NPC_AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "NPC.h"

UBTTask_FindPatrolPoint::UBTTask_FindPatrolPoint(FObjectInitializer const& ObjectInitializer) : UBTTask_BlackboardBase(ObjectInitializer)
{
	NodeName = TEXT("Find Path Point");
}

EBTNodeResult::Type UBTTask_FindPatrolPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (auto* const cont = Cast<ANPC_AIController>(OwnerComp.GetAIOwner()))
	{
		if (auto* const bc = OwnerComp.GetBlackboardComponent())
		{
			auto const index = bc->GetValueAsInt((GetSelectedBlackboardKey()));

			if (auto* npc = Cast<ANPC>(cont->GetPawn()))
			{
				auto const point = npc->GetPatrolPath()->GetPatrolPoint(index);

				auto const globalPoint = npc->GetPatrolPath()->GetActorTransform().TransformPosition(point);
				bc->SetValueAsVector(PatrolPathVectorKey.SelectedKeyName, globalPoint);

				FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
				return EBTNodeResult::Succeeded;
			}
		}
	}
	return EBTNodeResult::Failed;
}
