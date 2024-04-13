// Fill out your copyright notice in the Description page of Project Settings.


#include "LinecastWeapon.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "DemolitionALSCharacter.h"

void ALinecastWeapon::Fire()
{
	Super::Fire();

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		ADemolitionALSCharacter* Player = Cast<ADemolitionALSCharacter>(GetOwner());
		if (Player)
		{
			// MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
			APlayerCameraManager* PlayerCamera = Player->GetLocalViewingPlayerController()->PlayerCameraManager;
			const FVector StartLocation = PlayerCamera->GetCameraLocation()/*GetActorLocation()*/;
			const FVector EndLocation = PlayerCamera->GetCameraLocation() + PlayerCamera->GetActorForwardVector() * 3000.0f;
			FHitResult HitResult;

			FCollisionQueryParams QueryParams;
			QueryParams.AddIgnoredActor(this);
			QueryParams.AddIgnoredActor(Owner);

			World->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, TraceChannelProperty, QueryParams);
			//DrawDebugLine(World, StartLocation, EndLocation, FColor(255, 255, 0), false, -1, 0, 12);

			if (HitResult.GetActor() != nullptr)
			{
				//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Shot in " + HitResult.ImpactPoint.ToString()));
				UGameplayStatics::ApplyDamage(HitResult.GetActor(), WeaponDataRow->BaseDamage, Player->GetInstigatorController(), Player, WeaponDataRow->DamageType);
				if (HitEmitter)
				{
					UGameplayStatics::SpawnEmitterAtLocation(World, HitEmitter, HitResult.ImpactPoint, HitResult.ImpactNormal.Rotation());
				}
			}
		}

	}
}
