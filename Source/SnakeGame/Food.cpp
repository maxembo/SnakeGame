#include "Food.h"
#include "SnakeBase.h"
#include "PlayerPawnBase.h"

AFood::AFood()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFood::BeginPlay()
{
	Super::BeginPlay();
	RandomFood();
}

void AFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFood::Interact(AActor* Interactor, bool bIsHead)
{
	if(bIsHead)
	{
		auto Snake = Cast<ASnakeBase>(Interactor);
		
		if(IsValid(Snake))
		{
			Snake->AddSnakeElement();
			RandomFood();
		}
	}
}

FVector2D AFood::GetRandomPos()
{
	float foodX = FMath::FRandRange(-1350, 1310);
	float foodY = FMath::FRandRange(-1630, 1690);
	
	return FVector2D(foodX, foodY);
}

void AFood::RandomFood()
{
	FVector spawnFood = FVector(GetRandomPos(), foodZ);
	SetActorLocation(spawnFood);
}


