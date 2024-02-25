#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.h"
#include "WeaponPickup.generated.h"

UCLASS()
class DEMOLITION_API AWeaponPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponPickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable)
	AWeapon* GetWeapon();

	UFUNCTION(BlueprintCallable)
	void OnPickup();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon Pickup")
	TSubclassOf<class AWeapon> WeaponClass;

	AWeapon* WeaponInstance;
};
