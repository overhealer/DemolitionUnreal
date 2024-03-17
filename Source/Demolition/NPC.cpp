// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC.h"


// Called when the game starts or when spawned
void ANPC::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UBehaviorTree* ANPC::GetBehaviorTree() const
{
	return Tree;
}

APatrolPath* ANPC::GetPatrolPath() const
{
	return PatrolPath;
}

UAnimMontage* ANPC::GetAnimMontage() const
{
	return Montage;
}

int ANPC::MeleeAttack_Implementation()
{
	if (Montage)
	{
		PlayAnimMontage(Montage);
	}
	return 0;
}

float ANPC::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (HealthPoints <= 0)
		return 0;
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	HealthPoints -= DamageAmount;
	if (HealthPoints <= 0)
	{
		RagdollStart();
	}
	return DamageAmount;
}

