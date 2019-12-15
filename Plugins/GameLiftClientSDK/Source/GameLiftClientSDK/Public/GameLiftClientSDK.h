// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "aws/core/Aws.h"
#include "Modules/ModuleManager.h"

class FGameLiftClientSDKModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	/** AWS Options */
	Aws::SDKOptions options;
	/** Handle to the dll we will load */
	static void* GameLiftHandle;
	static void* CognitoIdentityHandle;
	static void * AWSCoreHandle;
	static bool LoadDependency(const FString& Dir, const FString& Name, void*& Handle);
	static void FreeDependency(void*& Handle);
};
