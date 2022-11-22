// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "Teleport.generated.h"


class ASnakeBase;
class ASnakeElementBase;
UCLASS()
class SNAKEGAME_API ATeleport : public AActor,public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATeleport();

	UPROPERTY(EditAnywhere,Category = "Teleport")
		ATeleport* otherTeleport;

	UPROPERTY()
		bool teleport;
		
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact(AActor* Interactor, bool bIsHead) override;

	void EnterTeleport(AActor* overlappedActor, AActor* otherActor);

	void ExitTeleport(AActor* overlappedActor, AActor* otherActor);
};
