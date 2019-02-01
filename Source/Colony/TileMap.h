// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TileMap.generated.h"

UCLASS()
class COLONY_API ATileMap : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATileMap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/*
	TArray<TArray<FVector>> TileMap;

	TArray <FVector> Tiles;
	FVector Vector1;
	FVector Vector2;
	FVector Vector3;
	FVector Vector4;
	FVector Vector5;
	FVector Vector6;
	FVector Vector7;
	FVector Vector8;
	FVector Vector9;
	FVector Vector10;
	FVector Vector11;
	FVector Vector12;
	FVector Vector13;
	FVector Vector14;
	FVector Vector15;
	FVector Vector16;
	*/

	struct FVector Tiles[16][16];

	UClass* RoomClass;
};
