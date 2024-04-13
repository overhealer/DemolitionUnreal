// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Particles/ParticleSystem.h"
#include "Sound/SoundBase.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"
#include "GeometryCollection/GeometryCollectionComponent.h"  
#include "Field/FieldSystemActor.h"  
#include "ExplosionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DEMOLITION_API UExplosionComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UExplosionComponent();

	void Explode(FVector Position);

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float BaseDamage;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MinimumDamage;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float InnerRadius;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float OuterRadius;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<class UDamageType> DamageType;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UParticleSystem* ExplosionParticle;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	USoundBase* ExplosionSound;
};
