
#include "DestroySnake.h"
#include "SnakeBase.h"

ADestroySnake::ADestroySnake()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ADestroySnake::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADestroySnake::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADestroySnake::Interact(AActor* Interactor, bool bIsHead)
{
	if (bIsHead) 
	{
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake))
		{
			Snake->Destroy();
			Snake->KillSnake();
		}
	}
}

