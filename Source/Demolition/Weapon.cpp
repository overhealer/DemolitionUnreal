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
	SkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComp"));
}



void AWeapon::Fire()
{
	if (FireSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	if (FireEmitter)
	{
		UGameplayStatics::SpawnEmitterAttached(FireEmitter, SkeletalMeshComp, "MuzzleFlash");
	}
	
}

void AWeapon::OnWeaponPickup()
{
	if (WeaponData.IsNull() == false)
	{
		WeaponDataRow = WeaponData.GetRow<FDemolitionWeaponData>("Data");
		if (WeaponDataRow != nullptr)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("INIT WEAPON"));
			FireSound = WeaponDataRow->FireSound;
			FireEmitter = WeaponDataRow->FireEmitter;
			HitEmitter = WeaponDataRow->HitEmitter;
		}
	}
}
