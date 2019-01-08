// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Worker.generated.h"

UCLASS()
class COLONY_API AWorker : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AWorker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void SetSuffocating(bool change);

private:

	UPROPERTY(EditAnywhere)
		int32 Health;

	UPROPERTY(EditAnywhere)
		int32 HPDecreseSuffocate;

	bool IsSuffocating;

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* Box;

	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* Image;


};
