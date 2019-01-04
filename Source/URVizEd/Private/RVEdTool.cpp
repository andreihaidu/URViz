// Copyright 2018, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

#include "RVEdTool.h"
#include "RVEdMode.h"
#include "RVMarkerSub.h"

// Create ROSBridge and connect to ROS
void URVEdTool::Connect()
{
	UE_LOG(LogTemp, Warning, TEXT("%s::%d"), TEXT(__FUNCTION__), __LINE__);
	if (!ROSBridgeHandler.IsValid())
	{
		ROSBridgeHandler = MakeShareable<FROSBridgeHandler>(new FROSBridgeHandler(ServerAdress, ServerPort));
	}

	if (GEditor && GEditor->GetEditorWorldContext().World())
	{
		// Register to topics
		ROSBridgeHandler->AddSubscriber(MakeShareable<FRVMarkerSub>(new FRVMarkerSub(
			GEditor->GetEditorWorldContext().World())));
	}

	ROSBridgeHandler->AddConnectedCallback(this, &URVEdTool::ConnectedCb);
	ROSBridgeHandler->AddErrorCallback(this, &URVEdTool::ErrorCb);

	if (!ROSBridgeHandler->IsConnected())
	{
		ROSBridgeHandler->SetHost(ServerAdress);
		ROSBridgeHandler->SetPort(ServerPort);
		ROSBridgeHandler->Connect();
	}	
}

// Disconnect from ROS
void URVEdTool::Disconnect()
{
	UE_LOG(LogTemp, Warning, TEXT("%s::%d"), TEXT(__FUNCTION__), __LINE__);
	ROSBridgeHandler->Disconnect();
	ConnectionStatus = TEXT("Disconnected");
}

// Callback on connection
void URVEdTool::ConnectedCb()
{
	ConnectionStatus = TEXT("Connected");
	UE_LOG(LogTemp, Warning, TEXT("%s::%d"), TEXT(__FUNCTION__), __LINE__);
}

// Callback when disconnected
void URVEdTool::ErrorCb()
{
	ConnectionStatus = TEXT("Error");
	UE_LOG(LogTemp, Error, TEXT("%s::%d"), TEXT(__FUNCTION__), __LINE__);
}