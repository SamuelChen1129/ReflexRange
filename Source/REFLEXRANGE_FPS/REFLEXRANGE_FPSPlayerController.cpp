// Copyright Epic Games, Inc. All Rights Reserved.


#include "REFLEXRANGE_FPSPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "REFLEXRANGE_FPSCameraManager.h"
#include "Blueprint/UserWidget.h"
#include "REFLEXRANGE_FPS.h"
#include "Widgets/Input/SVirtualJoystick.h"

AREFLEXRANGE_FPSPlayerController::AREFLEXRANGE_FPSPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = AREFLEXRANGE_FPSCameraManager::StaticClass();
}

void AREFLEXRANGE_FPSPlayerController::BeginPlay()
{
	Super::BeginPlay();

	
	// only spawn touch controls on local player controllers
	if (SVirtualJoystick::ShouldDisplayTouchInterface() && IsLocalPlayerController())
	{
		// spawn the mobile controls widget
		MobileControlsWidget = CreateWidget<UUserWidget>(this, MobileControlsWidgetClass);

		if (MobileControlsWidget)
		{
			// add the controls to the player screen
			MobileControlsWidget->AddToPlayerScreen(0);

		} else {

			UE_LOG(LogREFLEXRANGE_FPS, Error, TEXT("Could not spawn mobile controls widget."));

		}

	}
}

void AREFLEXRANGE_FPSPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		// Add Input Mapping Context
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}

			// only add these IMCs if we're not using mobile touch input
			if (!SVirtualJoystick::ShouldDisplayTouchInterface())
			{
				for (UInputMappingContext* CurrentContext : MobileExcludedMappingContexts)
				{
					Subsystem->AddMappingContext(CurrentContext, 0);
				}
			}
		}
	}
	
}
