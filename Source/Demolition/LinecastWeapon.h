// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "LinecastWeapon.generated.h"

/**
 * 
 */
UCLASS()
class DEMOLITION_API ALinecastWeapon : public AWeapon
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "Collision")
	TEnumAsByte<ECollisionChannel> TraceChannelProperty = ECC_Pawn;

	void Fire() override;
};
