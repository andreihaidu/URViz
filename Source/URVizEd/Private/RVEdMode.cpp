// Copyright 2018, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

#include "RVEdMode.h"
#include "RVEdModeToolkit.h"
#include "Toolkits/ToolkitManager.h"
#include "EditorModeManager.h"

const FEditorModeID FRVEdMode::EM_RVEdModeId = TEXT("EM_RVEdMode");

FRVEdMode::FRVEdMode()
{

}

FRVEdMode::~FRVEdMode()
{

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




