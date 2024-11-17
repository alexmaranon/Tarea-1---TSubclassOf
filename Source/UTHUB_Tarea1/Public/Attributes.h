// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Attributes.generated.h"

//Template to obtain the Get, Set and Create more Attributes

template<typename T>
class Attributes 
{
private:

	T AttribVal;

public:

	Attributes():AttribVal(T()){};

	Attributes(T InValue)
	{
		AttribVal = InValue;
	}


	void SetValue(const T& NewVal)
	{
		AttribVal = NewVal;
	}


	T GetValue() const
	{
		return AttribVal;
	}



protected:
};


UCLASS()
class UTHUB_TAREA1_API UAttributes : public UObject
{
	GENERATED_BODY()


private:
	float AttribVal;

public:

	UAttributes():AttribVal(0.f){};


	UFUNCTION(BlueprintCallable, Category ="Attributes")
	void SetValue(float InValue)
	{
		AttribVal = InValue;
	}

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	float GetValue() const
	{
		return AttribVal;
	}


	
};
