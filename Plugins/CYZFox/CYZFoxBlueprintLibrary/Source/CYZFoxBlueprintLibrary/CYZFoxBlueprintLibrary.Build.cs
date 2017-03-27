/*
 * F.O.X UnrealEngine SDK
 * Copyright © 2017 CyberZ, Inc. All Rights Reserved.
 */
namespace UnrealBuildTool.Rules
{
	public class CYZFoxBlueprintLibrary : ModuleRules
	{
        public CYZFoxBlueprintLibrary(TargetInfo Target)
		{
			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
          "Engine",
				}
				);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"CYZFox",
				}
			);

      PublicIncludePathModuleNames.Add("CYZFox");
    }
	}
}
