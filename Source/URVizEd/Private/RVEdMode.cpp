// Copyright 2018, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

#include "RVEdMode.h"
#include "RVEdModeToolkit.h"
#include "Toolkits/ToolkitManager.h"
#include "EditorModeManager.h"

const FEditorModeID FRVEdMode::EM_RVEdModeId = TEXT("EM_RVEdMode");

// Ctor
FRVEdMode::FRVEdMode()
{
	UISettings = NewObject<URVEdTool>(GetTransientPackage(), TEXT("NewUISettings"), RF_Transactional);
	UISettings->SetParent(this);
}

// Dtor
FRVEdMode::~FRVEdMode()
{

}

void FRVEdMode::AddReferencedObjects(FReferenceCollector& Collector)
{
	// Call parent implementation
	FEdMode::AddReferencedObjects(Collector);

	Collector.AddReferencedObject(UISettings);
}

void FRVEdMode::Enter()
{
	FEdMode::Enter();

	if (!Toolkit.IsValid() && UsesToolkits())
	{
		Toolkit = MakeShareable(new FRVEdModeToolkit);
		Toolkit->Init(Owner->GetToolkitHost());
	}
}

void FRVEdMode::Exit()
{
	if (Toolkit.IsValid())
	{
		FToolkitManager::Get().CloseToolkit(Toolkit.ToSharedRef());
		Toolkit.Reset();
	}

	// Call base Exit method to ensure proper cleanup
	FEdMode::Exit();
}

bool FRVEdMode::UsesToolkits() const
{
	return true;
}




