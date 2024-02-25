// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileWeapon.h"
#include "DemolitionALSCharacter.h"

void AProjectileWeapon::Fire()
{
	Super::Fire();

	// Try and fire a projectile
	if (ProjectileClass != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			ADemolitionALSCharacter* Player = Cast<ADemolitionALSCharacter>(GetOwner());
			if (Player)
			{
				const FRotator SpawnRotation = Player->GetAimingRotation();
				// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
				const FVector SpawnLocation = SkeletalMeshComp->GetSocketLocation("MuzzleFlash");

				//Set Spawn Collision Handling Override
				FActorSpawnParameters ActorSpawnParams;
				ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

				// Spawn the projectile at the muzzle
				World->SpawnActor<ADemolitionProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
			}
			
		}
	}
}
