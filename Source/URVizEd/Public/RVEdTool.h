// Copyright 2018, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "RVEdMode.h"
#include "RVEdTool.generated.h"

UCLASS()
class URVEdTool : public UObject
{
	GENERATED_UCLASS_BODY()	

public:
	// Ctor
	URVEdTool();

	// Set parent mode
	void SetParent(FRVEdMode* InParent);

private:
	// Callback on connection
	void ConnectedCb();

	// Callback when disconnected
	void DisconnectedCb();

private:
	UPROPERTY(EditAnywhere, Category = "ROS")
	FString ServerAdress = TEXT("127.0.0.1");

	UPROPERTY(EditAnywhere, Category = "ROS", meta = (DisplayName = "ROS"))
	uint32 ServerPort = 9090;

	UPROPERTY(EditAnywhere, Category = "ROS")
	FString Namespace = TEXT("unreal");

	UPROPERTY(VisibleInstanceOnly, Category = "ROS")
	FString ConnectionStatus = TEXT("Not connected.");

	// Pointer to parent mode
	FRVEdMode* ParentMode;
};
