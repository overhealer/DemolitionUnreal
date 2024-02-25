// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponPickup.h"

// Sets default values
AWeaponPickup::AWeaponPickup()
{
 	
}

// Called when the game starts or when spawned
void AWeaponPickup::BeginPlay()
{
	Super::BeginPlay();
	FActorSpawnParameters ActorSpawnParams;
	ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	WeaponInstance = GetWorld()->SpawnActor<AWeapon>(WeaponClass, GetTransform(), ActorSpawnParams);
	WeaponInstance->AttachToActor(this, FAttachmentTransformRules::SnapToTargetIncludingScale);
}

AWeapon* AWeaponPickup::GetWeapon()
{
	return WeaponInstance;
}

void AWeaponPickup::OnPickup()
{
	//WeaponInstance->Destroy();
	Destroy();
}

