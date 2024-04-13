// Fill out your copyright notice in the Description page of Project Settings.


#include "DemolitionALSCharacter.h"
#include "Runtime/UMG/Public/UMG.h"
#include <ALSV4_CPP/Public/Library/ALSCharacterEnumLibrary.h>

void ADemolitionALSCharacter::EquipWeapon(AWeapon* weapon)
{
	if (CurrentWeapon)
	{
		CurrentWeapon->Destroy();
	}

	CurrentWeapon = weapon;
	CurrentWeapon->SetOwner(this);
	FName AttachBone;
	AttachBone = TEXT("VB RHS_ik_hand_gun");
	CurrentWeapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, AttachBone);
	FDemolitionWeaponData* weaponData = weapon->WeaponData.GetRow<FDemolitionWeaponData>("Data");
	if (weaponData != nullptr)
	{
		SetOverlayState(weaponData->PlayerOverlayState);
	}
	CurrentWeapon->OnWeaponPickup();
}

void ADemolitionALSCharacter::UseWeapon()
{
	if (RotationMode != EALSRotationMode::Aiming)
		return;

	if (CurrentWeapon == nullptr)
		return;

	CurrentWeapon->Fire();

	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Weapon Used"));
}
