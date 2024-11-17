// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributesComponent.h"
#include "Attributes.h"

// Sets default values

// Called when the game starts or when spawned
void AAttributesComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

AAttributesComponent::AAttributesComponent()
{

	UAttributesMap = TMap<FName, UAttributes*>();
	AttributesMap = TMap<FName, Attributes<float>>();


}




//UObjects

bool AAttributesComponent::HasUAttrib(FName Attrib) const
{
	return UAttributesMap.Contains(Attrib);
}


void AAttributesComponent::AddUAttrib(FName Attrib, float NewVal)
{
	if (HasUAttrib(Attrib))
	{
		return;
	}
	else
	{
		UAttributes* AddedAttrib = NewObject<UAttributes>(this);
		AddedAttrib->SetValue(NewVal);

		UAttributesMap.Add(Attrib, AddedAttrib);
	}
}

float AAttributesComponent::GetUAttrib(FName Attrib) const
{
	if (HasUAttrib(Attrib))
	{
		return UAttributesMap[Attrib]->GetValue();
	}
	else
	{
		return NULL;
	}
}



void AAttributesComponent::ModifyUAttrib(FName Attrib, float NewVal)
{
	if (HasUAttrib(Attrib))
	{
		UAttributesMap[Attrib]->SetValue(NewVal);
	}
}


//Templates

bool AAttributesComponent::HasAttrib(FName Attrib) const
{
	return AttributesMap.Contains(Attrib);
}


void AAttributesComponent::AddAttrib(FName Attrib, float NewVal)
{
	if(HasAttrib(Attrib))
	{
		return;
	}
	else
	{
		AttributesMap.Add(Attrib, Attributes<float>(NewVal));
	}
	
}

float AAttributesComponent::GetAttrib(FName Attrib) const
{
	if (HasAttrib(Attrib))
	{
		return AttributesMap.Find(Attrib)->GetValue();
	}
	else
	{
		return NULL;
	}
	
}



void AAttributesComponent::ModifyAttrib(FName Attrib, float NewVal)
{
	if (HasAttrib(Attrib))
	{
		AttributesMap.Find(Attrib)->SetValue(NewVal);
	}
	
}


void AAttributesComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

