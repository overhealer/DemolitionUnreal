// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "DemolitionProjectile.h"
#include "ProjectileWeapon.generated.h"

/**
 * 
 */
UCLASS()
class DEMOLITION_API AProjectileWeapon : public AWeapon
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class ADemolitionProjectile> ProjectileClass;

	void Fire() override;
};
