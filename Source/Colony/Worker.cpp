// Fill out your copyright notice in the Description page of Project Settings.

#include "Worker.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"


// Sets default values
AWorker::AWorker()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
	RootComponent = Box;

	Image = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Image"));
	Image->SetupAttachment(Box);

	IsSuffocating = false;
}

// Called when the game starts or when spawned
void AWorker::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWorker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsSuffocating) {
		Health -= HPDecreseSuffocate * DeltaTime;
	}

	if (Health <= 0) {
		Destroy();
	}

}

// Called to bind functionality to input
void AWorker::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AWorker::SetSuffocating(bool change)
{
	IsSuffocating = change;
}

