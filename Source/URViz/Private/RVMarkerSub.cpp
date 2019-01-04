// Copyright 2018, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

#include "RVMarkerSub.h"
#include "std_msgs/String.h"
#include "visualization_msgs/Marker.h"
#include "visualization_msgs/MarkerArray.h"

// Ctor
//FRVMarkerSub::FRVMarkerSub(UWorld* InWorld) : FROSBridgeSubscriber(TEXT("ros_string"), TEXT("std_msgs/String")), World(InWorld)
//{
//	UE_LOG(LogTemp, Warning, TEXT("%s::%d"), TEXT(__FUNCTION__), __LINE__);
//}
FRVMarkerSub::FRVMarkerSub(UWorld* InWorld) : FROSBridgeSubscriber(TEXT("visualization_marker"), TEXT("visualization_msgs/Marker")), World(InWorld)
{
	UE_LOG(LogTemp, Warning, TEXT("%s::%d"), TEXT(__FUNCTION__), __LINE__);
}

// Dtor
FRVMarkerSub::~FRVMarkerSub()
{
}

// Parse the incoming message
TSharedPtr<FROSBridgeMsg> FRVMarkerSub::ParseMessage(TSharedPtr<FJsonObject> JsonObject) const
{
	UE_LOG(LogTemp, Warning, TEXT("%s::%d"), TEXT(__FUNCTION__), __LINE__);
//	TSharedPtr<std_msgs::String> StringMessage = MakeShareable<std_msgs::String>(
//		new std_msgs::String());
//
//	StringMessage->FromJson(JsonObject);
//
//	return StaticCastSharedPtr<FROSBridgeMsg>(StringMessage);

	TSharedPtr<visualization_msgs::Marker> MarkerMsg = MakeShareable<visualization_msgs::Marker>(
		new visualization_msgs::Marker());

	MarkerMsg->FromJson(JsonObject);

	return StaticCastSharedPtr<FROSBridgeMsg>(MarkerMsg);
}

void FRVMarkerSub::Callback(TSharedPtr<FROSBridgeMsg> Msg)
{
	// Downcast to subclass using StaticCastSharedPtr function
	//TSharedPtr<std_msgs::String> StringMessage = StaticCastSharedPtr<std_msgs::String>(Msg);

	//UE_LOG(LogTemp, Error, TEXT("%s::%d World name=%s Msg=%s"),
	//	TEXT(__FUNCTION__), __LINE__, *World->GetName(), *StringMessage->GetData());

	UE_LOG(LogTemp, Error, TEXT("%s::%d World name=%s "),
		TEXT(__FUNCTION__), __LINE__, *World->GetName());
}
