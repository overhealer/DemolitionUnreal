// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/ALSPlayerController.h"
#include "Runtime/UMG/Public/UMG.h"
#include "DemolitionALSPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class DEMOLITION_API ADemolitionALSPlayerController : public AALSPlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay();

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = UI)
	TSubclassOf<UUserWidget> WeaponHUDWidgetTemplate;

	UPROPERTY()
	UUserWidget* WeaponHUDWidgetInstance;

	UFUNCTION()
	void FireAction(const FInputActionValue& Value);


};
