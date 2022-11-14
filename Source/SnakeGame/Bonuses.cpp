// Fill out your copyright notice in the Description page of Project Settings.


#include "Bonuses.h"
#include "SnakeBase.h"
#include "Food.h"
#include "Interactable.h"

// Sets default values
ABonuses::ABonuses()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABonuses::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABonuses::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void ABonuses::Interact(AActor* Interactor, bool bIsHead)
{
	if (bIsHead)
	{
		auto Snake = Cast<ASnakeBase>(Interactor);
		
		if (IsValid(Snake)) 
		{
			Snake->SpeedOrSlowdown();
			Destroy();
		}
	}
}


