// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GameLiftClientSDK.h"
#include "GameLiftClientGlobals.h"
#include "Core.h"
#include "aws/core/Aws.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"

#define LOCTEXT_NAMESPACE "FGameLiftClientSDKModule"

void* FGameLiftClientSDKModule::AWSCoreHandle = nullptr;
void* FGameLiftClientSDKModule::CognitoIdentityHandle = nullptr;
void* FGameLiftClientSDKModule::GameLiftHandle = nullptr;

void FGameLiftClientSDKModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
#if PLATFORM_WINDOWS && PLATFORM_64BITS

	const FString BaseDir = IPluginManager::Get().FindPlugin("GameLiftClientSDK")->GetBaseDir();
	LOG_NORMAL(FString::Printf(TEXT("Base directory is %s"), *BaseDir));

	const FString ThirdPartyDir = FPaths::Combine(*BaseDir, TEXT("ThirdParty"), TEXT("GameLiftClientSDK"), TEXT("Win64"));
	LOG_NORMAL(FString::Printf(TEXT("ThirdParty directory is %s"), *ThirdPartyDir));

	FString CoreLibName = "aws-cpp-sdk-core";
	FString CognitoIdentityLibName = "aws-cpp-sdk-cognito-identity";
	FString GameLiftLibName = "aws-cpp-sdk-gamelift";

	LOG_NORMAL("Starting AWSCore Module...");
	if (!LoadDependency(ThirdPartyDir, CoreLibName, AWSCoreHandle))
	{
		FFormatNamedArguments Arguments;
		Arguments.Add(TEXT("Name"), FText::FromString(CoreLibName));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}. Plugin will not be functional"), Arguments));
		FreeDependency(AWSCoreHandle);
		return;
	}

	LOG_NORMAL("Starting CognitoIdentity Module...");
	if (!LoadDependency(ThirdPartyDir, CognitoIdentityLibName, CognitoIdentityHandle))
	{
		FFormatNamedArguments Arguments;
		Arguments.Add(TEXT("Name"), FText::FromString(CognitoIdentityLibName));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}. Plugin will not be functional"), Arguments));
		FreeDependency(CognitoIdentityHandle);
		return;
	}

	LOG_NORMAL("Starting GameLift Module...");
	if (!LoadDependency(ThirdPartyDir, GameLiftLibName, GameLiftHandle))
	{
		FFormatNamedArguments Arguments;
		Arguments.Add(TEXT("Name"), FText::FromString(GameLiftLibName));
		FMessageDialog::Open(EAppMsgType::Ok, FText::Format(LOCTEXT("LoadDependencyError", "Failed to load {Name}. Plugin will not be functional"), Arguments));
		FreeDependency(GameLiftHandle);
		return;
	}

	Aws::InitAPI(options);
	LOG_NORMAL("Aws::InitAPI called.");
#endif
}

void FGameLiftClientSDKModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FreeDependency(AWSCoreHandle);
	FreeDependency(CognitoIdentityHandle);
	FreeDependency(GameLiftHandle);

	LOG_NORMAL("Shutting down GameLift Module...");
}

bool FGameLiftClientSDKModule::LoadDependency(const FString & Dir, const FString & Name, void *& Handle)
{
	FString Lib = Name + TEXT(".") + FPlatformProcess::GetModuleExtension();
	FString Path = Dir.IsEmpty() ? *Lib : FPaths::Combine(*Dir, *Lib);

	Handle = FPlatformProcess::GetDllHandle(*Path);

	if (Handle == nullptr)
	{
		LOG_ERROR(FString::Printf(TEXT("Dependency %s failed to load in directory %s"), *Lib, *Dir));
		return false;
	}

	LOG_NORMAL(FString::Printf(TEXT("Dependency %s successfully loaded from directory %s"), *Lib, *Dir));

	return true;
}

void FGameLiftClientSDKModule::FreeDependency(void *& Handle)
{
#if !PLATFORM_LINUX
	if (Handle != nullptr)
	{
		FPlatformProcess::FreeDllHandle(Handle);
		Handle = nullptr;
	}
#endif
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FGameLiftClientSDKModule, GameLiftClientSDK)