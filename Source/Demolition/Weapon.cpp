// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "TP_WeaponComponent.h"
#include "DemolitionCharacter.h"
#include "DemolitionProjectile.h"
#include "GameFramework/PlayerController.h"
#include "Camera/PlayerCameraManager.h"
#include "Kismet/GameplayStatics.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AWeapon::AWeapon()
{
	MuzzleOffset = FVector(100.0f, 0.0f, 10.0f);
}

void AWeapon::Detach()
{
}


void AWeapon::Fire(ADemolitionCharacter* character)
{
	if (character == nullptr || character->GetController() == nullptr)
	{
		return;
	}

	// Try and fire a projectile
	if (ProjectileClass != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World != nullptr)
		{
			APlayerController* PlayerController = Cast<APlayerController>(character->GetController());
			const FRotator SpawnRotation = PlayerController->PlayerCameraManager->GetCameraRotation();
			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			const FVector SpawnLocation = GetOwner()->GetActorLocation() + SpawnRotation.RotateVector(MuzzleOffset);

			//Set Spawn Collision Handling Override
			FActorSpawnParameters ActorSpawnParams;
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

			// Spawn the projectile at the muzzle
			World->SpawnActor<ADemolitionProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
		}
	}

	// Try and play the sound if specified
	if (FireSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, character->GetActorLocation());
	}

	// Try and play a firing animation if specified
	if (FireAnimation != nullptr)
	{
		// Get the animation object for the arms mesh
		UAnimInstance* AnimInstance = character->GetMesh1P()->GetAnimInstance();
		if (AnimInstance != nullptr)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
}