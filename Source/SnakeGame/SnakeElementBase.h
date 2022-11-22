// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "SnakeElementBase.generated.h"


class UStaticMeshComponent;
class ASnakeBase;

UCLASS()
class SNAKEGAME_API ASnakeElementBase : public AActor,public IInteractable
{
	GENERATED_BODY()
	
public:	
	ASnakeElementBase();

	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite)
		UStaticMeshComponent* MeshComponent;
		
	UPROPERTY()
		ASnakeBase* SnakeOwner;

	

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintNativeEvent)
		void SetFirstElementType();
		void SetFirstElementType_Implementation();
	
	virtual void Interact(AActor* Interactor,bool bIsHead) override;

	UFUNCTION()
		void HandleBeginOverlap(UPrimitiveComponent* OverlappedComponent, 
								AActor* OtherActor, 
								UPrimitiveComponent* OtherComp, 
								int32 otherBodyIndex, 
								bool bFromSweep,const FHitResult &SweepResult);

	UFUNCTION()
		void ToggleCollision();
};
