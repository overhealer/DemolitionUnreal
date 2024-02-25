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

	if (WeaponData.IsNull() == false)
	{
		FDemolitionWeaponData* weaponData = WeaponData.GetRow<FDemolitionWeaponData>("Data");
		if (weaponData != nullptr)
		{
			FireSound = weaponData->FireSound;
		}


	}
}



void AWeapon::Fire()
{
	if (FireSound != nullptr)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}
}
