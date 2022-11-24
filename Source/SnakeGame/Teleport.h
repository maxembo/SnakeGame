
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "Teleport.generated.h"


class ASnakeBase;
class ASnakeElementBase;
UCLASS()
class SNAKEGAME_API ATeleport : public AActor,public IInteractable
{
	GENERATED_BODY()
	
public:	
	ATeleport();

	UPROPERTY(EditAnywhere,Category = "Teleport")
		ATeleport* otherTeleport;

	UPROPERTY()
		bool teleport;
		
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void Interact(AActor* Interactor, bool bIsHead) override;

	void EnterTeleport(AActor* overlappedActor, AActor* otherActor);

	void ExitTeleport(AActor* overlappedActor, AActor* otherActor);
};
