

#include "OCineasta.h"
#include "OCCameraBox.h"


AOCCameraBox::AOCCameraBox(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	TScriptDelegate<FWeakObjectPtr> beginOvDelegate;
	TScriptDelegate<FWeakObjectPtr> endOvDelegate;

	beginOvDelegate.BindUFunction(this, FName(TEXT("BeginOverlap")));
	endOvDelegate.BindUFunction(this, FName(TEXT("EndOverlap")));
	
	cameraLimits = PCIP.CreateDefaultSubobject<UBoxComponent>(this, "CameraLimits");
	cameraLimits->OnComponentBeginOverlap.Add(beginOvDelegate);
	cameraLimits->OnComponentEndOverlap.Add(endOvDelegate);

	RootComponent = cameraLimits;
}

void AOCCameraBox::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AOCCameraBox::BeginOverlap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("BeginOverlap!"));
	}
}

void AOCCameraBox::EndOverlap(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("EndOverlap!"));
	}
}
