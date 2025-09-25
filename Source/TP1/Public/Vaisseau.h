// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Vaisseau.generated.h"

UCLASS()
class TP1_API AVaisseau : public APawn
{
	GENERATED_BODY()

public:
	AVaisseau();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ShipMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float MoveSpeed = 400.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Combat")
	TSubclassOf<class AProjectile> ProjectileClass;

private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	
	FVector CurrentVelocity;

	UPROPERTY(EditDefaultsOnly, Category="Combat")
	FVector MuzzleOffset = FVector(100.f, 0.f, 0.f);

	UFUNCTION(BlueprintCallable)
	void Tir();

	
	
};
