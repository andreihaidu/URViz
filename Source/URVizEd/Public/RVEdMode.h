// Copyright 2018, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

#pragma once

#include "CoreMinimal.h"
#include "EdMode.h"

class FRVEdMode : public FEdMode
{
public:
	const static FEditorModeID EM_RVizEditorMode;
public:
	// Ctor
	FRVEdMode();

	// Dtor
	virtual ~FRVEdMode();

	/** FGCObject interface */
	void AddReferencedObjects(FReferenceCollector& Collector) override;

	// FEdMode interface
	virtual void Enter() override;
	virtual void Exit() override;
	//virtual void Tick(FEditorViewportClient* ViewportClient, float DeltaTime) override;
	//virtual void Render(const FSceneView* View, FViewport* Viewport, FPrimitiveDrawInterface* PDI) override;
	//virtual void ActorSelectionChangeNotify() override;
	bool UsesToolkits() const override;
	// End of FEdMode interface

public:
	// public so it can be accessed by the toolkit to refresh
	class URVEdTool* RVizEditorTool;
};
