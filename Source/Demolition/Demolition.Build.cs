// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Demolition : ModuleRules
{
	public Demolition(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] 
		{ 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput", 
			"AIModule",  
			"GameplayTasks",
			"NavigationSystem"
		});
	}
}
