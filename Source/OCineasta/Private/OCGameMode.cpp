

#include "OCineasta.h"
#include "OCGameMode.h"


AOCGameMode::AOCGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	DefaultPawnClass = AOCDefaultPawn::StaticClass();
	HUDClass = AOCHUD::StaticClass();
	PlayerControllerClass = AOCPlayerController::StaticClass();
}


