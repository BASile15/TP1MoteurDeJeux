// Fill out your copyright notice in the Description page of Project Settings.

#include "Asteroide.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AAsteroide::AAsteroide()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->bAutoActivate = false;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->ProjectileGravityScale = 0.f;
}

// Called when the game starts or when spawned
void AAsteroide::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAsteroide::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAsteroide::InitDirection(const FVector& Direction)
{
	UE_LOG(LogTemp, Warning, TEXT("test Init Direction"));

	if (ProjectileMovement)
	{
		UE_LOG(LogTemp, Warning, TEXT("ProjectileMovement OK"));
		ProjectileMovement->Velocity = Direction * Speed;
		ProjectileMovement->Activate();
		UE_LOG(LogTemp, Warning, TEXT("Asteroide velocity set to %s"), *ProjectileMovement->Velocity.ToString());
	}
}
