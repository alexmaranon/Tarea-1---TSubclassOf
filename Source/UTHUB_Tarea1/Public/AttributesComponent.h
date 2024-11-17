// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Attributes.h"
#include "AttributesComponent.generated.h"


UCLASS()
class UTHUB_TAREA1_API AAttributesComponent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAttributesComponent();

private:

	//Declare the attributes we want
	TMap<FName, Attributes<float>> AttributesMap;

	TMap<FName, UAttributes*> UAttributesMap;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:	
	// Called every frame

	//UObject
	UFUNCTION(BlueprintCallable, Category = "UAttributes")
	void AddUAttrib(FName Attrib, float NewVal);

	UFUNCTION(BlueprintCallable, Category = "UAttributes")
	float GetUAttrib(FName Attrib) const;

	UFUNCTION(BlueprintCallable, Category = "UAttributes")
	bool HasUAttrib(FName Attrib) const;

	UFUNCTION(BlueprintCallable, Category = "UAttributes")
	void ModifyUAttrib(FName Attrib, float NewVal);






	//Template
	UFUNCTION(BlueprintCallable, Category = "TAttributes")
	void AddAttrib(FName Attrib, float NewVal);

	UFUNCTION(BlueprintCallable, Category = "TAttributes")
	float GetAttrib(FName Attrib) const;

	UFUNCTION(BlueprintCallable, Category = "TAttributes")
	bool HasAttrib(FName Attrib) const;

	UFUNCTION(BlueprintCallable, Category = "TAttributes")
	void ModifyAttrib(FName Attrib, float NewVal);


	

};
