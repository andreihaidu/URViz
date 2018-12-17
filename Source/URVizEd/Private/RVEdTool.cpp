// Copyright 2018, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

#include "RVedTool.h"

// Ctor
URVEdTool::URVEdTool()
{
}

// Set parent mode
void SetParent(FRVEdMode* InParent)
{
	ParentMode = InParent;
}

// Callback on connection
void URVEdTool::ConnectedCb()
{
	UE_LOG(LogTemp, Warning, TEXT("%s::%d"), TEXT(__FUNCTION__), __LINE__);
}

// Callback when disconnected
void URVEdTool::DisconnectedCb()
{
	UE_LOG(LogTemp, Error, TEXT("%s::%d"), TEXT(__FUNCTION__), __LINE__);
}