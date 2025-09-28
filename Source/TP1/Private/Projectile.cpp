// Fill out your copyright notice in the Description page of Project Settings.

#include "Projectile.h"
#include "Asteroide.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"


AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
	MeshComp->SetCollisionProfileName("OverlapAllDynamic");
	MeshComp->SetGenerateOverlapEvents(true);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;

	InitialLifeSpan = 3.0f;
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	UBoxComponent* BoxCollider = FindComponentByClass<UBoxComponent>();
	if (BoxCollider)
	{
		BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::OnOverlapBegin);
	}
}

void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProjectile::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) 
{
	if (OtherActor && OtherActor != this)
	{
		AAsteroide* Asteroide = Cast<AAsteroide>(OtherActor);
		if (Asteroide)
		{
			Asteroide->Vie--;
			if (Asteroide->Vie<=0)
			{
				Asteroide->Destroy();
			}
			Destroy();
		}
	}
}




