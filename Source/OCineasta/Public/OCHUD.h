

#pragma once

#include "GameFramework/HUD.h"
#include "OCPlayerController.h"
#include "OCHUD.generated.h"

/**
 * 
 */
UCLASS()
class OCINEASTA_API AOCHUD : public AHUD
{
	GENERATED_UCLASS_BODY()

	UTexture *cursorTexture;
	FVector2D cursorSize;
	FVector2D cursorLocation;
	FVector2D cursorCentre;
	
	FVector2D mouseLocation;

	FVector2D screenCentre;
	
public:

	FVector2D getCursorScreenLocation();

protected:

	virtual void DrawHUD() override;
};
