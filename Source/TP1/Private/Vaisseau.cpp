// Fill out your copyright notice in the Description page of Project Settings.

#include "Public/Vaisseau.h"
#include "Projectile.h"
#include "Engine/World.h"


// Sets default values
AVaisseau::AVaisseau()
{
	PrimaryActorTick.bCanEverTick = true;

	ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMesh;
}

// Called when the game starts or when spawned
void AVaisseau::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVaisseau::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!CurrentVelocity.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime);
		SetActorLocation(NewLocation);
	}
}

void AVaisseau::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AVaisseau::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AVaisseau::MoveRight);
	PlayerInputComponent->BindAction("Tir", IE_Pressed, this, &AVaisseau::Tir);
}

void AVaisseau::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		AddActorLocalOffset(FVector(Value * MoveSpeed * GetWorld()->DeltaTimeSeconds, 0, 0), true);
	}
}

void AVaisseau::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		AddActorLocalOffset(FVector(0, Value * MoveSpeed * GetWorld()->DeltaTimeSeconds, 0), true);
	}
}

void AVaisseau::Tir()
{
	UE_LOG(LogTemp, Warning, TEXT("Test Tir"));

	if (ProjectileClass)
	{
		FVector SpawnLocation = GetActorLocation() + GetActorForwardVector() * 100.f;
		FRotator SpawnRotation = GetActorRotation();

		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		SpawnParams.Instigator = GetInstigator();

		GetWorld()->SpawnActor<AProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, SpawnParams);
	}
}