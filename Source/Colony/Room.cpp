// Fill out your copyright notice in the Description page of Project Settings.

#include "Room.h"
#include "Worker.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"


// Sets default values
ARoom::ARoom()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));

	Image = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("image"));

	RootComponent = Box;
	Image->SetupAttachment(Box);

	CurrentO2 = 10.f;
}

// Called when the game starts or when spawned
void ARoom::BeginPlay()
{
	Super::BeginPlay();
	
	Box->OnComponentBeginOverlap.AddDynamic(this, &ARoom::OnBeginOverlap);
}

// Called every frame
void ARoom::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentO2 > 0.f) {
		CurrentO2 -= O2Decrease * DeltaTime;
	}
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%f"), CurrentO2));
}

void ARoom::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("Entered!")));

	if (Cast<AWorker>(OtherActor) != NULL) {

		AWorker* Worker = Cast<AWorker>(OtherActor);

		if (CurrentO2 <= 3.5f) {
			Worker->SetSuffocating(true);
		}

		if (CurrentO2 > 3.5f) {
			Worker->SetSuffocating(false);
		}
	}

}

