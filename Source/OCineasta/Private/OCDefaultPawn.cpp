

#include "OCineasta.h"
#include "OCDefaultPawn.h"


AOCDefaultPawn::AOCDefaultPawn(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	MovementComponent->MaxSpeed = 250.f;
	MovementComponent->Acceleration = 1000.f;
	MovementComponent->Deceleration = 1000.f;

	cameraSupport = PCIP.CreateDefaultSubobject<USpringArmComponent>(this, TEXT("CameraSupport"));
	cameraSupport->AttachTo(RootComponent);
	cameraSupport->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	cameraSupport->TargetArmLength = 0.f;
	cameraSupport->bEnableCameraLag = true;
	cameraSupport->bEnableCameraRotationLag = true;
	cameraSupport->CameraLagSpeed = 8.f;
	cameraSupport->CameraRotationLagSpeed = 8.f;
	cameraSupport->bUseControllerViewRotation = true;

	playerCamera = PCIP.CreateDefaultSubobject<UCameraComponent>(this, TEXT("PlayerCamera"));
	playerCamera->AttachTo(cameraSupport, USpringArmComponent::SocketName);
	playerCamera->bUseControllerViewRotation = false;
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