// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UTHUB_Tarea1 : ModuleRules
{
	public UTHUB_Tarea1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
