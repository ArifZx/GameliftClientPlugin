// Fill out your copyright notice in the Description page of Project Settings.


#include "GameLiftClientObject.h"
#if WITH_GAMELIFTCLIENTSDK
#include "GameLiftClientGlobals.h"
#include "GameLiftClientTypes.h"
#include "GameLiftClientApi.h"
#include "aws/core/client/ClientConfiguration.h"
#include "aws/core/auth/AWSCredentials.h"
#include "aws/gamelift/GameLiftClient.h"
#endif

void UGameLiftClientObject::Internal_InitGameLiftClientSDK(const FString& AccessKey, const FString& Secret, const FString& Region, bool bUsingGameLiftLocal, int32 LocalPort)
{
#if WITH_GAMELIFTCLIENTSDK
	Aws::Client::ClientConfiguration ClientConfig;
	Aws::Auth::AWSCredentials Credentials;

	ClientConfig.connectTimeoutMs = 10000;
	ClientConfig.requestTimeoutMs = 10000;
	ClientConfig.region = TCHAR_TO_UTF8(*Region);

	bIsUsingGameLiftLocal = bUsingGameLiftLocal;

	if (bIsUsingGameLiftLocal)
	{
		ClientConfig.scheme = Aws::Http::Scheme::HTTP;
		const FString HostAddress = FString::Printf(TEXT("localhost:%i"), LocalPort);
		ClientConfig.endpointOverride = TCHAR_TO_UTF8(*HostAddress);
		LOG_WARNING(FString::Printf(TEXT("GameLift is currently configured to use GameLift Local at port %i."), LocalPort));
	}

	Credentials = Aws::Auth::AWSCredentials(TCHAR_TO_UTF8(*AccessKey), TCHAR_TO_UTF8(*Secret));
	GameLiftClient = new Aws::GameLift::GameLiftClient(Credentials, ClientConfig);
#endif
}

UGameLiftClientObject * UGameLiftClientObject::CreateGameLiftObject(const FString & AccessKey, const FString & Secret, const FString & Region, bool bUsingGameLiftLocal, int32 LocalPort)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftClientObject* Proxy = NewObject<UGameLiftClientObject>();
	Proxy->Internal_InitGameLiftClientSDK(AccessKey, Secret, Region, bUsingGameLiftLocal, LocalPort);
	return Proxy;
#endif
	return nullptr;
}

UGameLiftCreateGameSession * UGameLiftClientObject::CreateGameSession(FGameLiftGameSessionConfig GameSessionProperties)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftCreateGameSession* Proxy = UGameLiftCreateGameSession::CreateGameSession(GameSessionProperties, bIsUsingGameLiftLocal);
	Proxy->GameLiftClient = GameLiftClient;
	return Proxy;
#endif
	return nullptr;
}

UGameLiftDescribeGameSession * UGameLiftClientObject::DescribeGameSession(FString GameSessionID)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftDescribeGameSession* Proxy = UGameLiftDescribeGameSession::DescribeGameSession(GameSessionID);
	Proxy->GameLiftClient = GameLiftClient;
	return Proxy;
#endif
	return nullptr;
}

UGameLiftCreatePlayerSession * UGameLiftClientObject::CreatePlayerSession(FString GameSessionID, FString UniquePlayerID)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftCreatePlayerSession* Proxy = UGameLiftCreatePlayerSession::CreatePlayerSession(GameSessionID, UniquePlayerID);
	Proxy->GameLiftClient = GameLiftClient;
	return Proxy;
#endif
	return nullptr;
}

UGameLiftDescribeGameSessionQueues * UGameLiftClientObject::DescribeGameSessionQueues(FString QueueName)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftDescribeGameSessionQueues* Proxy = UGameLiftDescribeGameSessionQueues::DescribeGameSessionQueues(QueueName);
	Proxy->GameLiftClient = GameLiftClient;
	return Proxy;
#endif
	return nullptr;
}

UGameLiftSearchGameSessions * UGameLiftClientObject::SearchGameSessions(FString FleetId, FString AliasId, FString FilterExpression, FString SortExpression)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftSearchGameSessions* Proxy = UGameLiftSearchGameSessions::SearchGameSessions(FleetId, AliasId, FilterExpression, SortExpression);
	Proxy->GameLiftClient = GameLiftClient;
	return Proxy;
#endif
	return nullptr;
}

UGameLiftStartGameSessionPlacement * UGameLiftClientObject::StartGameSessionPlacement(FString QueueName, int MaxPlayerCount, FString PlacementId)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftStartGameSessionPlacement* Proxy = UGameLiftStartGameSessionPlacement::StartGameSessionPlacement(QueueName, MaxPlayerCount, PlacementId);
	Proxy->GameLiftClient = GameLiftClient;
	return Proxy;
#endif
	return nullptr;
}

UGameLiftDescribeGameSessionPlacement * UGameLiftClientObject::DescribeGameSessionPlacement(FString GameSessionPlacementId)
{
#if WITH_GAMELIFTCLIENTSDK
	UGameLiftDescribeGameSessionPlacement* Proxy = UGameLiftDescribeGameSessionPlacement::DescribeGameSessionPlacement(GameSessionPlacementId);
	Proxy->GameLiftClient = GameLiftClient;
	return Proxy;
#endif
	return nullptr;
}

