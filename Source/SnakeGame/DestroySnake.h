#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "DestroySnake.generated.h"

UCLASS()
class SNAKEGAME_API ADestroySnake : public AActor,public IInteractable
{
	GENERATED_BODY()
	
public:	
	ADestroySnake();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void Interact(AActor* Interactor, bool bIsHead) override;

};
