// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_ChangeSpeed.h"
#include "NPC.h"
#include "NPC_AIController.h"
#include "GameFramework/CharacterMovementComponent.h"

UBTService_ChangeSpeed::UBTService_ChangeSpeed()
{
	bNotifyBecomeRelevant = true;
	NodeName = TEXT("Change Speed");
}

void UBTService_ChangeSpeed::OnBecomeRelevant(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::OnBecomeRelevant(OwnerComp, NodeMemory);
	if (auto const cont = OwnerComp.GetAIOwner())
	{
		if (auto* const npc = Cast<ANPC>(cont->GetPawn()))
		{
			npc->GetCharacterMovement()->MaxWalkSpeed = Speed;
		}
	}
}
