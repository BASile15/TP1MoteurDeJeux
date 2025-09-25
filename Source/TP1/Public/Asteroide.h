// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Asteroide.generated.h"

UCLASS()
class TP1_API AAsteroide : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAsteroide();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float Speed = 5.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components")
	class UProjectileMovementComponent* ProjectileMovement;

	UFUNCTION(BlueprintCallable, Category="Asteroide")
	void InitDirection(const FVector& Direction);
	
};
