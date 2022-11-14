
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "Food.generated.h"


UCLASS()
class SNAKEGAME_API AFood : public AActor,public IInteractable
{
	GENERATED_BODY()
	
public:	
	AFood();

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AFood>FoodClass;

	float foodZ = -10.f;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void Interact(AActor* Interactor,bool bIsHead) override;

	FVector2D GetRandomPos();

	void RandomFood();

};
