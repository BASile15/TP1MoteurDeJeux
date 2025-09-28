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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveSpeed = 400.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<class AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Vie = 3;
	
	UFUNCTION(BlueprintCallable)
	float GetPtsDeVie() const;
	
	UFUNCTION(BlueprintCallable)
	float GetScore() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Score;

private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	
	FVector CurrentVelocity;

	UPROPERTY(EditDefaultsOnly, Category="Combat")
	FVector MuzzleOffset = FVector(100.f, 0.f, 0.f);

	UFUNCTION(BlueprintCallable)
	void Tir();

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable, Category="Gameplay")
	void AjouterScore(int nbpoints);
};
