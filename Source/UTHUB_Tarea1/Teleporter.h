// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Teleporter.generated.h"

UCLASS()
class UTHUB_TAREA1_API ATeleporter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATeleporter();

	UPROPERTY(EditInstanceOnly, Category = "Teleporters")
	ATeleporter* Teleporter;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	AActor* CollisionActor;
	
	UPROPERTY(EditInstanceOnly, Category = "Teleporters")
	USoundBase* TeleporterSound;

	UPROPERTY(EditInstanceOnly, Category = "Teleporters")
	UParticleSystem* TeleporterVFX;

	UFUNCTION(BlueprintCallable)
	void TeleportFunction();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;



};
