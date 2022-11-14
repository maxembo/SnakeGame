#include "SnakeBase.h"
#include "SnakeElementBase.h"
#include "Food.h"

ASnakeBase::ASnakeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	ElementSize = 100.f;
	MovementSpeed = 0.4f;
	LastMoveDirection = EMovementDirection::RIGHT;
}

void ASnakeBase::BeginPlay()
{
	Super::BeginPlay();
	SetActorTickInterval(MovementSpeed);
	AddSnakeElement(5);
	

}
void ASnakeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
}

void ASnakeBase::AddSnakeElement(int ElementsNum)
{
	for (int i = 0; i < ElementsNum; i++) 
	{
		FVector NewLocation(SnakeElements.Num() * ElementSize, 0, 0);
		FTransform NewTransform(NewLocation);
		ASnakeElementBase* NewSnakeElem = GetWorld()->SpawnActor<ASnakeElementBase>
			(SnakeElementClass, NewTransform);
		
		NewSnakeElem->SnakeOwner = this;
		int32 ElemIndex = SnakeElements.Add(NewSnakeElem);
		if(ElemIndex == 0)
		{
			NewSnakeElem->SetFirstElementType();
		}
	}
	SnakeElements[SnakeElements.Num() - 1]->
		SetActorLocation(SnakeElements[SnakeElements.Num() - 2]->GetActorLocation());
}

void ASnakeBase::Move()
{
	FVector MovementVector(ForceInitToZero);

	switch(LastMoveDirection)
	{
	case EMovementDirection::UP:
		MovementVector.X += ElementSize;	break;
	case EMovementDirection::DOWN:
		MovementVector.X -= ElementSize;	break;
	case EMovementDirection::LEFT:
		MovementVector.Y += ElementSize;	break;
	case EMovementDirection::RIGHT:
		MovementVector.Y -= ElementSize;	break;
	}
	//AddActorWorldOffset(MovementVector);
	SnakeElements[0]->ToggleCollision();

	for(int i = SnakeElements.Num() - 1;i > 0; i--)
	{
		auto CurrentElement = SnakeElements[i];
		auto PrevElement = SnakeElements[i - 1];
		FVector PrevLocation = PrevElement->GetActorLocation();
		CurrentElement->SetActorLocation(PrevLocation);
	}

	SnakeElements[0]->AddActorWorldOffset(MovementVector);
	SnakeElements[0]->ToggleCollision();
}

void ASnakeBase::SnakeElementOverlap(ASnakeElementBase* OverlappedElement,AActor* Other)
{
	if(IsValid(OverlappedElement))
	{
		int32 ElemIndex;
		SnakeElements.Find(OverlappedElement, ElemIndex);
		bool bIsFirst = ElemIndex == 0;
		IInteractable* InteractableInterface = Cast<IInteractable>(Other);
		if(InteractableInterface)
		{
			InteractableInterface->Interact(this,bIsFirst);
		}
	}
}

void ASnakeBase::KillSnake()
{
	for(int i = SnakeElements.Num() - 1; i > 0;i--)
	{
		SnakeElements[i]->Destroy();
	}
}

void ASnakeBase::SpeedOrSlowdown()
{
	if(TimerSpeed.IsValid())
	GetWorldTimerManager().ClearTimer(TimerSpeed);

	MovementSpeed = FMath::FRandRange(0.1f,0.6f);

	SetActorTickInterval(MovementSpeed);
	GetWorldTimerManager().SetTimer(TimerSpeed, this,
									&ASnakeBase::SpeedReturn,
										 1.0f, 
										true,							
									10.0f);
}

void ASnakeBase::SpeedReturn()
{
	MovementSpeed = 0.4f;
	SetActorTickInterval(MovementSpeed);
}




