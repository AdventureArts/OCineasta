

#include "OCineasta.h"
#include "OCPlayerController.h"


AOCPlayerController::AOCPlayerController(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	InputComponent = ConstructObject<UInputComponent>(UInputComponent::StaticClass(), this, TEXT("ControllerInputComponent"));
}


void AOCPlayerController::BeginPlay()
{
	SetupControllerInputComponent(InputComponent);
}

void AOCPlayerController::SetupControllerInputComponent(UInputComponent* InputComponent)
{
	check(InputComponent);

	InputComponent->BindAxis("mouseX", this, &AOCPlayerController::mouseX);
	InputComponent->BindAxis("mouseY", this, &AOCPlayerController::mouseY);
	InputComponent->BindAxis("forward", this, &AOCPlayerController::forward);
	InputComponent->BindAxis("right", this, &AOCPlayerController::right);
}

void AOCPlayerController::mouseX(float input)
{

}

void AOCPlayerController::mouseY(float input)
{

}

void AOCPlayerController::forward(float input)
{
	FVector viewDirection = GetControlRotation().Vector().SafeNormal();

	AOCDefaultPawn *OCPawn = StaticCast<AOCDefaultPawn*>(GetPawn());

	if (OCPawn) OCPawn->setForwardSpeed(input);
}

void AOCPlayerController::right(float input)
{
	FRotator viewRotator = GetControlRotation().Add(0.f, 90.f, 0.f);
	FVector viewDirection = viewRotator.Vector().SafeNormal();

	AOCDefaultPawn *OCPawn = StaticCast<AOCDefaultPawn*>(GetPawn());

	if (OCPawn) OCPawn->setRightSpeed(input);
}