// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class REFLEXRANGE_FPS : ModuleRules
{
	public REFLEXRANGE_FPS(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"REFLEXRANGE_FPS",
			"REFLEXRANGE_FPS/Variant_Horror",
			"REFLEXRANGE_FPS/Variant_Horror/UI",
			"REFLEXRANGE_FPS/Variant_Shooter",
			"REFLEXRANGE_FPS/Variant_Shooter/AI",
			"REFLEXRANGE_FPS/Variant_Shooter/UI",
			"REFLEXRANGE_FPS/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
