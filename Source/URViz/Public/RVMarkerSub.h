// Copyright 2018, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

#pragma once

#include "CoreMinimal.h"
#include "ROSBridgeHandler.h"
#include "ROSBridgeSubscriber.h"

// RViz marker subscriber
class URVIZ_API FRVMarkerSub : public FROSBridgeSubscriber
{
public:
	// Ctor
	FRVMarkerSub(UWorld* IWorld);

	// Dtor
	~FRVMarkerSub() override;

	// Parse the incoming message
	TSharedPtr<FROSBridgeMsg> ParseMessage(TSharedPtr<FJsonObject> JsonObject) const override;

	// On message receive callback function
	void Callback(TSharedPtr<FROSBridgeMsg> Msg) override;

private:
	// Pointer to the world
	UWorld* World;
};
