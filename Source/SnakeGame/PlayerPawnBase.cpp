
#include "PlayerPawnBase.h"
#include "Engine/Classes/Camera/CameraComponent.h"
#include "SnakeBase.h"
#include "Bonuses.h"
#include "Components/InputComponent.h"

APlayerPawnBase::APlayerPawnBase()
{
	PrimaryActorTick.bCanEverTick = true;
	
	PawnCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PawnCamera"));
	RootComponent = PawnCamera;

	randomTimer = FMath::FRandRange(20.f, 35.f);
	foodZ = 0.f;
}


void APlayerPawnBase::BeginPlay()
{
	Super::BeginPlay();
	SetActorRotation(FRotator(-90,0,0));
	CreateSnakeActor();
	CreateFoodActor();
	CreateBonusActor();
}


void APlayerPawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);


	PlayerInputComponent->BindAxis("Vertical", this, &APlayerPawnBase::HandlePlayerVerticalInput);
	PlayerInputComponent->BindAxis("Horizontal", this, &APlayerPawnBase::HandlePlayerHorizontalInput);
}

void APlayerPawnBase::CreateSnakeActor()
{
	SnakeActor = GetWorld()->SpawnActor<ASnakeBase>(SnakeActorClass, FTransform());
}

void APlayerPawnBase::HandlePlayerVerticalInput(float value)
{
	if (IsValid(SnakeActor) && SnakeActor->turnSnake)
	{
		if (value > 0 && SnakeActor->LastMoveDirection != EMovementDirection::DOWN)
		{
			SnakeActor->LastMoveDirection = EMovementDirection::UP;
			SnakeActor->turnSnake = false;

		}
		else if(value < 0 && SnakeActor->LastMoveDirection != EMovementDirection::UP)
		{
			SnakeActor->LastMoveDirection = EMovementDirection::DOWN;
			SnakeActor->turnSnake = false;
		}
	}
}

void APlayerPawnBase::HandlePlayerHorizontalInput(float value)
{
	if (IsValid(SnakeActor) && SnakeActor->turnSnake)
	{
		if (value > 0 && SnakeActor->LastMoveDirection != EMovementDirection::LEFT)
		{
			SnakeActor->LastMoveDirection = EMovementDirection::RIGHT;
			SnakeActor->turnSnake = false;
		
		}
		else if (value < 0 && SnakeActor->LastMoveDirection != EMovementDirection::RIGHT)
		{
			SnakeActor->LastMoveDirection = EMovementDirection::LEFT;
			SnakeActor->turnSnake = false;
		
		}
	}
}

void APlayerPawnBase::CreateFoodActor()
{
	GetWorld()->SpawnActor<AFood>(FoodClass, FTransform());
}


void APlayerPawnBase::CreateBonusActor()
{
	if(timerSpawn.IsValid())
		GetWorldTimerManager().ClearTimer(timerSpawn);

	FVector spawnBonus = FVector(GetRandom(), foodZ);

	GetWorld()->SpawnActor<ABonuses>(BonusClass, spawnBonus,FRotator(0,0,0));

	GetWorldTimerManager().SetTimer(timerSpawn, this,
		&APlayerPawnBase::CreateBonusActor,
		1.0f,
		true,
		randomTimer);
}






