// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SkeletalMeshComponent.h"
#include "DemolitionCharacter.h"
#include <Engine/DataTable.h>
#include <ALSV4_CPP/Public/Library/ALSCharacterEnumLibrary.h>
#include "Weapon.generated.h"


UCLASS()
class DEMOLITION_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon")
	FDataTableRowHandle WeaponData;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	virtual void Fire();

	virtual void OnWeaponPickup();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* SkeletalMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundBase* FireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UParticleSystem* FireEmitter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UParticleSystem* HitEmitter;

protected:
	FDemolitionWeaponData* WeaponDataRow;
};

USTRUCT(BlueprintType)
struct FDemolitionWeaponData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Weapon Data")
	USoundBase* FireSound;

	UPROPERTY(EditAnywhere, Category = "Weapon Data")
	UParticleSystem* FireEmitter;
	UPROPERTY(EditAnywhere, Category = "Weapon Data")
	UParticleSystem* HitEmitter;

	UPROPERTY(EditAnywhere, Category = "Weapon Data")
	int MaxAmmoInClip;

	UPROPERTY(EditAnywhere, Category = "Weapon Data")
	float BaseDamage;

	UPROPERTY(EditAnywhere, Category = "Weapon Data")
	EALSOverlayState PlayerOverlayState;

	UPROPERTY(EditAnywhere, Category = "Weapon Data")
	TSubclassOf<UDamageType> DamageType;
};
