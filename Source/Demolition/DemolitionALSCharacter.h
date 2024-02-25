// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/ALSCharacter.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Weapon.h"
#include "DemolitionALSCharacter.generated.h"

/**
 * 
 */
UCLASS()
class DEMOLITION_API ADemolitionALSCharacter : public AALSCharacter
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void EquipWeapon(AWeapon* weapon);

	void UseWeapon();

private:
	AWeapon* CurrentWeapon;
};
