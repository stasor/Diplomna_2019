// Fill out your copyright notice in the Description page of Project Settings.

#include "TileMap.h"
#include "Room.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


// Sets default values
ATileMap::ATileMap()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	/*
	Tiles.Add(Vector1);
	Tiles.Add(Vector2);
	Tiles.Add(Vector3);
	Tiles.Add(Vector4);
	Tiles.Add(Vector5);
	Tiles.Add(Vector6);
	Tiles.Add(Vector7);
	Tiles.Add(Vector8);
	Tiles.Add(Vector9);
	Tiles.Add(Vector10);
	Tiles.Add(Vector11);
	Tiles.Add(Vector12);
	Tiles.Add(Vector13);
	Tiles.Add(Vector14);
	Tiles.Add(Vector15);
	Tiles.Add(Vector16);

	for (int32 i = 0; i < Tiles.Num(); i++) {
		Tiles[i] 
	}
	*/

	static ConstructorHelpers::FClassFinder<ARoom>
		RoomBP(TEXT("Blueprint'/Game/Blueprints/RoomBP.RoomBP_C'"));
	if (RoomBP.Succeeded() == true) {
		RoomClass = (UClass*)RoomBP.Class;
	}

	for (int32 i = 0; i < 16; i++)
	{
		for (int32 j = 0; j < 16; j++) 
		{
			Tiles[i][j] = FVector(i * 62.5, j * 62.5, 0.f);

		}
	}

}

// Called when the game starts or when spawned
void ATileMap::BeginPlay()
{
	Super::BeginPlay();
	
	for (int32 i = 0; i < 16; i++)
	{
		for (int32 j = 0; j < 16; j++)
		{
			FActorSpawnParameters ActorSpawnParams;
			GetWorld()->SpawnActor<ARoom>(RoomClass, Tiles[i][j], FRotator(0.f, 0.f, 0.f), ActorSpawnParams);
		}
	}
}

// Called every frame
void ATileMap::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

