

#pragma once

#include "GameFramework/DefaultPawn.h"
#include "OCDefaultPawn.generated.h"

/**
 * 
 */
UCLASS()
class OCINEASTA_API AOCDefaultPawn : public ADefaultPawn
{
	GENERATED_UCLASS_BODY()

	float forwardSpeed = 0.f;
	float rightSpeed = 0.f;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TSubobjectPtr<class USpringArmComponent> cameraSupport;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	TSubobjectPtr<class UCameraComponent> playerCamera;


public:

	void setForwardSpeed(float speed);
	void setRightSpeed(float speed);


protected:

	virtual void Tick(float DeltaSeconds) override;

};
