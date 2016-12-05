// Some copyright should be here...

using UnrealBuildTool;
using System.IO;

public class CYZFox : ModuleRules
{
	public CYZFox(TargetInfo Target)
	{

		PublicIncludePaths.AddRange(
			new string[] {
				"CYZFox/Public"

				// ... add public include paths required here ...
			}
			);


		PrivateIncludePaths.AddRange(
			new string[] {
				"CYZFox/Private",
				"CYZFox/Private/Android",
				"CYZFox/Private/IOS",
				// ... add other private include paths required here ...
			}
			);


		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"Engine",
				"Json",
				// ... add other public dependencies that you statically link with here ...
			}
			);


		// PrivateDependencyModuleNames.AddRange(
		// 	new string[]
		// 	{
		// 		"Core",
		// 		"CoreUObject",
		// 		"Engine",
		// 		"Json",
		//
		// 		// ... add private dependencies that you statically link with here ...
		// 	}
		// );

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
				"SystemConfiguration"
				});
		}
	}
}
