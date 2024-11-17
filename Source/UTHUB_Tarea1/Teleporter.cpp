// Fill out your copyright notice in the Description page of Project Settings.


#include "Teleporter.h"
#include "Sound/SoundBase.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ATeleporter::ATeleporter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATeleporter::TeleportFunction()
{
	if (Teleporter) 
	{
		//Get the other teleporters location
		FVector TeleportLocation = Teleporter->GetActorLocation();
		if (CollisionActor) 
		{
			//Add players height to the spawnpoint
			FVector PlayersSize = CollisionActor->GetComponentsBoundingBox().GetExtent();
			TeleportLocation.Z += PlayersSize.Z;
			CollisionActor->SetActorLocation(TeleportLocation);

			//Play sound when tp
			if (TeleporterSound)
			{
				UGameplayStatics::PlaySoundAtLocation(this, TeleporterSound, TeleportLocation);
			}
			//DestroyVFX
			if (TeleporterVFX)
			{
				UParticleSystemComponent* TeleporterEffect = UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), TeleporterVFX, Teleporter->GetActorLocation(), Teleporter->GetActorRotation());

				FTimerHandle Timer;
				GetWorld()->GetTimerManager().SetTimer(Timer, [TeleporterEffect]()
					{
						if (TeleporterEffect)
						{
							TeleporterEffect->DestroyComponent();
						}
					}, 1.5f, false);

			}
		}		
	}
}

// Called when the game starts or when spawned
void ATeleporter::BeginPlay()
{
	Super::BeginPlay();
	if (Teleporter) 
	{
		//If the connected teleporter is not assigned auto assign
		if (Teleporter->Teleporter == NULL) 
		{
			//Auto asign this teleporter to the selected
			Teleporter->Teleporter = this;
		}
		
	}
	
}

// Called every frame
void ATeleporter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


