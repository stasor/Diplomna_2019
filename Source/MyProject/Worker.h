// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Worker.generated.h"

UCLASS()
class MYPROJECT_API AWorker : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AWorker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
		int32 Health;

	UPROPERTY(EditAnywhere)
		int32 HPDecreseSuffocate;

	bool IsSuffocating;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// The animation to play while running around
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		class UPaperFlipbook* MovingAnimation;

	// The animation to play while idle (standing still)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animations)
		class UPaperFlipbook* IdleAnimation;
	
	void SetSuffocating(bool change);

	UPROPERTY(VisibleAnywhere)
		class UBoxComponent* Box;

};
