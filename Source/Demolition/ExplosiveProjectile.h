// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DemolitionProjectile.h"
#include "ExplosionComponent.h"
#include "ExplosiveProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
/**
 * 
 */
UCLASS()
class DEMOLITION_API AExplosiveProjectile : public ADemolitionProjectile
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
	UExplosionComponent* ExplosionComp;

public:
	AExplosiveProjectile();

	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;

	void Explode();

	void SetDamage(float Damage, TSubclassOf<class UDamageType> DamageType);
};
