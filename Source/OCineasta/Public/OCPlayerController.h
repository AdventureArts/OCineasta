

#pragma once

#include "GameFramework/PlayerController.h"
#include "OCDefaultPawn.h"
#include "OCPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class OCINEASTA_API AOCPlayerController : public APlayerController
{
	GENERATED_UCLASS_BODY()

	FVector2D mouseLocation;

	float mouseSpeed;

public:

	FVector2D GetMouseLocation() const;

	float GetMouseSpeed() const;

	void SetMouseSpeed(float speed);

protected:

	virtual void BeginPlay();

	virtual void SetupControllerInputComponent(UInputComponent* InputComponent);
	
	virtual void mouseX(float input);
	virtual void mouseY(float input);
	virtual void forward(float input);
	virtual void right(float input);

};
