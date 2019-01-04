// Copyright 2018, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ROSBridgeHandler.h"
#include "RVEdTool.generated.h"

/**
 *
 */
UCLASS()
class URVIZED_API URVEdTool : public UObject
{
	GENERATED_BODY()	

public:
	// Set parent mode
	void SetParent(class FRVEdMode* InParent);

private:
	// Create ROSBridge and connect to ROS
	UFUNCTION(Exec, Category = "ROS")
	void Connect();

	// Disconnect from ROS
	UFUNCTION(Exec, Category = "ROS")
	void Disconnect();

	// Callback on connection
	void ConnectedCb();

	// Callback when disconnected
	void ErrorCb();

private:
	// ROS master ip
	UPROPERTY(EditAnywhere, Category = "ROS", meta = (editcondition = "bCanEdit"))
	FString ServerAdress = TEXT("127.0.0.1");

	// ROS bridge connection port
	UPROPERTY(EditAnywhere, Category = "ROS", meta = (editcondition = "bCanEdit"))
	uint32 ServerPort = 9090;

	// Namespace under which the callbacks are registered
	UPROPERTY(EditAnywhere, Category = "ROS", meta = (editcondition = "bCanEdit"))
	FString Namespace = TEXT("unreal");

	// ROS connection status
	UPROPERTY(VisibleInstanceOnly, Category = "ROS")
	FString ConnectionStatus = TEXT("null");

	// ROS Bridge Handler
	TSharedPtr<FROSBridgeHandler> ROSBridgeHandler;
};
