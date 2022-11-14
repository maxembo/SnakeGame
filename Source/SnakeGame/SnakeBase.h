#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SnakeBase.generated.h"

class ASnakeElementBase;

UENUM()
enum class EMovementDirection 
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

UCLASS()
	class SNAKEGAME_API ASnakeBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ASnakeBase();

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<ASnakeElementBase>SnakeElementClass;
		
	UPROPERTY()
		float defaultSpeed;

	UPROPERTY()
		TArray<ASnakeElementBase*>SnakeElements;

	UPROPERTY(EditDefaultsOnly)
		float ElementSize;
	
	UPROPERTY()
		FTimerHandle TimerSpeed;

	UPROPERTY()
		EMovementDirection LastMoveDirection;

	UPROPERTY(EditDefaultsOnly)
		float MovementSpeed;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void AddSnakeElement(int ElementsNum = 1);
	
	UFUNCTION(BlueprintCallable)
		void Move();
	
	UFUNCTION()
		void SnakeElementOverlap(ASnakeElementBase* OverlappedElement, AActor* Other);

	UFUNCTION()
		void KillSnake();	

	UFUNCTION()
		void SpeedOrSlowdown();

	UFUNCTION()
		void SpeedReturn();
};
