// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.IO;

public class GameLiftClientSDK : ModuleRules
{
    public GameLiftClientSDK(ReadOnlyTargetRules Target) : base(Target)
    {


        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "Projects",
				// ... add other public dependencies that you statically link with here ...
			}
            );


        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
				// ... add private dependencies that you statically link with here ...	
			}
            );


        DynamicallyLoadedModuleNames.AddRange(
            new string[]
            {
				// ... add any modules that your module loads dynamically here ...
			}
            );


        bEnableExceptions = true;
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));

        PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private"));

        string BaseDirectory = Path.GetFullPath(Path.Combine(ModuleDirectory, "..", ".."));
        string SDKDirectory = Path.Combine(BaseDirectory, "ThirdParty", "GameLiftClientSDK", Target.Platform.ToString());
        string BinariesDirectory = Path.Combine(BaseDirectory, "Binaries", Target.Platform.ToString());

        if (!Directory.Exists(BinariesDirectory))
        {
            Directory.CreateDirectory(BinariesDirectory);
        }

        bool bHasGameLiftSDK = Directory.Exists(SDKDirectory);

        if (bHasGameLiftSDK)
        {
            PublicDefinitions.Add("WITH_GAMELIFTCLIENTSDK=1");
            PublicLibraryPaths.Add(SDKDirectory);
            InitiateSDK(SDKDirectory, BinariesDirectory);
        }
        else
        {
            PublicDefinitions.Add("WITH_GAMELIFTCLIENTSDK=0");
        }
    }

    private bool InitiateSDK(string SDKDirectory, string BinariesDirectory)
    {
        // Initiate lib files
        string AWSCoreLibFile = Path.Combine(SDKDirectory, "aws-cpp-sdk-core.lib");
        string AWSCognitoIndentityLibFile = Path.Combine(SDKDirectory, "aws-cpp-sdk-cognito-identity.lib");
        string AWSGameliftLibFile = Path.Combine(SDKDirectory, "aws-cpp-sdk-gamelift.lib");
    
        if (File.Exists(AWSCoreLibFile))
        {
            PublicAdditionalLibraries.Add(AWSCoreLibFile);
        }
        else
        {
            throw new BuildException("aws-cpp-sdk-core.lib not found. Expected in this location: " + AWSCoreLibFile);
        }

        if (File.Exists(AWSCognitoIndentityLibFile))
        {
            PublicAdditionalLibraries.Add(AWSCognitoIndentityLibFile);
        }
        else
        {
            throw new BuildException("aws-cpp-sdk-cognito-identity.lib not found. Expected in this location: " + AWSCognitoIndentityLibFile);
        }

        if (File.Exists(AWSGameliftLibFile))
        {
            PublicAdditionalLibraries.Add(AWSGameliftLibFile);
        }
        else
        {
            throw new BuildException("aws-cpp-sdk-gamelift.lib not found. Expected in this location: " + AWSGameliftLibFile);
        }


        // Initiate dll files
        string AWSCoreDLLFile = Path.Combine(SDKDirectory, "aws-cpp-sdk-core.dll");
        string AWSCognitoIndentityDLLFile = Path.Combine(SDKDirectory, "aws-cpp-sdk-cognito-identity.dll");
        string AWSGameliftDLLFile = Path.Combine(SDKDirectory, "aws-cpp-sdk-gamelift.dll");

        if (File.Exists(AWSCoreDLLFile))
        {
            PublicDelayLoadDLLs.Add("aws-cpp-sdk-core.dll");
            RuntimeDependencies.Add(AWSCoreDLLFile);
        }
        else
        {
            throw new BuildException("aws-cpp-sdk-core.dll not found. Expected in this location: " + AWSCoreDLLFile);
        }

        if (File.Exists(AWSCognitoIndentityDLLFile))
        {
            PublicDelayLoadDLLs.Add("aws-cpp-sdk-cognito-identity.dll");
            RuntimeDependencies.Add(AWSCognitoIndentityDLLFile);
        }
        else
        {
            throw new BuildException("aws-cpp-sdk-cognito-identity.dll not found. Expected in this location: " + AWSCognitoIndentityDLLFile);
        }

        if (File.Exists(AWSGameliftDLLFile))
        {
            PublicDelayLoadDLLs.Add("aws-cpp-sdk-gamelift.dll");
            RuntimeDependencies.Add(AWSGameliftDLLFile);
        }
        else
        {
            throw new BuildException("aws-cpp-sdk-gamelift.dll not found. Expected in this location: " + AWSGameliftDLLFile);
        }

        // Copy all dll files to binaries
        string[] files = Directory.GetFiles(SDKDirectory);

        for(int i = 0; i != files.Length; ++i)
        {
            string f = files[i];
            if (Path.GetExtension(f).ToLower().Equals(".dll"))
            {
                string BinPath = Path.Combine(BinariesDirectory, Path.GetFileName(f));
                if(!File.Exists(BinPath))
                {
                    File.Copy(f, BinPath);
                }
            }
        }

        return true;
    }
}
