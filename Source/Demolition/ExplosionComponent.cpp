// Fill out your copyright notice in the Description page of Project Settings.

#include "ExplosionComponent.h"
#include "Containers/UnrealString.h"

// Sets default values for this component's properties
UExplosionComponent::UExplosionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	BaseDamage = 10;
	MinimumDamage = 1;
	InnerRadius = 1;
	OuterRadius = 100;

	// ...
}

void UExplosionComponent::Explode(FVector Position)
{
	UGameplayStatics::ApplyRadialDamageWithFalloff(this, BaseDamage, MinimumDamage, Position,
		InnerRadius, OuterRadius, 1, DamageType, TArray<AActor*>(), GetOwner(), nullptr, ECollisionChannel::ECC_WorldDynamic);

	if (ExplosionParticle != nullptr)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, ExplosionParticle, Position, GetComponentRotation());
	}

	if (ExplosionSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, ExplosionSound, Position);
	}
}



