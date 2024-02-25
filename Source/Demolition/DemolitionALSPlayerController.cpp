// Fill out your copyright notice in the Description page of Project Settings.


#include "DemolitionALSPlayerController.h"
#include "Runtime/UMG/Public/UMG.h"
#include "DemolitionALSCharacter.h"

void ADemolitionALSPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (IsLocalPlayerController() && WeaponHUDWidgetTemplate)
	{
		if (!WeaponHUDWidgetInstance)
		{
			WeaponHUDWidgetInstance = CreateWidget(this, WeaponHUDWidgetTemplate);
		}

		if (!WeaponHUDWidgetInstance->GetIsVisible())
		{
			WeaponHUDWidgetInstance->AddToViewport();
		}
	}
}

void ADemolitionALSPlayerController::FireAction(const FInputActionValue& Value)
{
	if (Value.Get<bool>() == true)
	{
		ADemolitionALSCharacter* demolitionCharacter = Cast<ADemolitionALSCharacter>(PossessedCharacter);
		if (demolitionCharacter)
		{
			demolitionCharacter->UseWeapon();
		}
	}
	
}

