

#pragma once

#include "GameFramework/HUD.h"
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
	
	FVector2D screenCentre;
	

protected:

	virtual void DrawHUD() override;
};
