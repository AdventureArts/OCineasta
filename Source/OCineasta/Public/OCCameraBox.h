

#pragma once

#include "GameFramework/Actor.h"
#include "OCCameraBox.generated.h"

/**
*
*/
UCLASS()
class OCINEASTA_API AOCCameraBox : public AActor
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TSubobjectPtr<class UBoxComponent> cameraLimits;


public:



protected:

	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION()
	virtual void BeginOverlap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	virtual void EndOverlap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
