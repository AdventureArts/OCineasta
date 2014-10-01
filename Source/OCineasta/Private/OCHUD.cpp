

#include "OCineasta.h"
#include "OCHUD.h"


AOCHUD::AOCHUD(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// ====================
	// Configuração de cursor temporário para o protótipo da versão a0.1.
	// ====================

	cursorTexture = ConstructorHelpers::FObjectFinder<UTexture>(TEXT("/Engine/EditorMaterials/TargetIcon.TargetIcon")).Object;

	float cursorWidth = cursorTexture->GetSurfaceWidth();
	float cursorHeight = cursorTexture->GetSurfaceHeight();

	cursorSize = FVector2D(cursorWidth, cursorHeight) / 4.f;
	cursorCentre = cursorSize / 2.f;
	cursorLocation = FVector2D(0.f, 0.f);

	// ====================
	// Fim de configuração de cursor.
	// ====================
}

void AOCHUD::DrawHUD()
{
	Super::DrawHUD();

	// Atualiza a coordenada que representa o centro da tela.
	screenCentre = FVector2D(Canvas->ClipX, Canvas->ClipY) / 2.f;

	AOCPlayerController *PC = StaticCast<AOCPlayerController*>(PlayerOwner);

	if (PC)
	{
		cursorLocation = PC->GetMouseLocation();
		cursorLocation += screenCentre;
		cursorLocation -= cursorCentre;
	}

	if (cursorTexture) // Existe a textura de cursor para ser impressa na tela?
	{
		Canvas->K2_DrawTexture(cursorTexture, cursorLocation, cursorSize, FVector2D(0.f, 0.f));
	}
}

FVector2D AOCHUD::getCursorScreenLocation()
{
	return cursorLocation + screenCentre;
}