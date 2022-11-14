#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Food.h"
#include "Bonuses.h"
#include "PlayerPawnBase.generated.h"

class UCameraComponent;
class ASnakeBase;

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
