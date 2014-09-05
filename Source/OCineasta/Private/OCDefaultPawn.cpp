

#include "OCineasta.h"
#include "OCDefaultPawn.h"


AOCDefaultPawn::AOCDefaultPawn(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	
}

void AOCDefaultPawn::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	FVector directionMovement;

	directionMovement.X = forwardSpeed;
	directionMovement.Y = rightSpeed;
	directionMovement.Normalize();

	AddMovementInput(directionMovement);
}

void AOCDefaultPawn::setForwardSpeed(float speed)
{
	forwardSpeed = speed;
}

void AOCDefaultPawn::setRightSpeed(float speed)
{
	rightSpeed = speed;
}