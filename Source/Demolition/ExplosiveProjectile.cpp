// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplosiveProjectile.h"
#include "ExplosionComponent.h"

AExplosiveProjectile::AExplosiveProjectile()
{
	ExplosionComp = CreateDefaultSubobject<UExplosionComponent>(TEXT("Explosion Component"));
}

void AExplosiveProjectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		Explode();
	}
}

void AExplosiveProjectile::Explode()
{
	if (ExplosionComp != nullptr)
	{
		ExplosionComp->Explode(GetActorLocation());
	}
	Destroy();
}
