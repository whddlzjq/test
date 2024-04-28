// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereSpawner.h"
#include "MySphere.h"
#include "Engine/World.h"
#include "TimerManager.h"


// Sets default values
ASphereSpawner::ASphereSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ASphereSpawner::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ASphereSpawner::SpawnSphere, 10.0f, false);
}

void ASphereSpawner::SpawnSphere()
{
    // Define the spawn parameters
    FActorSpawnParameters SpawnParams;
    SpawnParams.Owner = this;
    SpawnParams.Instigator = GetInstigator();

    // Define the spawn location and rotation (arbitrary example)
    FVector SpawnLocation(0.0f, 0.0f, 0.0f); // Adjust as needed
    FRotator SpawnRotation(0.0f, 0.0f, 0.0f);

    // Spawn the MySphere actor
    AMySphere* SpawnedSphere = GetWorld()->SpawnActor<AMySphere>(AMySphere::StaticClass(), SpawnLocation, SpawnRotation, SpawnParams);

    if (SpawnedSphere)
    {
        // Log or perform any other actions upon successful spawn
        UE_LOG(LogTemp, Warning, TEXT("Sphere spawned successfully."));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to spawn sphere."));
    }
}
