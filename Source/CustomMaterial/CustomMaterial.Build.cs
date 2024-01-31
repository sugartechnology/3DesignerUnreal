// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CustomMaterial : ModuleRules
{
	public CustomMaterial(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		//PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

        PublicDependencyModuleNames.AddRange(new string[] {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
            "DatasmithGLTFTranslator",
            "GLTFCore" ,
            "DatasmithTranslator" ,
            "ImageWrapper",
            "MeshDescription",
            "StaticMeshDescription",
            "ProceduralMeshComponent",
            "Json",
            "JsonUtilities",
            "HTTP",
            "SevenZipForUnreal",
        });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
