// Fill out your copyright notice in the Description page of Project Settings.


#include "Teleport.h"
#include "SnakeBase.h"
#include "SnakeElementBase.h"

// Sets default values
ATeleport::ATeleport()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void ATeleport::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATeleport::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATeleport::Interact(AActor* Interactor, bool bIsHead)
{
	if (bIsHead) 
	{
		auto Snake = Cast<ASnakeBase>(Interactor);
		if(IsValid(Snake))
		{
			Snake->SnakeElements[0]->SetActorLocation(FVector(0,0,0));

		}
	}
}

