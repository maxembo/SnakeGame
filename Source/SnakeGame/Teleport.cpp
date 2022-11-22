
#include "Teleport.h"
#include "SnakeBase.h"
#include "SnakeElementBase.h"

ATeleport::ATeleport()
{
	PrimaryActorTick.bCanEverTick = true;
	OnActorBeginOverlap.AddDynamic(this,&ATeleport::EnterTeleport);
	OnActorBeginOverlap.AddDynamic(this,&ATeleport::ExitTeleport);

	teleport = false;
}

void ATeleport::BeginPlay()
{
	Super::BeginPlay();
	
}

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
			EnterTeleport(Snake,Interactor);
			ExitTeleport(Snake, Interactor);
		}
	}
}

void ATeleport::EnterTeleport(AActor* overlappedActor, AActor* otherActor)
{
	if (otherTeleport)
	{
		auto Snake = Cast<ASnakeBase>(otherActor);
		if (Snake && !otherTeleport->teleport)
		{
			teleport = true;
			Snake->SnakeElements[0]->SetActorLocation(otherTeleport->GetActorLocation());
		}
	}
}

void ATeleport::ExitTeleport(AActor* overlappedActor, AActor* otherActor)
{
	if (otherTeleport && !teleport)
	{
		otherTeleport->teleport = false;
	}
}

