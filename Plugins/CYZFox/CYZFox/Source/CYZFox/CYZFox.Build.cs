/*
 * F.O.X UnrealEngine SDK
 * Copyright © 2017 CyberZ, Inc. All Rights Reserved.
 */
using UnrealBuildTool;
using System.IO;

public class CYZFox : ModuleRules
{
	public CYZFox(TargetInfo Target)
	{

		PublicIncludePaths.AddRange(
			new string[] {
				"CYZFox/Public"
			}
		);


		PrivateIncludePaths.AddRange(
			new string[] {
				"CYZFox/Private",
				"CYZFox/Private/Android",
				"CYZFox/Private/IOS",
			}
		);


		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"Json",
			}
		);

		if (Target.Platform == UnrealTargetPlatform.Android)
		{
			PrivateDependencyModuleNames.Add("Launch");
			string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, BuildConfiguration.RelativeEnginePath);
			AdditionalPropertiesForReceipt.Add(
				new ReceiptProperty("AndroidPlugin", Path.Combine(PluginPath, "CYZFox_APL.xml"))
			);
		}
		else if (Target.Platform == UnrealTargetPlatform.IOS)
		{
			// Add the TapJoy framework
			PublicAdditionalFrameworks.Add(
				new UEBuildFramework(
					"CYZFox",														// Framework name
					"../../ThirdPartyLibraries/IOS/CYZFox.embeddedframework.zip"	// Zip name
				)
			);

			PublicFrameworks.AddRange(new string[] {
				// "UIKit",
				"Foundation",
				"Security",
				"StoreKit",
				"AdSupport",
				"WebKit",
				"SystemConfiguration"
				});
		}
	}
}
