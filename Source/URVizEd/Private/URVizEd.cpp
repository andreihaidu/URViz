// Copyright 2018, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

#include "URVizEd.h"
#include "RVEdMode.h"
#include "RVEdStyle.h"

// Define logging types
DEFINE_LOG_CATEGORY(LogRVEd);

#define LOCTEXT_NAMESPACE "FURVizEd"

void FURVizEd::StartupModule()
{
	// Register slate style overrides
	FRVEdStyle::Initialize();
	FRVEdStyle::ReloadTextures();

	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FEditorModeRegistry::Get().RegisterMode<FRVEdMode>(
		FRVEdMode::EM_RVEdModeId,
		LOCTEXT("RVizEdModeName", "RViz"),
		FSlateIcon("LevelEditor.RVizEd", "LevelEditor.RVizEd.Small"),
		true);
}

void FURVizEd::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FEditorModeRegistry::Get().UnregisterMode(FRVEdMode::EM_RVEdModeId);
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FURVizEd, URViz)