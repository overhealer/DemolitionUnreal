// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SkeletalMeshComponent.h"
#include "DemolitionCharacter.h"
#include "Weapon.generated.h"

UCLASS()
class DEMOLITION_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

	void Detach();

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class ADemolitionProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	USoundBase* FireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	UAnimMontage* FireAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector MuzzleOffset;

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void Fire(ADemolitionCharacter* character);
};
