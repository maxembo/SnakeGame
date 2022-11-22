#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Food.h"
#include "Bonuses.h"
#include "PlayerPawnBase.generated.h"

class UCameraComponent;
class ASnakeBase;
class ASnakeElementBase;

UCLASS()
class SNAKEGAME_API APlayerPawnBase : public APawn
{
	GENERATED_BODY()

public:
	APlayerPawnBase();

	UPROPERTY(BlueprintReadWrite)
		UCameraComponent* PawnCamera;

	UPROPERTY(BlueprintReadWrite)
		ASnakeBase* SnakeActor;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ASnakeBase>SnakeActorClass;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AFood>FoodClass;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ABonuses>BonusClass;

	UPROPERTY()
		FTimerHandle timerSpawn;

	UPROPERTY()
		float randomTimer;

	UPROPERTY()
		float foodX;
	
	UPROPERTY()
		float foodY;
	
	UPROPERTY()
		float foodZ;

	FVector2D GetRandom()
	{
		foodX = FMath::FRandRange(-1350, 1310);
		foodY = FMath::FRandRange(-1630, 1690);
		return FVector2D(foodX, foodY);
	}

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UFUNCTION()
	void CreateSnakeActor();

	UFUNCTION()
		void HandlePlayerVerticalInput(float value);
	
	UFUNCTION()
		void HandlePlayerHorizontalInput(float value);
	
	UFUNCTION()
		void CreateFoodActor();
	
	UFUNCTION()
		void CreateBonusActor();
};
