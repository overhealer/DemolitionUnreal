// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/Character.h"
#include "PatrolPath.h"
#include "CombatInterface.h"
#include "Animation/AnimMontage.h"
#include "ALSV4_CPP/Public/Character/ALSCharacter.h"
#include "NPC.generated.h"

UCLASS()
class DEMOLITION_API ANPC : public AALSCharacter, public ICombatInterface
{
	GENERATED_BODY()

//public:
//	// Sets default values for this character's properties
//	ANPC() = default;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UBehaviorTree* GetBehaviorTree() const;
	APatrolPath* GetPatrolPath() const;
	UAnimMontage* GetAnimMontage() const;

	int MeleeAttack_Implementation() override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	float HealthPoints = 10;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AI", meta=(AllowPrivateAccess="true"))
	UBehaviorTree* Tree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	APatrolPath* PatrolPath;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation", meta = (AllowPrivateAccess = "true"))
	UAnimMontage* Montage;
};
